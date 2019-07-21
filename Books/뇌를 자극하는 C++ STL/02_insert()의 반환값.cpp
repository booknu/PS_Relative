/************
<�ּ�>		: p280
**********
<�ذ���>	:

insert�� ��ȯ���� set�� ���������� pair<���� ��ġ �ݺ���, ��������>

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <map>
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
	map<int, int> m;
	pair<map<int, int>::iterator, bool> res;

	fillMap(m);
	printMap(m);

	res = m.insert(make_pair(10, 1111));
	if (res.second) {
		cout << "����: (" << res.first->first << ", " << res.first->second << ") " << endl;
	} else {
		cout << "(10, 1111) ���� ����!" << endl;
	}

	res = m.insert(make_pair(1, 1111));
	if (res.second) {
		cout << "����: (" << res.first->first << ", " << res.first->second << ") " << endl;
	} else {
		cout << "����: (1, 1111)" << endl;
	}

	printMap(m);

	return 0;
}