/************
<주소>		: p183
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v) {
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> v1(10, 12345);
	vector<int> v2(5, -10);

	printVector(v1);
	printVector(v2);
	cout << "===== swap =====" << endl;
	
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

	return 0;
}