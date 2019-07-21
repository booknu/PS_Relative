/************
<주소>		: p98
**********
<해결방안>	:

함수 템플릿의 매개변수로 타입뿐만 아니라 정수 등도 가능하다!

**********
<오답노트>	:

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