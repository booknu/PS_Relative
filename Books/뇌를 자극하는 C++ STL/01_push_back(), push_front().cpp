/************
<�ּ�>		: p220
**********
<�ذ���>	:

**********
<�����Ʈ>	:

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
	// const list<int>�� ��ȸ�ϴ� �ݺ����̱� ������ const_iterator�� ���!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	list<int> ls;

	fillList(ls);
	printList(ls);

	for (int i = 1; i <= 5; i++) {
		ls.push_front(-i);
	}
	printList(ls);

	return 0;
}