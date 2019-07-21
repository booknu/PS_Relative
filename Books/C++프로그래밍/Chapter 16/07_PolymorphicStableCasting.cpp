/************
<�ּ�>		: p646
**********
<�ذ���>	:

[ ������� ]
Derive -> Base
Base -> Derived (��, Base�� Polymorphic Class �� ���)

[ ��� ]
��������, ��������

[ Polymorphic Class ]
�ϳ� �̻��� �����Լ��� ���ϴ� Ŭ����

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
		Base *bp = new Derived();
		Derived *dp = dynamic_cast<Derived*>(bp); // Base�� Polymorphic Class �̹Ƿ� dynamic_cast ����!
		dp->print();

		return 0;
	}
};