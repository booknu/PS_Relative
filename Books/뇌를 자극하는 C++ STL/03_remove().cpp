/************
<�ּ�>		: p226
**********
<�ذ���>	:

remove(n)�� n�� �ش��ϴ� ���Ҹ� ��� �����.

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
	list<int> lt;

	fillList(lt);
	lt.push_back(20);
	lt.push_back(20);
	printList(lt);

	lt.remove(20);
	printList(lt);

	return 0;
}