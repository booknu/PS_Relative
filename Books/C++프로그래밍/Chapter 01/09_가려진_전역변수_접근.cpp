///************
//<주소>		: p50
//**********
//<해결방안>	:
//
//global과 같은 이름의 local이 있으면, global은 local에 의해 가려진다.
//이 때 global에 접근하고 싶다면, ::name과 같이 접근하면 된다.
//(Scope Resolution Operator의 기능)
//
//**********
//<오답노트>	:
//
//*/
//
//#include<iostream>
//
//using namespace std;
//
//char str[] = "Global";
//
//int main(void) {
//	char str[] = "Local";
//
//	cout << str << endl; // local에 접근
//	cout << ::str << endl; // global에 접근 (명시적 전역)
//}