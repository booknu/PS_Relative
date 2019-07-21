///************
//<주소>		: p534
//**********
//<해결방안>	:
//
//2가지 이상의 type에 대해 템플릿을 선언할 수 있고,
//함수 템플릿의 return, param이 기본 자료형이어도 그 내부에서 템플릿을 사용할 수 있다.
//
//**********
//<오답노트>	:
//
//*/
//
//template <typename T1, typename T2>
//void print(double n) {
//	cout << (T1)n << ", " << (T2)n << endl;
//}
//
//#include <iostream>
//using namespace std;
//
//int main() {
////	print(65); 위와 같은 경우에는 param이 이미 정해졌기 때문에 인자를 통해 T1, T2 자료형을 결정하지 못한다.
//	print<char, int>(65);
//	print<char, int>(67);
//	print<char, double>(68.9);
//	print<short, double>(69.2);
//	print<short, double>(70.4);
//
//	return 0;
//}