/************
<�ּ�>		: p138
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>

#define pb push_back

using namespace std;


int main(void) {
	vector<int> v;

	v.pb(10);
	v.pb(20);
	v.pb(30);

	vector<int>::iterator iter; // vector�� ��ȸ�ϴ� �ݺ��� ��ü
	for (iter = v.begin(); iter < v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}