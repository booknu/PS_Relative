/************
<�ּ�>		: p44, 46
**********
<�ذ���>	:

obj->member();
obj.operator->()->member();

-> ��
operator->()-> �� �ٲ�!

**********
<�����Ʈ>	:

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