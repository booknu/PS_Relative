///************
//<주소>		: p29
//**********
//<해결방안>	:
//함수의 원형을 별도로 선언시, 그 부분에만 Default Value를 지정해야 함
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//void print(int a = 1, int b = 2); // 함수의 원형을 별도로 선언할 때는, 이 부분에만 Default Value 지정
//
//int main(void) {
//	print();
//	print(-1);
//	print(-1, -1);
//}
//
//void print(int a, int b) {
//	std::cout << "a = " << a << ", b = " << b << std::endl;
//}