/************
<�ּ�>		: p644, p646
**********
<�ذ���>	:

[ ������� ]
Derive -> Base
Base -> Derived (��, Base�� Polymorphic Class �� ���)

[ ��� ]
��������, ��������

[ Polymorphic Class ]
�ϳ� �̻��� �����Լ��� ���ϴ� Ŭ����

[ ���� ]
Base -> Derived ��
Dynamic Type�� Base -> Derived���,
�����ͷ� NULL�� ��ȯ�Ѵ�.

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
		// OK! static: (Base -> Derived), dynamic: (Derived -> Derived)
		Base *bp = new Derived();
		Derived *dp = dynamic_cast<Derived*>(bp); // Base�� Polymorphic Class �̹Ƿ� dynamic_cast ����!
		dp->print();
		
		// NULL static: (Base -> Derived), dynamic: (Base -> Derived)
		Base *bp2 = new Base();
		Derived *dp2 = dynamic_cast<Derived*>(bp); // Base�� Polymorphic Class �̹Ƿ� dynamic_cast ����!
		if (dp2 == NULL) {
			cout << "dynamic type�� ���� �ʽ��ϴ�." << endl;
		}

		return 0;
	}
};