/************
<�ּ�>		:p366
**********
<�ذ���>	:

���Ҹ� �����ϴ� �˰�����, ���Ҹ� �����ϴ� �˰����� Ư���� �������μ�
���� ���Ҹ� �����ϴ� ���� �ƴϰ�, Overwrite ����� ���� ������ �� ó�� ���̰� �����.
���� size�� ������ �ʴ´�.

size���� ���ϰ� �ϰ� ������ �����̳� ��� �Լ��� erase()�� ����ؾ��Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T, typename Predicate>
void print(const vector<T, Predicate> &s) {
	for (vector<T, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

void print(vector<int>::iterator from, vector<int>::iterator to) {
	for (; from != to; from++) {
		cout << *from << ' ';
	}
	cout << endl;
}

template <typename T, typename Predicate>
void fill(vector<T, Predicate> &s, int same = 1, int add = 0) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(i * 10 + add);
		}
	}
}

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	vector<int>::iterator ret = remove(v.begin(), v.end(), 30);

	// ������ size�� ������ �ʴ´�!
	cout << "size = " << v.size() << endl;
	print(v); // begin ~ end
	print(v.begin(), ret); // begin ~ remove��ȯ��

	// size���� ���ϰ� �ϰ� �ʹٸ� erase ���!
	v.erase(ret, v.end());
	print(v);

	return 0;
}