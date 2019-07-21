/************
<�ּ�>		: p221
**********
<�ذ���>	:

list�� insert(), erase()�� O(1)
���� �̰��� Node ��� �����̳ʵ鿡���� �ݺ��ڰ� ��ȿȭ ���� �ʴ´�.
(���� ��ü�� ���ŵ��� �ʴ���)

������, Array ��� �����̳ʵ鿡���� �ݺ��ڰ� ��ȿȭ �ȴ�.
(�� ���� �� �޸𸮰� ���Ҵ� �ǰų�, ���Ұ� �̵��� �� �ֱ� ����)

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

	// list�� iterator�� ����� �ݺ����̱� ������ ++, --���길 ����
	list<int>::iterator iter1 = ls.begin();
	iter1++;
	iter1++;

	// erase
	iter1 = ls.erase(iter1);
	printList(ls);

	// insert
	ls.insert(iter1, 5, -1);
	printList(ls);
	cout << *iter1 << endl; // list������ ���Ұ� �������� �ʴ��� iterator�� ��ȿȭ ���� �ʴ´�!

	return 0;
}