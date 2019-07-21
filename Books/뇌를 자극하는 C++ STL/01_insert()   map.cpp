/************
<�ּ�>		: p278
**********
<�ذ���>	:

map�� ���� insert �� ����, pair ���·� ���� �Ѵ�.
���� make_pair�� ����ϰų� pair ��ü�� ����� �־�� �Ѵ�.

���� �ݺ��ڴ� *�� ->�� �����ε� �Ǿ� �����Ƿ�
(*iter).first �� iter->first �� �� �����ϴ�.

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

	fillMap(m);
	printMap(m);

	return 0;
}