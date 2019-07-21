/************
<주소>		: p570
**********
<해결방안>	:

템플릿 특수화도 모든 템플릿의 자료형이 특정되야 하는 것은 아니다.
부분적으로 특정되도록 선언할 수도 있다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

/**
 *	기본 템플릿 클래스 <T1, T2>
 */
template <class T1, class T2>
class Class {
public:
	void print() {
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of T2: " << sizeof(T2) << endl;
		cout << "<class T1, class T2>" << endl << endl;
	}
};

/**
 *	템플릿 클래스 특수화 <int, double>
 */
template <>
class Class<int, double> {
public:
	void print() {
		cout << "size of int: " << sizeof(int) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<int, double>" << endl << endl;
	}
};

/**
 *	템플릿 클래스 특수화 <T1, double>
 *	이렇게 일부분만 특수화 가능!
 *	위의 <int, double>인 경우를 제외하고 2번째 인자가 double이 오면 이거!
 */
template <typename T1>
class Class<T1, double> {
public:
	void print() {
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<T1, double>" << endl << endl;
	}
};

/**
 *	템플릿 클래스 특수화 <double, T2>
 *	이렇게 일부분만 특수화 가능!
 */
template <typename T2>
class Class<double, T2> {
public:
	void print() {
		cout << "size of double: " << sizeof(double) << endl;
		cout << "size of T2: " << sizeof(T2) << endl;
		cout << "<double, T2>" << endl << endl;
	}
};


class Main {
public:
	static int main() {
		Class<int, int> c1;
		c1.print();

		Class<int, double> c2;
		c2.print();
		
		Class<float, double> c3;
		c3.print();

		Class<double, float> c4;
		c4.print();

		return 0;
	}
};