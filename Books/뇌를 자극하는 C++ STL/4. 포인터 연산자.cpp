/************
<주소>		: p44, 46
**********
<해결방안>	:

obj->member();
obj.operator->()->member();

-> 이
operator->()-> 로 바뀜!

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int _x, int _y) : x(_x), y(_y) { }
	void print() const {
		cout << '(' << x << ", " << y << ')' << endl;
	}
};

template <class T>
class SmartPtr {
private:
	T *ptr;

public:
	SmartPtr(T *p) : ptr(p) { }
	virtual ~SmartPtr() {
		delete ptr;
	}

	T& operator*() const {
		return *ptr;
	}

	T* operator->() const {
		return ptr;
	}
};

int main(void) {
	SmartPtr<Point> p1(new Point(1, 2));
	p1->print();
	(*p1).print();
}