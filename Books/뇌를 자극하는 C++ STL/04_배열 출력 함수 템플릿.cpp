/************
<�ּ�>		: p98
**********
<�ذ���>	:

�Լ� ���ø��� �Ű������� Ÿ�ԻӸ� �ƴ϶� ���� � �����ϴ�!

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

template <typename T, int size>
void PrintArray(T* arr) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;
}

int main(void) {
	int arr[] = { 10, 20, 30, 40, 50 };

	PrintArray<int, 5>(arr);

	return 0;
}