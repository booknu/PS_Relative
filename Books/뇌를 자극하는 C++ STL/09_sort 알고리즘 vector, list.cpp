/************
<주소>		: p144
**********
<해결방안>	:

sort 알고리즘은 Random Access Iterator을 필요로 함
따라서 양방향 Iterator만 지원하는 list의 경우는 컴파일 에러

**********
<오답노트>	:

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(void) {
	vector<int> v;
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	list<int> list;
	list.push_back(30);
	list.push_back(50);
	list.push_back(10);
	list.push_back(20);
	list.push_back(40);

	sort(v.begin(), v.end());
	//sort(list.begin(), list.end()); // 컴파일 에러! (임의 접근 반복자 필요)

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}