/************
<주소>		: p552 - 문제
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

/**
 *	@class	SmartPtr<T>
 *
 *	@brief	포인터 기능을 하는 클래스
 *			template를 통해 다양한 자료형에 적용이 가능하다.
 *			객체 소멸 시 자동 delete를 해주기 때문에 일일이 delete 할 필요가 없다.
 *
 *	@remark	new로 할당된 메모리를 가리키는 포인터로 생성자를 호출해야 함
 */
template <class T>
class SmartPtr {
private:
	T *ptr;

public:
	SmartPtr(T *ptr);
	T& operator*();
	T* operator->();
	~SmartPtr();
};

template <class T>
SmartPtr<T>::SmartPtr(T *ptr) : ptr(ptr) { }

template <class T>
T& SmartPtr<T>::operator*() {
	return *ptr;
}

template <class T>
T* SmartPtr<T>::operator->() {
	return ptr;
}

template <class T>
SmartPtr<T>::~SmartPtr() {
	delete ptr;
}
////////

class Point {
private:
	int x, y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << '(' << x << ", " << y << ')' << endl;
	}
};

class Main {
public:
	static int main() {
		SmartPtr<Point> p1(new Point(1, 2));
		SmartPtr<Point> p2(new Point(3, 4));
		p1->print();
		p2->print();

		p1->setPos(-1, -2);
		p2->setPos(-3, -4);
		p1->print();
		p2->print();

		SmartPtr<int> ip1(new int);
		SmartPtr<int> ip2(new int);

		*ip1 = 3;
		*ip2 = 4;

		cout << *ip1 << ", " << ip1.operator->() << endl;
		cout << *ip2 << ", " << ip2.operator->() << endl;

		return 0;
	}
};
