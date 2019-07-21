/************
<주소>		: p278
**********
<해결방안>	:

insert를 이용하지 않아도, []연산자를 이용하면 원소를 추가, 갱신이 가능하다
m[key] = value;

만약 key가 없다면 원소를 추가하고,
key가 있다면 value를 갱신한다.

**********
<오답노트>	:

*/

#include <iostream>
#include <map>
using namespace std;

template <typename T1, typename T2, typename Predicate>
void printMap(const map<T1, T2, Predicate> &s) {
	for (map<T1, T2, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // 이것도 가능!
		cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	cout << endl;
}

template <typename T1, typename T2, typename Predicate>
void fillMap(map<T1, T2, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(make_pair(i, i * 100));
	}
}

int main(void) {
	map<int, int> m;

	fillMap(m);
	printMap(m);

	cout << m[-1] << endl; // 존재하지 않는 원소


	return 0;
}