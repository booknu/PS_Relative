/************
<�ּ�>		: p260
**********
<�ذ���>	:

set�� ���� ������ value�� �� �񱳷� ���Ǵ� key�� �ǹǷ� value, key Ÿ���� ����.

key_comp(), value_comp()�� ���� ���� �����ڸ� ��ȯ�Ѵ�. (��ȯ ������ �Ʒ�)
key_compare, value_compare�� ���� ���� �����̴�. (typedef ���� ��� ����)

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main(void) {
	set<int, less<int>> s_less;
	set<int, greater<int>> s_greater;

	s_less.insert(50);
	s_less.insert(80);
	s_less.insert(40);

	s_greater.insert(50);
	s_greater.insert(80);
	s_greater.insert(40);

	// ���� ������ �����´�
	set<int, less<int>>::key_compare l_comp = s_less.key_comp();
	set<int, greater<int>>::key_compare g_comp = s_greater.key_comp();

	// ���� ������ �̷��� ��� ����
	cout << l_comp(10, 20) << endl;
	cout << g_comp(10, 20) << endl;

	cout << "key_comp: " << typeid(s_less.key_comp()).name() << endl;
	cout << "key_comp: " << typeid(s_greater.key_comp()).name() << endl;
	cout << "value_comp: " << typeid(s_less.value_comp()).name() << endl;
	cout << "value_comp: " << typeid(s_greater.value_comp()).name() << endl;

	return 0;
}