/************
<�ּ�>		: p567
**********
<�ذ���>	:

**********
<�����Ʈ>	:

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
 *	�⺻ Ŭ���� ���ø�
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
 *	Ŭ���� ���ø� Ư��ȭ (char*�� ����)
 */
template <>
class SimpleDataWrapper<char*> {
private:
	char *mdata;

public:
	// ������ ��ɸ� ��� ����
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
 *	Ŭ���� ���ø� Ư��ȭ (Point<int>�� ����)
 */
template <>
class SimpleDataWrapper<Point<int>> {
private:
	Point<int> mdata;

public:
	// ������ ��ɸ� ��� ����
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