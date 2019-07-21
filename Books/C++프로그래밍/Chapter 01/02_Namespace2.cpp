///************
//<주소>		: p40
//**********
//<해결방안>	: 
//
//"함수의 선언"은 헤더파일에 저장하고,
//"함수의 정의"는 소스파일에 저장하는것이 보통이므로
//
//namespace 내부에는 "함수의 선언"을 하고,
//그 외부에 "함수의 정의"를 한다.
//
//**********
//<오답노트>	: 
//
//*/
//
//#include <iostream>
//
//// 여기서는 "함수의 선언"
//namespace name1 {
//	void sameFunc(void);
//}
//
//namespace name2 {
//	void sameFunc(void);
//}
//
//int main(void) {
//	name1::sameFunc();
//	name2::sameFunc();
//}
//
//// 여기서는 "함수의 구현"
//void name1::sameFunc(void) {
//	std::cout << "name1's function" << std::endl;
//}
//
//void name2::sameFunc(void) {
//	std::cout << "name2's function" << std::endl;
//}