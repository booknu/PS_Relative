/************
<�ּ�>		: p71
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <algorithm>
using namespace std;

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

	// STL�� for_each �˰��� ����ؼ� �ݹ� �Լ� �ѱ�� ����
	for_each(arr, arr + 5, Print1);
	cout << endl << endl;
	for_each(arr, arr + 5, Print2);
	cout << endl << endl;
	for_each(arr, arr + 5, Print3);

	return 0;
}