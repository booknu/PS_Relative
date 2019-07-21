/************
<�ּ�>		: p233
**********
<�ذ���>	:

list�� ������ ���Ұ� ������, ���Ҹ� �ϳ��� ����� �������� �����.
������ ���ҿ��� ����� ��, ��ü������ ���� ���Ұ� ���� ���� ������ �����ؾ� �Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &ls) {
	// const list<int>�� ��ȸ�ϴ� �ݺ����̱� ������ const_iterator�� ���!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(40);
	lt.push_back(30);
	printList(lt);

	lt.unique();
	printList(lt);

	return 0;
}