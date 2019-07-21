/************
<주소>		: p63
**********
<해결방안>	:

정적 함수 포인터

1. 전역함수
2. namespace 안의 전역함수
3. 객체의 static 멤버함수

를 가리킬 수 있음

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

void Print(int n) {
	cout << "전역함수: " << n << endl;
}

namespace A {
	void Print(int n) {
		cout << "namespace A 전역함수: " << n << endl;
	}
}

class Point {
public:
	static void Print(int n) {
		cout << "Point 클래스의 static 멤버함수: " << n << endl;
	}
};

int main(void) {
	void(*pf)(int);
	
	// 함수 이름으로 호출
	Print(10);
	A::Print(11);
	Point::Print(12);

	// 함수 포인터로 호출
	pf = Print;
	pf(10);
	pf = A::Print;
	pf(11);
	pf = Point::Print;
	pf(12);

	return 0;
}