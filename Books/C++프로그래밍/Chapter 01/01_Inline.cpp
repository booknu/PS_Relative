///************
//<주소>		: p34
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//
///*
//	인라인 함수는 매크로 함수와 똑같은 기능을 한다.
//	하지만, 명시적으로 자료형을 표현해야 하므로, 매크로를 사용하는 것과는 조금 다르다.
//	이런 문제는 템플릿을 사용함으로서 해결할 수 있다.
//*/
//inline int max(int a, int b) {
//	return a > b ? a : b;
//}
//
///*
//	인라인 함수를 템플릿을 활용해 구현한 모습.
//	매크로와 정확히 같은 기능을 한다.
//*/
//template <typename T>
//inline T min(T a, T b) {
//	return a < b ? a : b;
//}
//
//int main(void) {
//	std::cout << "----- inline function -----" << std::endl;
//	std::cout << max(10, 5) << std::endl;
//	std::cout << max(-1, 1) << std::endl;
//
//	std::cout << "----- use template -----" << std::endl;
//	std::cout << min(10, 5) << std::endl;
//	std::cout << min(-1, 1) << std::endl;
//	return 0;
//}