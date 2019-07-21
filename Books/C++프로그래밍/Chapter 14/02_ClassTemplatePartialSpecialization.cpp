/************
<�ּ�>		: p570
**********
<�ذ���>	:

���ø� Ư��ȭ�� ��� ���ø��� �ڷ����� Ư���Ǿ� �ϴ� ���� �ƴϴ�.
�κ������� Ư���ǵ��� ������ ���� �ִ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

/**
 *	�⺻ ���ø� Ŭ���� <T1, T2>
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
 *	���ø� Ŭ���� Ư��ȭ <int, double>
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
 *	���ø� Ŭ���� Ư��ȭ <T1, double>
 *	�̷��� �Ϻκи� Ư��ȭ ����!
 *	���� <int, double>�� ��츦 �����ϰ� 2��° ���ڰ� double�� ���� �̰�!
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
 *	���ø� Ŭ���� Ư��ȭ <double, T2>
 *	�̷��� �Ϻκи� Ư��ȭ ����!
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