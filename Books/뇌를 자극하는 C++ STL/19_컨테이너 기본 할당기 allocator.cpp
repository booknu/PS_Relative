/************
<�ּ�>		: p158
**********
<�ذ���>	:
( vector<typename T, typename Alloc = allocator<T>> )
( set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>> )
**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	// vector<typename T, typename Alloc = allocator<T>>
	// �⺻ allocator�� ���� ����
	vector<int, allocator<int>> v;
	v.push_back(10);
	cout << *v.begin() << endl;

	// set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>>
	// �⺻ allocator�� ���� ����
	set<int, less<int>, allocator<int>> set;
	set.insert(10);
	cout << *set.begin() << endl;

	return 0;
}