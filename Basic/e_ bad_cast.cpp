/************
<�ּ�>		: p647
**********
<�ذ���>	:

[ �߻� ��ġ ]
dynamic_cast ���� �� �߻�

[ ��� ]
��������
(���������� ���� �׳� NULL ��ȯ)

[ ���� ]
dynamic_cast ��
dynamic type�� Base -> Derived �� ���

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

/**
*	virtual �Լ��� �ϳ� �̻� ������ �����Ƿ�
*	Polymorphic Class
*/
class Base {
public:
	virtual void print() {
		cout << "virtual Base Class" << endl;
	}
};

class Derived : public Base {
public:
	void print() {
		cout << "virtual Derived Class" << endl;
	}
};

class Main {
public:
	static int main() {
		Base b;
		Base &refB = b;

		try {
			Derived &refD = dynamic_cast<Derived&>(refB);
			refD.print();
		} catch (bad_cast e) {
			cout << "type cast �� Exception ����" << endl;
			cout << e.what() << endl;
		}

		return 0;
	}
};