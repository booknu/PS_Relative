/************
<�ּ�>		: p586
**********
<�ذ���>	:

����ó���� ���� �ʾ��� ��

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
		// ����ó���� �� �ϸ� ���α׷��� ������ ��ä ����
		cout << "�������� ��: " << n1 / n2 << endl;
		cout << "�������� ������: " << n1 % n2 << endl;
		return 0;
	}
};