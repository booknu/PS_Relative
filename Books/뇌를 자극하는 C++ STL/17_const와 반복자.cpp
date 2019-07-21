/************
<주소>		: p194
**********
<해결방안>	:

iter을 const로 선언하면
int* const p;와 같다.
즉, 포인터(iter)가 가리키는 주소를 바꾸지 못한다 (++, --... 사용 불가)

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int arr[] = { 10, 20, 30, 40, 50 };

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	int *p = arr;
	cout << *iter << ", " << *p << endl; // iter은 p처럼 동작

	vector<int>::const_iterator c_iter = v.begin();
	const int *c_p = arr;
	cout << *c_iter << ", " << *c_p << endl; // c_iter은 c_p처럼 동작

	// iter을 const로 선언하면 다음 원소로 이동 불가! (포인터가 가리키는 주소 변경 불가)
	const vector<int>::const_iterator citer_const = v.begin();
	const int* const cp_const = arr;
	cout << *citer_const << ", " << cp_const << endl;

	return 0;
}