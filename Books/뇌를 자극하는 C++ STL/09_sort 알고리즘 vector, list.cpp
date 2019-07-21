/************
<�ּ�>		: p144
**********
<�ذ���>	:

sort �˰����� Random Access Iterator�� �ʿ�� ��
���� ����� Iterator�� �����ϴ� list�� ���� ������ ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(void) {
	vector<int> v;
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	list<int> list;
	list.push_back(30);
	list.push_back(50);
	list.push_back(10);
	list.push_back(20);
	list.push_back(40);

	sort(v.begin(), v.end());
	//sort(list.begin(), list.end()); // ������ ����! (���� ���� �ݺ��� �ʿ�)

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}