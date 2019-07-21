/************
<�ּ�>		: p480
**********
<�ذ���>	:

���̺귯���� Smart Pointer�� ������, ���� ������ ��

[ Smart Pointer�� ]
�⺻������ ��ü�̸�, Pointer ó�� ������ �� �ְ�, ( *, -> )
�������� �ڵ����� delete ���شٴ� ������ ����

[ ���� ]
* : ���� ��ü�� ������ ��ȯ
->: ���� ��ü�� �ּҰ� ��ȯ

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int x, int y) : x(x), y(y) {
		cout << "Point ��ü ����" << endl;
	}
	~Point() {
		cout << "Point ��ü �Ҹ�" << endl;
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
 *	@brief	�Ϲ� �����Ϳ��� ��������, delete ������ �ڵ����� �̷����ٴ� ���̴�.
 *			�� �ܿ��� �Ϲ� �����Ϳ� �Ȱ��� ������� ����, ������ �� �ִ�.
 */
class SmartPtr {
private:
	Point *posptr;

public:
	SmartPtr(Point *ptr) : posptr(ptr) { }

	/**
	 *	����Ʈ �������� �⺻!
	 *	@return: ���� ��ü�� �������� ��ȯ
	 */
	Point& operator*() const {
		return *posptr;
	}

	/**
	 *	����Ʈ �������� �⺻!
	 *	@return: ���� ��ü�� �ּҰ��� ��ȯ 
	 */
	Point* operator->() const {
		return posptr;
	}

	/**
	 *	SmartPtr ��ü���� ���� �Ҵ��� ������ ������,
	 *	���޵Ǵ� ���ڰ� new�� ���� �����Ҵ� �� �ּ� ���̶�� ������ ���Ե�
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
		// ������ó�� * ���� ����!
		cout << *p1 << endl;
		cout << *p2 << endl;
		cout << *p3 << endl;

		// ������ó�� -> ���� ����!
		p1->set(10, 20);
		p2->set(30, 40);
		p3->set(50, 60);
		cout << *p1 << endl;
		cout << *p2 << endl;
		cout << *p3 << endl;

		return 0;
	}
};
