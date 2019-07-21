/************
<�ּ�>		: p254
**********
<�ذ���>	:

set�� �ߺ��� ���Ҹ� ������� ����
insert�� ��ȯ���� pair(���Ե� ������ ��ġ, ��������)

���� �ݺ��ڰ� set�� ��ȸ�ϴ� ������ Inorder (LAR)

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

	s.insert(50);
	s.insert(20);
	s.insert(30);
	s.insert(10);
	s.insert(70);
	s.insert(40);
	s.insert(60);
	printSet(s);

	// �ߺ��� ���Ҹ� insert�ϸ� ������ ���� ����!
	// ��ȯ ���� pair�� (���Ե� ������ ��ġ, ��������)
	s.insert(10);
	s.insert(10);
	printSet(s);

	return 0;
}