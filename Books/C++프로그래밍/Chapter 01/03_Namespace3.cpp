///************
//<주소>		: p41
//**********
//<해결방안>	:
//
//같은 namespace에 정의된 함수 호출시에는 namespace를 명시할 필요가 없음.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//namespace name1 {
//	void sameFunc(void);
//}
//
//namespace name1 {
//	void inName1Func(void);
//}
//
//namespace name2 {
//	void sameFunc(void);
//}
//
//int main(void) {
//	name1::sameFunc();
//}
//
//void inName1Func(void) {
//	std::cout << "global inFunc called" << std::endl;
//}
//void name1::inName1Func(void) {
//	std::cout << "name1's inFunc called" << std::endl;
//}
//
//void name2::sameFunc(void) {
//	std::cout << "name2's func called" << std::endl;
//}
//
//void name1::sameFunc(void) {
//	std::cout << "name1's func called" << std::endl;
//	inName1Func(); // namespace를 명시할 필요가 없음! (같은 namespace)
//	::inName1Func(); // 명시적 전역
//	name2::sameFunc(); // namespace를 명시해야함! (다른 namespace)
//}