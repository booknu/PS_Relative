/************
<�ּ�>		: p302
**********
<�ذ���>	:

�������� ���ǿ� �´� x�� ������ ��

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
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
void fill(vector<T, Predicate> &s, int fill = 1) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < fill; j++) {
			s.push_back(i * 10);
		}
	}
}

// ������
class Pred {
public:
	bool operator()(int n) {
		return n >= 30 && n <= 40;
	}
};

int main(void) {
	vector<int> v;

	fill(v, 3);
	print(v);

	cout << count_if(v.begin(), v.end(), Pred()) << endl; // ���ǿ� �´� ���� �� ��

	return 0;
}