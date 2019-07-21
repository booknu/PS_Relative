/************
<�ּ�>		: p579
**********
<�ذ���>	:

�����Ϸ��� "�Լ� ���ø� -> (������) ���ø� �Լ�" �� ����µ�,
�� �� �Լ� ���ø� �ȿ� static ������ ������
static ���� ���� �������� �޸𸮿� ���� ����ȴ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

template <class T>
void staticValueFunc() {
	static T n = 0;
	n += 1;
	cout << n << " ";
}

class Main {
public:
	static int main() {
		// ������ int ���ø� �Լ������� static ���� �޸𸮴� ����������,
		staticValueFunc<int>();
		staticValueFunc<int>();
		cout << endl;

		// �ٸ��� ������ double ���ø� �Լ������� static ������ �� �ٸ� ������ �����
		staticValueFunc<double>();
		staticValueFunc<double>();
		cout << endl;

		// �̰͵� ��������
		staticValueFunc<long>();
		staticValueFunc<long>();
		cout << endl;
		return 0;
	}
};