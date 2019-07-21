/************
<주소>		: p122
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
	T1 first;
	T2 second;
	Pair(const T1& fi, const T2& se) : first(fi), second(se) { }
};

int main(void) {
	Pair<int, int> p1(10, 20);
	cout << p1.first << ", " << p1.second << endl;
	Pair<int, string> p2(11, "STRING");
	cout << p2.first << ", " << p2.second << endl;

	return 0;
}