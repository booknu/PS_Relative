/************
<�ּ�>		: p616
**********
<�ذ���>	:

catch(...) {} �� ��� ���ܸ� ����ش�.
������, ���ܿ� ���� ����, Ÿ���� �� �� ����.

���� catch�� �� �������� ���°� �Ϲ����̴�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class MyException {
public:
	void printStackTrace() {
		cout << "My Exception!" << endl;
	}
};

class Main {
public:
	static void exception(int e) throw(MyException, int, double) {
		if (e == 0) {
			throw MyException();
		} else if(e == 1) {
			throw (int)2100000000;
		} else if (e == 2) {
			throw (double)0.00001;
		}
	}

	static int main() {
		try {
			exception(0);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "����: " << e << endl;
		} catch (...) {
			// � ���ܵ� �� �����!
			// but, ������ ���� �� ������, ���޵� ���� ������ ���� �Ұ�!
			cout << "�� �� ���� ���� �߻�!" << endl;
		}

		try {
			exception(1);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "����: " << e << endl;
		} catch (...) {
			// � ���ܵ� �� �����!
			// but, ������ ���� �� ������, ���޵� ���� ������ ���� �Ұ�!
			cout << "�� �� ���� ���� �߻�!" << endl;
		}

		try {
			exception(2);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "����: " << e << endl;
		} catch (...) {
			// � ���ܵ� �� �����!
			// but, ������ ���� �� ������, ���޵� ���� ������ ���� �Ұ�!
			cout << "�� �� ���� ���� �߻�!" << endl;
		}
		return 0;
	}
};