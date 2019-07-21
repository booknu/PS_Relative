/************
<�ּ�>		: p283
**********
<�ذ���>	:

map<T, T, Predicate> �������� ���ø��� ���� ������ �Ǵ� �Լ���ü or �Լ������͸� �� (������)

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <map>
#include <functional>
using namespace std;

template <typename T1, typename T2, typename Predicate>
void printMap(const map<T1, T2, Predicate> &s) {
	for (map<T1, T2, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // �̰͵� ����!
		cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	cout << endl;
}

template <typename T1, typename T2, typename Predicate>
void fillMap(map<T1, T2, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(make_pair(i, i * 100));
	}
}

int main(void) {
	map<int, int, greater<int>> m; // �̷�������

	fillMap(m);
	printMap(m);

	return 0;
}