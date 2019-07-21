/************
<�ּ�>		: p235
**********
<�ذ���>	:

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

// ���� ������
// ���� �ں��� ũ�� true
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

	lt.unique(Predicate()); // �����ڿ� ���� ������ ���� ������ ���� (��ġ ��������ó�� ��)
	printList(lt);

	return 0;
}