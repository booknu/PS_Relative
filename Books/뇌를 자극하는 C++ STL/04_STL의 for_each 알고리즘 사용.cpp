/************
<주소>		: p71
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <algorithm>
using namespace std;

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

	// STL의 for_each 알고리즘 사용해서 콜백 함수 넘기기 연습
	for_each(arr, arr + 5, Print1);
	cout << endl << endl;
	for_each(arr, arr + 5, Print2);
	cout << endl << endl;
	for_each(arr, arr + 5, Print3);

	return 0;
}