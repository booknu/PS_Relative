/************
<주소>		: p257
**********
<해결방안>	:

삽입할 위치를 지정하여 원소를 삽입
만약 지정한 위치가 정렬 순서에 맞으면 O(1)로 삽입되지만, 아니라면 O(log n)으로 삽입됨

ex) 작은 값 -> 큰 값 순으로 추가할 경우
    큰 값은 끝부분에 위치할 확률이 높으므로 삽입 위치로 end()를 주는게 유리

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
using namespace std;

void printSet(const set<int> &s) {
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	set<int> s;
	pair<set<int>::iterator, bool> res;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	res = s.insert(90);
	printSet(s);

	s.insert(res.first, 85); // 90원소의 반복자에서 검색 시작 후 삽입
	printSet(s);

	return 0;
}