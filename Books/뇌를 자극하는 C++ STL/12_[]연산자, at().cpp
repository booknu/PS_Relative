/************
<주소>		: p186
**********
<해결방안>	:

[]연산자는 범위 확인 x
at()함수는 범위 확인 o (참조를 반환) ==> 범위를 벗어나면 out_of_range 예외 던짐

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

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
	cout << endl;

	try {
		cout << v.at(4);
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	

	return 0;
}