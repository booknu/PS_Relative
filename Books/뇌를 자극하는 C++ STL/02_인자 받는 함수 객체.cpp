/************
<�ּ�>		: p78
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Functor {
public:
	void operator()(int a, int b) {
		cout << a << ", " << b << endl;
	}
};

int main(void) {
	Functor f;
	
	f(1, 2);

	return 0;
}