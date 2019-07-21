///************
//<주소>		: p21
//**********
//<해결방안>	:
//배열 형태의 문자열 IO
//white space를 기준으로 입력 문자열이 잘리기 때문에 띄어쓰기가 포함된 문자열은 입력불가
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//int main(void) {
//	char name[100], lang[200];
//
//	std::cout << "Name: ";
//	std::cin >> name;
//
//	std::cout << "Language: ";
//	std::cin >> lang;
//
//	std::cout << std::endl;
//	std::cout << "Your name is " << name << "!" << std::endl;
//	std::cout << "Your language is " << lang << "!" << std::endl;
//}