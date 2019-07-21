/************
<�ּ�>		:
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

void init(list<int> &list1, list<int> &list2) {
	list1.assign(10, -1);
	list2.swap(list<int>());
	fillList(list2);
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
	list<int>::iterator iter1;
	list<int>::iterator iter2_1;
	list<int>::iterator iter2_2;

	init(list1, list2);
	print(list1, list2);

	// list2 ��ü�� list1�� �ٿ��ֱ�
	init(list1, list2);
	iter1 = list1.begin();
	iter1++;
	iter1++;

	list1.splice(iter1, list2); // list2 ��ü �߶󳻱�
	cout << "===== splice(iter, other_list) =====" << endl;
	print(list1, list2);

	// list2 �� ���� 1���� list1�� �ٿ��ֱ�
	init(list1, list2);
	iter1 = list1.begin();
	iter1++;
	iter1++;
	iter2_1 = list2.begin();
	
	list1.splice(iter1, list2, iter2_1);
	cout << "===== splice(iter, other_list, other_iter) =====" << endl;
	print(list1, list2);

	// list2 �� �������� list1�� �ٿ��ֱ�
	init(list1, list2);
	iter1 = list1.begin();
	iter1++;
	iter1++;
	iter2_1 = list2.begin();
	iter2_2 = list2.begin();
	iter2_2++;
	iter2_2++;
	iter2_2++;

	list1.splice(iter1, list2, iter2_1, iter2_2);
	cout << "===== splice(iter, other_list, other_iter_begin, other_iter_end) =====" << endl;
	print(list1, list2);

	return 0;
}