/************
<�ּ�>		: p51
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;
class A {

};

class B {
public:
	// B ��ü�� A, int, double ��ü�� ����ȯ ����!
	operator A() {
		cout << "operator A();" << endl;
		return A();
	}
	operator int() {
		cout << "operator int();" << endl;
		return 10;
	}
	operator double() {
		cout << "operator double();" << endl;
		return 9.9;
	}
};
int main(void) {
	B b;

	// �������ڸ��� ����ȯ�ؼ� �ʱ�ȭ
	A a = b;
	int i = b;
	double d = b;

	// ����� ������ ����
	a = b;
	i = b;
	d = b;

	// ����� ����ȯ
	(A)b;
	(int)b;
	(double)b;
//	(ostream)b; �����ε� ���� ���� ����ȯ�� �Ұ�!

}