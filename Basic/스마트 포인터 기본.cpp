/************
<주소>		: p480
**********
<해결방안>	:

라이브러리에 Smart Pointer가 있지만, 직접 구현해 봄

[ Smart Pointer란 ]
기본적으로 객체이며, Pointer 처럼 연산할 수 있고, ( *, -> )
무엇보다 자동으로 delete 해준다는 장점이 있음

[ 연산 ]
* : 현재 객체의 참조값 반환
->: 현재 객체의 주소값 반환

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int x, int y) : x(x), y(y) {
		cout << "Point 객체 생성" << endl;
	}
	~Point() {
		cout << "Point 객체 소멸" << endl;
	}
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator<<(ostream &os, Point &p) {
		os << '(' << p.x << ", " << p.y << ')';
		return os;
	}
};


/**
 *	@class	SmartPtr
 *	@brief	일반 포인터와의 차이점은, delete 연산이 자동으로 이뤄졌다는 것이다.
 *			그 외에는 일반 포인터와 똑같은 방식으로 접근, 조작할 수 있다.
 */
class SmartPtr {
private:
	Point *posptr;

public:
	SmartPtr(Point *ptr) : posptr(ptr) { }

	/**
	 *	스마트 포인터의 기본!
	 *	@return: 현재 객체의 참조값을 반환
	 */
	Point& operator*() const {
		return *posptr;
	}

	/**
	 *	스마트 포인터의 기본!
	 *	@return: 현재 객체의 주소값을 반환 
	 */
	Point* operator->() const {
		return posptr;
	}

	/**
	 *	SmartPtr 자체에서 동적 할당을 하지는 않지만,
	 *	전달되는 인자가 new에 의해 동적할당 된 주소 값이라는 가정이 포함됨
	 */
	~SmartPtr() {
		delete posptr;
	}
};

class Main {
public:
	static int main() {
		SmartPtr p1(new Point(1, 2));
		SmartPtr p2(new Point(3, 4));
		SmartPtr p3(new Point(5, 6));
		// 포인터처럼 * 연산 가능!
		cout << *p1 << endl;
		cout << *p2 << endl;
		cout << *p3 << endl;

		// 포인터처럼 -> 연산 가능!
		p1->set(10, 20);
		p2->set(30, 40);
		p3->set(50, 60);
		cout << *p1 << endl;
		cout << *p2 << endl;
		cout << *p3 << endl;

		return 0;
	}
};
