/************
<주소>		: p561
**********
<해결방안>	:

**********
<오답노트>	:

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

	// Point<T>에 대한 << 오버로딩
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