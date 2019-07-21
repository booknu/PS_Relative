///************
//<주소>		: p38
//**********
//<해결방안>	:
//
//using namespace Name; // ::을 사용하지 않아도 Name안의 함수를 사용하는걸로 간주
//func();   // 묵시적 전역
//::func(); // 명시적 전역
//Name::func(); // Name의 func를 불러옴
//
//:: = 범위지정 연산자 (scope resolution operator)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//namespace name1 {
//	void sameFunc(void) {
//		std::cout << "name1's function" << std::endl;
//	}
//}
//
//namespace name2 {
//	void sameFunc(void) {
//		std::cout << "name1's function" << std::endl;
//	}
//}
//
//void sameFunc(void) {
//	std::cout << "global function" << std::endl;
//}
//
//int main(void) {
//	// 특정 Namespace 호출시 name::function() 으로 호출
//	name1::sameFunc();
//	name2::sameFunc();
//	sameFunc();   // 묵시적 전역
//	::sameFunc(); // 명시적 전역
//
//	std::cout << std::endl << "----- after using namespace name1 -----" << std::endl;
//	using namespace name1;
//	//sameFunc(); // 이것은 global과 name1의 함수를 동시에 뜻하므로 컴파일 오류가 발생함
//	::sameFunc(); // 명시적 전역
//
//	return 0;
//}