/************
<주소>		: p154
**********
<해결방안>	:

대부분의 알고리즘은 +연산자만으로 구현되어 있으며,
이렇게 구현된 알고리즘은 정방향, 역방향 순회가 모두 가능하다.

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

	vector<int>::iterator iter = v.begin() + 3; // 40을 가리키는 정방향 반복자
	vector<int>::reverse_iterator rIter(iter);

	// iter, rIter은 같은 위치를 가리키지만, 값은 다르다.
	cout << "정방향 반복자의 값: " << *iter << endl;
	cout << "역방향 반복자의 값: " << *rIter << endl;


	return 0;
}