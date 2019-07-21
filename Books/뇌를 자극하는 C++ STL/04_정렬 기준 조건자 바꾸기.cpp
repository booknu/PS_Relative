/************
<주소>		: p283
**********
<해결방안>	:

map<T, T, Predicate> 형식으로 템플릿에 정렬 기준이 되는 함수객체 or 함수포인터를 줌 (조건자)

**********
<오답노트>	:

*/

#include <iostream>
#include <map>
#include <functional>
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
	map<int, int, greater<int>> m; // 이런식으로

	fillMap(m);
	printMap(m);

	return 0;
}