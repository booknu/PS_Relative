/************
<주소>		: p486
**********
<해결방안>	:

함수처럼 동작하는 클래스를 Functor = Function Object 라고 한다.

이것은 Java의 Comparator 처럼 함수, 객체의 동작에 유연함을 제공할 때 사용된다.
Java에서는 comp.compareTo(a, b); 처럼 길게 사용해야 하지만,
C++에서는 comp(a, b); 처럼 짧게 사용이 가능하다!

여기서는 Comparator를 Abstract Class로 두고,
그것을 구현하여 여러가지 ~~~Comparator 클래스를 만들어, 이것을 Functor로 사용한다.

즉, 함수나 객체에 Functor 객체를 인자로 넘겨주어 Sort 방식을 유연하게 바꿀 수 있게 된다!

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

/**
 *	@class	Comparator: Abstract Class
 *	@brief	다형성을 위한 틀을 마련해주는 추상 클래스. (여러가지 Comparator 클래스를 이 클래스를 상속함으로써 구현 가능!)
 *			Abstract Class는 이것을 통해 객체 생성은 불가능하다.
 */
class Comparator {
public:
	// 순수 가상 함수 (이게 하나라도 있으면 Abstract Class)
	virtual int operator()(int n1, int n2) const = 0;
};

/**
 *	@class	AscendingComparator
 *	@brief	오름차순으로 비교해주는 Functor
 */
class AscendingComparator : public Comparator {
public:
	virtual int operator()(int n1, int n2) const {
		return n1 - n2;
	}
};

/**
 *	@class	DescendingComparator
 *	@brief	오름차순으로 비교해주는 Functor
 */
class DescendingComparator : public Comparator {
public:
	virtual int operator()(int n1, int n2) const {
		return n2 - n1;
	}
};

/**
 *	@class	Array
 *	@brief	Array 기능을 하는 객체.
 *			add, sort, print 기능이 있음
 *			sort에서는 Comparator을 인자로 받아 유동적으로 정렬 가능
 */
class Array {
private:
	int *arr;
	int idx;

public:
	const int length;

public:
	Array(int length) : idx(0), length(length) {
		arr = new int[length];
	}

	void add(int n) {
		if (idx >= length) {
			cout << "Exception: ArrayIndexOutOfBoundException: " << idx << endl;
			return;
		}
		arr[idx++] = n;
	}

	void printAll() {
		for (int i = 0; i < idx; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}

	/**
	 *	Bubble Sort
	 *	@param comp: Comparator
	 */
	void sort(const Comparator &comp) {
		bool sorted = false;
		for (int i = 0; i < (idx - 1); i++) {
			if (!sorted) {
				sorted = true;
				for (int j = 0; j < (idx - 1) - i; j++) {
					if (comp(arr[j], arr[j + 1]) < 0) {
						int tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
						sorted = false;
					}
				}
			} else {
				break;
			}
		}
	}

	~Array() {
		delete[] arr;
	}
};

class Main {
public:
	static int main() {
		Array arr(10);
		arr.add(10);
		arr.add(9);
		arr.add(8);
		arr.add(7);
		arr.add(6);
		arr.add(5);
		arr.add(4);
		arr.add(3);
		arr.add(2);
		arr.add(1);

		arr.sort(AscendingComparator());
		arr.printAll();

		arr.sort(DescendingComparator());
		arr.printAll();
		cout << endl;

		Array arr1(10);
		arr1.add(3);
		arr1.add(5);
		arr1.add(2);
		arr1.add(7);
		arr1.add(2);
		arr1.add(1);
		arr1.add(4);
		arr1.add(6);
		arr1.add(8);
		arr1.add(9);

		arr1.sort(AscendingComparator());
		arr1.printAll();

		arr1.sort(DescendingComparator());
		arr1.printAll();

		return 0;
	}
};
