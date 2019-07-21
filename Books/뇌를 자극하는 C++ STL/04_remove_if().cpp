/************
<�ּ�>		:
**********
<�ذ���>	:

remove_if(predicate) �� �Լ� ��ü or �Լ� �����͸� ���ڷ� �־� �� ���ǿ� �´� ���ҵ鸸 �����.
(���� ������)

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

// ���� ������
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

	lt.remove_if(Predicate()); // ���ǿ� �´� ���ҵ��� ����
	printList(lt);

	return 0;
}