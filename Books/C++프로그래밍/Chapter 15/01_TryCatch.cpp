/************
<�ּ�>		: p591
**********
<�ذ���>	:

����ó���� try-catch������ ������� ��

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		int n1, n2;
		cout << "�� ���� ���� �Է�: ";
		cin >> n1 >> n2;

		// n2 = 0�� �� ArithmeticException �߻� (Divided by Zero)
		// try-catch���� ���ؼ� ����ó���� �� ���
		try {
			if (n2 == 0) {
				throw n2; // ���� ��ü�� ����
			}
			cout << "�������� ��: " << n1 / n2 << endl;
			cout << "�������� ������: " << n1 % n2 << endl;
		} catch(int expn) {
			cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
			cout << "���α׷��� �����մϴ�..." << endl;
		}
		cout << "end of main" << endl;

		return 0;
	}
};