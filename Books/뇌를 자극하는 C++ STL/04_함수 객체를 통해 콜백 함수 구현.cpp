/************
<주소>		: p80
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <algorithm>
using namespace std;

//// 클라이언트 ////
class Functor1 {
public:
	void operator()(int n) {
		cout << n << " ";
	}
};

class Functor2 {
public:
	void operator()(int n) {
		cout << n * n << " ";
	}
};

class Functor3 {
public:
	void operator()(int n) {
		cout << "정수: " << n << endl;
	}
};

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	
	// 임시 함수 객체를 만들어 전달
	for_each(arr, arr + 5, Functor1());
	cout << endl << endl;
	for_each(arr, arr + 5, Functor2());
	cout << endl << endl;
	for_each(arr, arr + 5, Functor3());

	return 0;
}