/************
<주소>		: p99
**********
<해결방안>	:

특수화 함수 템플릿은 일반적인 함수 템플릿이 처리하지 못하는 경우를 따로 처리하게 하는 것

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const { cout << x << ", " << y << endl; }
};

// 일반화 함수 템플릿
template <typename T>
void Print(T a) {
	// 이 방법으로는 Point 출력 불가!
	cout << a << endl;
}

// 특수화 함수 템플릿
template <>
void Print(Point a) {
	// 따라서 Point의 경우를 특수화
	cout << "Print특수화 버전: ";
	a.Print();
}

int main(void) {
	Print(10);				// 일반화 함수 템플릿
	Print(20.2);			// 일반화 함수 템플릿
	Print(Point(10, 20));	// 특수화 함수 템플릿

	return 0;
}