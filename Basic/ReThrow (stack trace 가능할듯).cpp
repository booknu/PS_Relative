/************
<�ּ�>		: p616
**********
<�ذ���>	:

catch�� throw�� Exception�� �ٽ� throw �� �� �ִ�.
==> �̰� Ȱ���ؼ� printStackTrace ���� �� ������!

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static void Divide(int a, int b) throw(int) {
		try {
			if (b == 0) {
				throw 0;
			}
			cout << "��: " << a / b << endl;
			cout << "������: " << a % b << endl;
		} catch (int e) {
			cout << "Exception occured in Divide(" << a << ", " << b << ")" << endl;
			throw; // ���ܸ� �ٽ� ����!
		}
	}

	static int main() {
		try {
			Divide(1, 0);
		} catch (int e) {
			cout << "Exception catched in main(): " << e << endl;
		}
		
		return 0;
	}
};