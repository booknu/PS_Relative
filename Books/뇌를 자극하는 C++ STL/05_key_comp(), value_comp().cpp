/************
<주소>		: p260
**********
<해결방안>	:

set은 저장 원소인 value가 곧 비교로 사용되는 key가 되므로 value, key 타입이 같다.

key_comp(), value_comp()는 정렬 기준 조건자를 반환한다. (반환 형식은 아래)
key_compare, value_compare은 정렬 기준 형식이다. (typedef 내장 멤버 형식)

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main(void) {
	set<int, less<int>> s_less;
	set<int, greater<int>> s_greater;

	s_less.insert(50);
	s_less.insert(80);
	s_less.insert(40);

	s_greater.insert(50);
	s_greater.insert(80);
	s_greater.insert(40);

	// 정렬 기준을 가져온다
	set<int, less<int>>::key_compare l_comp = s_less.key_comp();
	set<int, greater<int>>::key_compare g_comp = s_greater.key_comp();

	// 정렬 기준을 이렇게 사용 가능
	cout << l_comp(10, 20) << endl;
	cout << g_comp(10, 20) << endl;

	cout << "key_comp: " << typeid(s_less.key_comp()).name() << endl;
	cout << "key_comp: " << typeid(s_greater.key_comp()).name() << endl;
	cout << "value_comp: " << typeid(s_less.value_comp()).name() << endl;
	cout << "value_comp: " << typeid(s_greater.value_comp()).name() << endl;

	return 0;
}