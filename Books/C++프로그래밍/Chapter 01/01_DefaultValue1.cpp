///************
//<주소>		: p28
//**********
//<해결방안>	:
//함수에 인자를 주지 않거나, 적게 주고 호출하면
//인자가 주어진 부분 이외에는 인자가 default value인 것으로 처리된다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//void print(int a = 1, int b = 2) {
//	std::cout << "a = " << a << ", b = " << b << std::endl;
//}
//
//int main(void) {
//	print(); // a, b가 default value
//	print(-1); // b가 default value
//	print(-1, -1);
//}