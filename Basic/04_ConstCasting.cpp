/************
<�ּ�>		: p640
**********
<�ذ���>	:

[ ������� ]
const type -> type

[ ��� ]
��������, ��������

[ ��� �� ]
� �Լ��� ���ڰ� const���� �ƴѵ�, ������ ���ο��� ���� �ٲ��� �ʴ´ٸ�
const ��ü/������ �� �Լ��� ���ڷ� ���� �� ����.
�̷� �� const_cast�� ����ϸ� �Լ��� ȣ�� �� �� �ִ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	/**
	 *	������ str�� ���� �ٲ����� ������, const�� ��������� �ʾҴ�.
	 */
	static void showString(char *str) {
		cout << str << endl;
	}

	/**
	 *	������ a, b�� ���� �ٲ����� ������, const�� ��������� �ʾҴ�.
	 */
	static void add(int &a, int &b) {
		cout << a + b << endl;
	}

	static int main() {
		const char *name = "My Name!";
		char *arg = const_cast<char*>(name); // const char* -> char*
		showString(arg); // const char* -> char* ����ȯ�� ���� ������ ������ ������ ����!

		cout << reinterpret_cast<int>(arg) << ' ' << reinterpret_cast<int>(name) << endl;

		// const_cast�� ����� ������, ������ �̹Ƿ� �̷��� ����
		const int &a = 100;
		const int &b = 200;

		// const int& -> int&
		int &castA = const_cast<int&>(a);
		int &castB = const_cast<int&>(b);

		add(castA, castB);
		cout << &a << ' ' << &castA << endl;
		cout << &b << ' ' << &castB << endl;

		return 0;
	}
};