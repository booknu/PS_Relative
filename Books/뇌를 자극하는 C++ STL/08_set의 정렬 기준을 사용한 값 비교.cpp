/************
<주소>		: p264
**********
<해결방안>	:

비교를 할 때 같은지를 판단할 때 "== 연산"을 사용하지 않고 "조건자"를 사용해서 비교한다.
즉, !Pred(a, b) && !Pred(b, a) 인 것이 같은 것이다.

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
using namespace std;

int main(void) {
	set<int, less<int>> s;

	// 30, 50
	cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl;

	// 30, 30
	cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl;

	return 0;
}