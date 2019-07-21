/************
<�ּ�>		: p278
**********
<�ذ���>	:

insert�� �̿����� �ʾƵ�, []�����ڸ� �̿��ϸ� ���Ҹ� �߰�, ������ �����ϴ�
m[key] = value;

���� key�� ���ٸ� ���Ҹ� �߰��ϰ�,
key�� �ִٸ� value�� �����Ѵ�.

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

	cout << m[-1] << endl; // �������� �ʴ� ����


	return 0;
}