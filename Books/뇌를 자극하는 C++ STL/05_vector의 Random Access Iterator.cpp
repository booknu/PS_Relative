/************
<주소>		: p140
**********
<해결방안>	:

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
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << endl;

	iter += 2;
	cout << *iter << endl;
	cout << endl;

	vector<int>::iterator iter2 = iter + 2;
	cout << *iter2 << endl;

	return 0;
}