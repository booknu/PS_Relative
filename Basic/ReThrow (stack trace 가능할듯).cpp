/************
<주소>		: p616
**********
<해결방안>	:

catch로 throw된 Exception은 다시 throw 될 수 있다.
==> 이걸 활용해서 printStackTrace 만들 수 있을듯!

**********
<오답노트>	:

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
			cout << "몫: " << a / b << endl;
			cout << "나머지: " << a % b << endl;
		} catch (int e) {
			cout << "Exception occured in Divide(" << a << ", " << b << ")" << endl;
			throw; // 예외를 다시 던짐!
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