/************
<�ּ�>		: p595
**********
<�ذ���>	:

Exception�� ����.

Exception�� throw�ƴµ� �װ��� ó���� try-catch���� ���ٸ�,
Exception�� �ش� �Լ��� ȣ���� �������� �Ѿ�� �ȴ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static void divide(int n1, int n2) {
		if (n2 == 0) {
			throw n2; // ���� ��ü�� ����
		}
		cout << "�������� ��: " << n1 / n2 << endl;
		cout << "�������� ������: " << n1 % n2 << endl;
	}

	static int main() {
		int n1, n2;
		cout << "�� ���� ���� �Է�: ";
		cin >> n1 >> n2;

		try {
			// n2 = 0�� �� ArithmeticException �߻� (Divided by Zero)
			// divide �Լ����� ���ܰ� �߻��ϸ� catch �� �� �ִ�.
			divide(n1, n2);
		}
		catch (int expn) {
			// divide �Լ��� �������� �� ���ܰ� �������� ����� ��
			cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
			cout << "���α׷��� �����մϴ�..." << endl;
		}
		cout << "end of main" << endl;

		return 0;
	}
};