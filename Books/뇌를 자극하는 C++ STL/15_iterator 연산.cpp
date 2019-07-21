/************
<주소>		: p191
**********
<해결방안>	:

vector의 반복자는 random access iterator이므로
+, -, +=, -=, [] 연산자도 제공한다.

**********
<오답노트>	:

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
	cout << *iter << endl;

	iter += 2;
	cout << *iter << endl;

	iter -= 1;
	cout << *iter << endl;

	cout << iter[1] << endl;

	return 0;
}