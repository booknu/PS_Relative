/************
<�ּ�>		: p587
**********
<�ذ���>	:

����ó���� if������ ������� ��
���� �߻�����, �߰�����, ó�������� �� ���� ���⿡ ��ƴ�.

[ �� �� ]
����ó���� ���� �ڵ��,
���α׷� �帧�� �����ϴ� �ڵ带 ���� �������� ����

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
		// if���� ���ؼ� ����ó���� �� ���
		if (n2 == 0) {
			cout << "Divided by Zero Exception" << endl;
		} else {
			cout << "�������� ��: " << n1 / n2 << endl;
			cout << "�������� ������: " << n1 % n2 << endl;
		}
		
		return 0;
	}
};