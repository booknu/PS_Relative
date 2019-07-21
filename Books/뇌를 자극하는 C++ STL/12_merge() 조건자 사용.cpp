/************
<�ּ�>		: p242
**********
<�ذ���>	:

�� list�� �ϳ��� ���ĵ� list�� �պ��Ѵ�.
�� list�� ���� �������� ���ĵǾ� �־�� �Ѵ�. (�ƴϸ� ������)

���� �� list�� �����ڸ� ����Ͽ� ���ĵǾ� ������, merge���� �����ڸ� ����ؾ� �Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <list>
#include <functional>
using namespace std;

void printList(const list<int> &ls) {
	// const list<int>�� ��ȸ�ϴ� �ݺ����̱� ������ const_iterator�� ���!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

void print(const list<int> &list1, const list<int> &list2) {
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
}

int main(void) {
	list<int> list1;
	list<int> list2;

	list1.push_back(50);
	list1.push_back(40);
	list1.push_back(30);
	list1.push_back(20);
	list1.push_back(10);

	list2.push_back(55);
	list2.push_back(45);
	list2.push_back(25);

	print(list1, list2);
	cout << "===========" << endl;

	list1.merge(list2, greater<int>()); // ������ ���
	print(list1, list2);

	return 0;
}