/************
<주소>		: p117
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

// 반복자와 함수 포인터를 템플릿으로 선언하여 범용성을 높임
template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) {
	while (begin != end) {
		pf(*begin++);
	}
}

template <typename T>
void Print(T data) {
	cout << data << " ";
}

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	For_each(arr, arr + 5, Print<int>);
	cout << endl;

	string sarr[] = { "a", "abc", "한글" };
	For_each(sarr, sarr + 3, Print<string>); // 템플릿 함수를 포인터로 넘길 때는 꼭 매개변수 인자 명시!
	cout << endl;

	return 0;
}