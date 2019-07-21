/************
<주소>		: p535 - 문제 1
**********
<해결방안>	:

포인터로 Swap, 참조자로 Swap 하는 방법에 대한 비교

밑의 방식으로 포인터 Swap해도 되는지?
ex)
class Obj
	void memberSwap(Obj &other)
		swap(&(this->member), &(other.member));

이러면?

**********
<오답노트>	:

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Point {
private:
	int x, y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	Point(Point &copy) : x(copy.x), y(copy.y) { cout << "copy const" << endl; }
	Point& operator=(Point& copy) {
		cout << "operator= " << endl;
		x = copy.x;
		y = copy.y;
		return *this;
	}
	void print() const {
		cout << '(' << x << ", " << y << ')' << endl;
	}
};

class Main {
public:
	/**
	* 참조자를 이용해 swap (a에 b를 복사, b에 a를 복사하는 방법)
	* 이 경우에는 복사 생성자, 대입 연산자 호출되서 비효율적!
	*
	* @param a, b: 바꿀 객체의 참조자형
	*/
	template <class T>
	static void swap(T &a, T &b) {
		T temp = a; // 복사 생성자
		a = b;		// 대입 연산자
		b = temp;	// 대입 연산자
	}

	/**
	* 포인터를 이용해 swap (서로 가리키는 곳만 바꿈)
	* 이 경우에는 복사 생성자, 대입 연산자 호출 안 됨!
	*
	* @param a, b: 바꿀 객체의 포인터형
	*/
	template <class T>
	static void swap(T *a, T *b) {
		T *temp = a;
		a = b;
		b = temp;

		// 원본
		//	T temp = *a;
		//	*a = *b;
		//	*b = temp;
	}

	static int main() {
		Point p1(10, 20);
		Point p2(-100, -200);
		swap(p1, p2);

		p1.print();
		p2.print();

		swap(&p1, &p2);

		p1.print();
		p2.print();

		return 0;
	}
};

