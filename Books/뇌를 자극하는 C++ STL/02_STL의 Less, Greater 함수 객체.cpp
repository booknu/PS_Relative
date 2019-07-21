/************
<주소>		: p83
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <functional>
using namespace std;

int main(void) {
	//// less ////
	less<int> lt;

	cout << lt(10, 20) << endl;
	cout << lt(20, 10) << endl;
	cout << lt.operator()(10, 20) << endl;
	cout << endl;

	cout << less<int>()(10, 20) << endl;

	//// greater ////
	greater<int> gt;

	cout << gt(10, 20) << endl;
	cout << gt(20, 10) << endl;

	return 0;
}