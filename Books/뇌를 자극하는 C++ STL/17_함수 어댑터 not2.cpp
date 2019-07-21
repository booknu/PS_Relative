/************
<주소>		: p156
**********
<해결방안>	:

bool not2(Functional &func) 함수객체
bool을 반환하는 조건자 함수객체인 func의 반대 값을 반환

**********
<오답노트>	:

*/

#include <iostream>
#include <functional> // not2, less, greater
using namespace std;

int main(void) {
	// 임시 객체로 비교
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "================" << endl;
	cout << not2(less<int>())(10, 20) << endl;
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	// 객체로 비교
	less<int> l;
	cout << l(10, 20) << endl;
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "================" << endl;
	cout << not2(l)(10, 20) << endl;
	cout << not2(l)(20, 20) << endl;
	cout << not2(l)(20, 10) << endl;

	return 0;
}