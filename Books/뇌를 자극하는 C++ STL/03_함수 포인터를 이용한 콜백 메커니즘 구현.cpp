/************
<주소>		: p69
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

//// 서버 ////
void For_each(int *begin, int *end, void(*pf)(int)) {
	while (begin != end) {
		pf(*begin++); // 클라이언트 함수 콜백
	}
}

//// 클라이언트 ////
void Print1(int n) {
	cout << n << ' ';
}

void Print2(int n) {
	cout << n*n << ' ';
}

void Print3(int n) {
	cout << "정수: " << n << endl;
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};

	// 서버에 동작할 함수를 넘겨주는 식으로 작동 가능 (콜백 함수 주소 전달)
	For_each(arr, arr + 5, Print1);
	cout << endl << endl;;
	For_each(arr, arr + 5, Print2);
	cout << endl << endl;
	For_each(arr, arr + 5, Print3);

	return 0;
}