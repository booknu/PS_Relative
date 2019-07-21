/************
<주소>		: p567
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Point {
private:
	int x, y;

public:
	Point(T x = 0, T y = 0) : x(x), y(y) { }
	friend ostream& operator<<(ostream &os, Point &p) {
		os << '(' << p.x << ", " << p.y << ')';
		return os;
	}
};

/**
 *	기본 클래스 템플릿
 */
template <typename T>
class SimpleDataWrapper {
private:
	T mdata;

public:
	SimpleDataWrapper(T data) : mdata(data) { }
	void print() {
		cout << "Data: " << mdata << endl;
	}
};

/**
 *	클래스 템플릿 특수화 (char*에 대해)
 */
template <>
class SimpleDataWrapper<char*> {
private:
	char *mdata;

public:
	// 구현한 기능만 사용 가능
	SimpleDataWrapper(char *data) {
		int len = strlen(data) + 1;
		mdata = new char[len];
		strcpy_s(mdata, len, data);
	}
	void print() {
		cout << "String: " << mdata << endl;
	}
	~SimpleDataWrapper() {
		delete[] mdata;
	}
};

/**
 *	클래스 템플릿 특수화 (Point<int>에 대해)
 */
template <>
class SimpleDataWrapper<Point<int>> {
private:
	Point<int> mdata;

public:
	// 구현한 기능만 사용 가능
	SimpleDataWrapper(int x, int y) : mdata(x, y) { }
	void print() {
		cout << mdata << endl;
	}
};

class Main {
public:
	static int main() {
		SimpleDataWrapper<char*> w1("HelloWorld!");
		w1.print();
		SimpleDataWrapper<int> w2(222);
		w2.print();
		SimpleDataWrapper<Point<int>> w3(-3, -3);
		w3.print();
		return 0;
	}
};