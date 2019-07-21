/************
<주소>		: p278
**********
<해결방안>	:

map에 값을 insert 할 때는, pair 형태로 들어가야 한다.
따라서 make_pair을 사용하거나 pair 객체를 만들어 넣어야 한다.

또한 반복자는 *과 ->가 오버로딩 되어 있으므로
(*iter).first 나 iter->first 둘 다 가능하다.

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

	return 0;
}