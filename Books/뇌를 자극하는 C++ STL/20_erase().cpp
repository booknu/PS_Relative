/************
<�ּ�>		: p200
**********
<�ذ���>	:

iter = erase(p)		: p�ڸ��� �ִ� ���Ҹ� �����, ���� �ڸ��� �ִ� ������ iter ��ȯ
iter = erase(b, e)	: b ~ e ������ ���Ҹ� �����, ���� �ڸ��� �ִ� ������ iter ��ȯ

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

	vector<int>::iterator iter1 = v.begin() + 2;
	vector<int>::iterator iter2;
	iter2 = v.erase(iter1); // iter1�� ��ġ�� �ִ� ���Ҹ� �����, �� �� �� �ڸ��� �ִ� ������ iter�� ��ȯ
	printVector(v);

	iter1 = v.begin() + 1;
	iter2 = iter1 + 2;
	v.erase(iter1, iter2); // iter1 ~ iter2�� ��ġ�� �ִ� ���Ҹ� �����, �� �ڸ��� �ִ� ������ iter�� ��ȯ
	printVector(v);

	return 0;
}