///************
//<주소>		: p99 - 문제 1
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <cstring> // string.h의 C++버전 사용
//
//using namespace std; // "std" namespace의 함수들 사용 (표준 라이브러리)
//
//int main(void) {
//	// strlen
//	char str[] = "Hello World!!";
//	cout << strlen(str) << endl;
//
//	// strcat
//	char cat[100] = "Cat + ";
//	strcat_s(cat, 100, str); // strcat_s를 사용하려면 cat의 크기를 미리 정해놓고, 최대 사이즈를 인자로 줘야 함
//	cout << cat << endl;
//
//	// strcpy
//	char cpy[100];
//	strcpy_s(cpy, 100, str);
//	cout << cpy << endl;
//
//	// strcmp
//	char a[] = "a";
//	char b[] = "b";
//	cout << strcmp(a, b) << endl; // LT
//	cout << strcmp(b, a) << endl; // GT
//	cout << strcmp(a, a) << endl; // EQ
//}