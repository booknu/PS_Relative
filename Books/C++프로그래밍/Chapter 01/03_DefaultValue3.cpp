///************
//<주소>		: p31
//**********
//<해결방안>	:
//함수의 default value 지정은 그 인자의 오른쪽부터 채워야 함.
//왜냐하면 함수의 인자는 왼쪽부터 오른쪽으로 전달되기 때문 (마이크로프로세서 시간 때 스택에 인자가 전달되는 법)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//void print1(int a, int b = 2, int c = 3) {
//	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
//}
//
//void print2(int a, int b, int c = 3) {
//	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
//}
//
//int main(void) {
//	std::cout << "----- print 1 -----" << std::endl;
//	print1(-1);
//	print1(-1, -1);
//	print1(-1, -1, -1);
//
//	std::cout << "----- print 2 -----" << std::endl;
//	print2(-1, -1);
//	print2(-1, -1, -1);
//	std::cout << "-------------------" << std::endl;
//
//}