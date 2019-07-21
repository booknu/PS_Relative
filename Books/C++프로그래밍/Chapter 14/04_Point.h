/************
<�ּ�>		: p561
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

template <class T>
class Point {
private:
	T x, y;

public:
	Point(T x = 0, T y = 0);
	void print();

	// Point<T>�� ���� << �����ε�
	friend ostream& operator<<(ostream &os, const Point &pos) {
		os << '(' << pos.x << ", " << pos.y << ')';
		return os;
	}
};

template <class T>
Point<T>::Point(T x, T y) : x(x), y(y) { }

template <class T>
void Point<T>::print() {
	cout << '(' << x << ", " << y << ')' << endl;
}

#endif