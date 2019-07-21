/************
<주소>		: p61
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

void Print() {
	cout << "정적 전역함수" << endl;
}

class Point {
public:
	void Print() {
		cout << "멤버 함수" << endl;
	}
};

int main(void) {
	Point pt;
	Point *p_pt = &pt;

	Print();		// 1. 정적 전역함수 호출
	pt.Print();		// 2. 객체로 멤버함수 호출
	p_pt->Print();	// 3. 객체의 주소로 멤버함수 호출

	return 0;
}