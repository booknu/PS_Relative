///************
//<주소>		: p263
//**********
//<해결방안>	:
//static 멤버 함수에서는 static 멤버 변수, static 멤버 함수만 접근 가능!
//
//1. 선언된 class의 모든 객체가 공유
//2. public으로 선언되면, class의 이름을 통해 호출 가능
//3. 객체의 멤버가 아님!
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	static int staticNum;
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	// static 멤버 함수
//	static void func() {
//		// cout << num << endl; 은 num이 static 멤버 변수가 아니라 불가!
//		cout << staticNum << endl;
//	}
//};
//int Class::staticNum = 10000; // static 멤버 변수 초기화
//
//int main() {
//	Class::func(); // static 멤버 함수 호출
//}