/************
<주소>		: p158
**********
<해결방안>	:
( vector<typename T, typename Alloc = allocator<T>> )
( set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>> )
**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	// vector<typename T, typename Alloc = allocator<T>>
	// 기본 allocator을 통해 생성
	vector<int, allocator<int>> v;
	v.push_back(10);
	cout << *v.begin() << endl;

	// set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>>
	// 기본 allocator을 통해 생성
	set<int, less<int>, allocator<int>> set;
	set.insert(10);
	cout << *set.begin() << endl;

	return 0;
}