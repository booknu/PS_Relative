/************
<�ּ�>		: p486
**********
<�ذ���>	:

�Լ�ó�� �����ϴ� Ŭ������ Functor = Function Object ��� �Ѵ�.

�̰��� Java�� Comparator ó�� �Լ�, ��ü�� ���ۿ� �������� ������ �� ���ȴ�.
Java������ comp.compareTo(a, b); ó�� ��� ����ؾ� ������,
C++������ comp(a, b); ó�� ª�� ����� �����ϴ�!

���⼭�� Comparator�� Abstract Class�� �ΰ�,
�װ��� �����Ͽ� �������� ~~~Comparator Ŭ������ �����, �̰��� Functor�� ����Ѵ�.

��, �Լ��� ��ü�� Functor ��ü�� ���ڷ� �Ѱ��־� Sort ����� �����ϰ� �ٲ� �� �ְ� �ȴ�!

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

/**
 *	@class	Comparator: Abstract Class
 *	@brief	�������� ���� Ʋ�� �������ִ� �߻� Ŭ����. (�������� Comparator Ŭ������ �� Ŭ������ ��������ν� ���� ����!)
 *			Abstract Class�� �̰��� ���� ��ü ������ �Ұ����ϴ�.
 */
class Comparator {
public:
	// ���� ���� �Լ� (�̰� �ϳ��� ������ Abstract Class)
	virtual int operator()(int n1, int n2) const = 0;
};

/**
 *	@class	AscendingComparator
 *	@brief	������������ �����ִ� Functor
 */
class AscendingComparator : public Comparator {
public:
	virtual int operator()(int n1, int n2) const {
		return n1 - n2;
	}
};

/**
 *	@class	DescendingComparator
 *	@brief	������������ �����ִ� Functor
 */
class DescendingComparator : public Comparator {
public:
	virtual int operator()(int n1, int n2) const {
		return n2 - n1;
	}
};

/**
 *	@class	Array
 *	@brief	Array ����� �ϴ� ��ü.
 *			add, sort, print ����� ����
 *			sort������ Comparator�� ���ڷ� �޾� ���������� ���� ����
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
