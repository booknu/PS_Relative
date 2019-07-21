/************
<주소>		: p65
**********
<해결방안>	:

[[ 멤버 함수 포인터 선언 ]]

반환형 (클래스::*함수포인터)(args);
함수포인터 = &클래스::함수이름;				& 꼭 있어야 함!

[[ 멤버 함수 포인터 호출 ]]
1. 객체로 호출
	(객체.*함수포인터)(args);				*함수포인터 형식으로 호출

2. 객체포인터로 호출
	(객체포인터->*함수포인터)(args);

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Point {
	int x, y;

public:
	explicit Point(int _x = 0, int _y = 0): x(_x), y(_y) { } // 자동 형 변환을 위해 생성자가 호출되는 것을 막음
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "정수: " << n << endl; }
};

int main(void) {
	Point pt(2, 3);
	Point *p_pt = &pt;

	// 멤버함수 포인터 선언
	void (Point::*pf1)() const;
	pf1 = &Point::Print;
	void (Point::*pf2)(int);
	pf2 = &Point::PrintInt;

	// 객체로 함수 호출
	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	// 객체로 멤버함수 포인터를 통해 함수 호출
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;

	// 주소로 멤버함수 포인터를 통해 함수 호출
	(p_pt->*pf1)();
	(p_pt->*pf2)(10);
	cout << endl;

	return 0;
}