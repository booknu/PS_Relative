/************
<�ּ�>		: p197
**********
<�ذ���>	:

insert(iter, x)		: iter ��ġ�� x ����
insert(iter, n, x)	: iter ��ġ�� n���� x ����
insert(iter, other_iter_begin, other_iter_end): iter ��ġ�� �ٸ� vector�� begin ~ end ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v) {
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	vector<int>::iterator iter = v.begin() + 2; // 2�� index�� -1�� 3�� ����
	v.insert(iter, 3, -1);
	printVector(v);

	// �ٸ� vector�� Ư�� ������ ����
	vector<int> v2;
	v2.push_back(-100);
	v2.push_back(-200);
	v2.push_back(-300);

	iter = v2.begin() + 1;
	v2.insert(iter, v.begin(), v.end());
	printVector(v2);
	return 0;
}