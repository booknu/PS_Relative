///************
//<주소>		: p32 - 문제 1
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
//int boxVolume(int l, int w, int h) {
//	return l * w * h;
//}
//
//int boxVolume(int l, int w) {
//	int h = 1;
//	return l * w * h;
//}
//
//int boxVolume(int l) {
//	int w, h;
//	w = h = 1;
//	return l * w * h;
//}
//
//int boxVolume() {
//	int l, w, h;
//	l = w = h = 1;
//	return l * w * h;
//}
//
//int main(void) {
//	std::cout << "[3, 3, 3]: " << boxVolume(3, 3, 3) << std::endl;
//	std::cout << "[5, 5, D]: " << boxVolume(5, 5) << std::endl;
//	std::cout << "[7, D, D]: " << boxVolume(7) << std::endl;
//	std::cout << "[D, D, D]: " << boxVolume() << std::endl;
//}