/************
<�ּ�>		: p87 - ���� 2
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Equal {
public:
	bool operator()(int a, int b) {
		return a == b;
	}
};

int main(void) {
	Equal cmp;

	cout << (cmp(10, 20) ? "����" : "�ٸ���") << endl;

	return 0;
}