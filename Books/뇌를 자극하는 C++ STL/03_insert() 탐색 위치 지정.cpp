/************
<�ּ�>		: p257
**********
<�ذ���>	:

������ ��ġ�� �����Ͽ� ���Ҹ� ����
���� ������ ��ġ�� ���� ������ ������ O(1)�� ���Ե�����, �ƴ϶�� O(log n)���� ���Ե�

ex) ���� �� -> ū �� ������ �߰��� ���
    ū ���� ���κп� ��ġ�� Ȯ���� �����Ƿ� ���� ��ġ�� end()�� �ִ°� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <set>
using namespace std;

void printSet(const set<int> &s) {
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	set<int> s;
	pair<set<int>::iterator, bool> res;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	res = s.insert(90);
	printSet(s);

	s.insert(res.first, 85); // 90������ �ݺ��ڿ��� �˻� ���� �� ����
	printSet(s);

	return 0;
}