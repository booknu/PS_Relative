/************
<주소>		: p135
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

	return 0;
}