/************
<�ּ�>		: p69
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

//// ���� ////
void For_each(int *begin, int *end, void(*pf)(int)) {
	while (begin != end) {
		pf(*begin++); // Ŭ���̾�Ʈ �Լ� �ݹ�
	}
}

//// Ŭ���̾�Ʈ ////
void Print1(int n) {
	cout << n << ' ';
}

void Print2(int n) {
	cout << n*n << ' ';
}

void Print3(int n) {
	cout << "����: " << n << endl;
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};

	// ������ ������ �Լ��� �Ѱ��ִ� ������ �۵� ���� (�ݹ� �Լ� �ּ� ����)
	For_each(arr, arr + 5, Print1);
	cout << endl << endl;;
	For_each(arr, arr + 5, Print2);
	cout << endl << endl;
	For_each(arr, arr + 5, Print3);

	return 0;
}