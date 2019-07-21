/************
<주소>		: p152
**********
<해결방안>	:

rbegin, rend를 활용한 reverse_iterator 활용

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

	for (vector<int>::reverse_iterator rIter = v.rbegin(); rIter != v.rend(); rIter++) {
		cout << *rIter << endl;
	}

	return 0;
}