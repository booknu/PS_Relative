/************
<주소>		: p235
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &ls) {
	// const list<int>를 순회하는 반복자이기 때문에 const_iterator을 사용!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

// 이항 조건자
// 앞이 뒤보다 크면 true
class Predicate {
public:
	bool operator()(int first, int second) {
		return first > second;
	}
};

int main(void) {
	list<int> lt;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(50);
	lt.push_back(40);
	lt.push_back(60);
	printList(lt);

	lt.unique(Predicate()); // 조건자에 따라 인접한 원소 삭제를 결정 (마치 오름차순처럼 됨)
	printList(lt);

	return 0;
}