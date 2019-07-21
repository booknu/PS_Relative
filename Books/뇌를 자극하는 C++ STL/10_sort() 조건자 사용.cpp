/************
<�ּ�>		: p238
**********
<�ذ���>	:

������ �����̳ʴ� ��� sort�� �����Ѵ�.
vector, deque�� �˰����� qsort()�� �̿��Ͽ� ����������,
list�� random access�� �Ұ����ϱ� ������ �� �ȴ�.
���� list�� ��ü������ sort() ����Լ��� �����Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <functional>
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

	lt.push_back(20);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);
	lt.push_back(30);
	lt.push_back(60);
	printList(lt);
	
	lt.sort(greater<int>()); // ������������ ����
	printList(lt);

	return 0;
}