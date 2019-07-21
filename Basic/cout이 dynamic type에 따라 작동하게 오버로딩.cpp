/************
<�ּ�>		:
**********
<�ذ���>	:

operator<< �� �����Լ��� �����ε� �ؾ��ϱ� ������ virtual�� �����ϴ� ���� �Ұ����ϴ�.
���� virtual void out(); �̶�� �Լ��� ��¿����� ����ϰ�,
operator<< �ȿ����� out�� ȣ���ϸ� dynamic type�� ���� print�� �ȴ�.

���� operator<< �� ���� Base Ŭ������ �ϳ� �����س����� �˾Ƽ� dynamic type�� ���� out�� ȣ���Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Base {
public:
	// ��¿�
	virtual void out(ostream &os) const {
		os << "BASE";
	}
	friend ostream& operator<<(ostream &os, Base &b);
};

// operator<< �����ε��� ���� ������ Base���� �����س����� ��
// ���⼭ b�� dynamic type�� ���� out�� ȣ���
ostream& operator<<(ostream &os, const Base &b) {
	b.out(os);
	return os;
}

class Derived : public Base {
public:
	// ��¿�
	virtual void out(ostream &os) const {
		os << "DERIVED";
	}
};

class Main {
public:
	static int main() {
		// dynamic type�� ���� ����� ��!
		Base *b = new Derived();
		cout << *b << endl;
		delete b;

		b = new Base();
		cout << *b << endl;
		delete b;

		return 0;
	}
};
