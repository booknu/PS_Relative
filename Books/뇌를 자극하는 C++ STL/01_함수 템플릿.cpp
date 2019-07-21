/************
<�ּ�>		: p93
**********
<�ذ���>	:

�Լ� ���ø�: �����ڰ� �������� �Լ��� Ʋ
���ø� �Լ�: �Լ� ���ø��� ������� �����Ϸ��� Ÿ�Կ� ���� �ʿ��� �Լ����� ���� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

template <typename T>
void Print(T a, T b) {
	cout << a << ", " << b << endl;
}

int main(void) {
	Print(10, 20);
	Print(10.1, 20.2);
	Print("Hello", "World!");

	// ���ø��� ����ϰ� ����� ���� ����
	Print<int>(10, 20);
	Print<double>(10.1, 20.2);
	Print<const char*>("Hello", "World!");

	return 0;
}