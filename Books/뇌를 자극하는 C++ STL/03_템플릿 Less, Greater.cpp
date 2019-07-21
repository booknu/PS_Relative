/************
<�ּ�>		: p120
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class Less {
public:
	bool operator()(T a, T b) const {
		return a < b;
	}
};

template <typename T>
class Greater {
public:
	bool operator()(T a, T b) const {
		return a > b;
	}
};

int main(void) {
	// ���� ����
	cout << Less<int>()(10, 20) << endl;
	cout << Less<int>()(20, 10) << endl;
	cout << Greater<int>()(10, 20) << endl;
	cout << Greater<int>()(20, 10) << endl;
	cout << endl;

	// STL
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << greater<int>()(10, 20) << endl;
	cout << greater<int>()(20, 10) << endl;
	return 0;
}