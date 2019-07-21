/************
<주소>		: p202
**********
<해결방안>	:

순차열 구간 [v.begin(), v.end())로 assing을 할 수 있다.
생성자에도 가능

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
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end()); // 순차열 [v1.begin(), v1.end()) 로 v2 초기화
	printVector(v2);

	vector<int> v3(15, -1);
	printVector(v3);
	v3.assign(v1.begin(), v1.end()); // 순차열 [v1.begin(), v1.end()) 로 v3 할당
	printVector(v3);

	return 0;
}