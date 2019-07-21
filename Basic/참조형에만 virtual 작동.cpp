/************
<�ּ�>		:
**********
<�ذ���>	:

virtual �Լ��� 
Base b = Derived();
�� ����Ǵ��� ����

Base b = Derived(); : �� ��
Base &ref = Derived(); : ��
Base *p = Derived() : ��

[ �� �� ]
������ ������ ��츸 dynamic type�� ���� �۵�

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Base {
public:
	virtual void sameFunc() {
		cout << "BASE" << endl;
	}
};

class Derived : public Base {
public:
	virtual void sameFunc() {
		cout << "DERIVED" << endl;
	}
};

class Main {
public:
	static int main() {
		// static type�� ���� �۵�
		cout << "[ Base b1 = Derived(); ]" << endl;
		Base b1 = Derived();
		b1.sameFunc();

		// dynamic type�� ���� �۵�
		cout << "[ Base *p = &Derived(); ]" << endl;
		Base *b2 = &Derived();
		b2->sameFunc();

		// dynamic type�� ���� �۵�
		cout << "[ Base *p = new Derived(); ]" << endl;
		Base *b3 = new Derived();
		b2->sameFunc();
		delete b3;

		// dynamic type�� ���� �۵�
		cout << "[ Base &ref = Derived(); ]" << endl;
		Base &b4 = Derived();
		b4.sameFunc();

		return 0;
	}
};