/************
<�ּ�>		: p68
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;
void Client();

//// ���� ////
void PrintHello() {
	cout << "Hello" << endl;
	Client(); // ���������� Ŭ���̾�Ʈ �ڵ� �ݹ�
}

//// Ŭ���̾�Ʈ ////
void Client() {
	cout << "Client������ �ڵ� ����" << endl; // �ݹ� �Լ�
}

int main(void) {
	PrintHello();

	return 0;
}