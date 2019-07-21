/************
<�ּ�>		: p612
**********
<�ذ���>	:

try-����catch ������
try���� Exception�� �߻��� ���

�ش� Exception�� ȣȯ�Ǵ� catch���� ã�� ������ ������ ��������.
���� ã����, �ش� catch������ ó���� �ǰ� ����ó���� ������.
���� �� ã����, Stack Unwinding���� �ϸ鼭 ã�´�.

[ ��� ���迡 �ִ� ���ܸ� catch �Ϸ���? ]
catch Base
catch Derived
�� ���� �ع�����, Derived ���ܰ� �������� Base���� catch�� �ȴ�.

����
catch Derived
catch Base
�� ���� Base Exception�� catch���� �� ���� �Ʒ��� �ִ°� ����.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class AAA {
public:
	void printStackTrace() {
		cout << "AAA Excpetion!" << endl;
	}
};

class BBB : public AAA {
public:
	void printStackTrace() {
		cout << "BBB Excpetion!" << endl;
	}
};

class CCC : public BBB {
public:
	void printStackTrace() {
		cout << "CCC Excpetion!" << endl;
	}
};

class Main {
public:
	static void exceptionGenerator(int e) {
		switch (e) {
		case 1:
			throw AAA();
		case 2:
			throw BBB();
		case 3:
			throw CCC();
		}
	}

	static int main() {
		try {
			exceptionGenerator(3);
			exceptionGenerator(2);
			exceptionGenerator(1);
		} catch (AAA e) {
			// CCC ���ܰ� ����������, CCC�� AAA Ŭ������ ����ϰ� �ֱ� ������ ���⼭ �ɸ�
			// ���� Base Exception�� catch���� �� ���� �Ʒ� �δ°� ����!
			cout << "catch (AAA e)" << endl;
			e.printStackTrace();
		} catch (BBB e) {
			cout << "catch (BBB e)" << endl;
			e.printStackTrace();
		} catch (CCC e) {
			cout << "catch (CCC e)" << endl;
			e.printStackTrace();
		}
		

		return 0;
	}
};