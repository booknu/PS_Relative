/************
<�ּ�>		: p192
********** 
<�ذ���>	:

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

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator c_iter = v.begin();

	*iter = 1;
	//*c_iter = 1; // ������ ����

	return 0;
}