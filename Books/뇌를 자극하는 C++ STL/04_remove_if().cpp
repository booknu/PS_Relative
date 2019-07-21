/************
<주소>		:
**********
<해결방안>	:

remove_if(predicate) 는 함수 객체 or 함수 포인터를 인자로 주어 그 조건에 맞는 원소들만 지운다.
(단항 조건자)

**********
<오답노트>	:

*/

#include <iostream>
#include <list>
using namespace std;

void fillList(list<int> &ls) {
	for (int i = 1; i <= 5; i++) {
		ls.push_back((i + 1) * 10);
	}
}

void printList(const list<int> &ls) {
	// const list<int>를 순회하는 반복자이기 때문에 const_iterator을 사용!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

// 단항 조건자
class Predicate {
public:
	bool operator()(int n) {
		return n <= 30;
	}
};

int main(void) {
	list<int> lt;

	fillList(lt);
	printList(lt);

	lt.remove_if(Predicate()); // 조건에 맞는 원소들을 지움
	printList(lt);

	return 0;
}