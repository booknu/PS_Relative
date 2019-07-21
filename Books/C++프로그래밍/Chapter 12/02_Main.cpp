///************
//<주소>		:
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h>
//#include "02_String.h"
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//	String *s1 = new String("I like ");
//	String *s2 = new String("string class");
//	String *cat = new String(*s1 + *s2);
//
//	// << 연산자도 오버로딩 됨
//	cout << *s1 << endl;
//	cout << *s2 << endl;
//	cout << *cat << endl;
//
//	// == 연산자도 오버로딩 됨
//	if (*s1 == *s2) {
//		cout << "동일 문자열" << endl;
//	} else {
//		cout << "다른 문자열" << endl;
//	}
//
//	// >> 연산자도 오버로딩 됨
//	String *in = new String();
//	cout << "문자열 입력: ";
//	cin >> *in;
//	cout << "입력한 문자열: " << *in << endl;
//
//	delete s1;
//	delete s2;
//	delete in;
//	delete cat;
//
//	_CrtDumpMemoryLeaks();
//}