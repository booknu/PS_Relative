/************
<�ּ�>		: p152
**********
<�ذ���>	:

rbegin, rend�� Ȱ���� reverse_iterator Ȱ��

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::reverse_iterator rIter = v.rbegin(); rIter != v.rend(); rIter++) {
		cout << *rIter << endl;
	}

	return 0;
}