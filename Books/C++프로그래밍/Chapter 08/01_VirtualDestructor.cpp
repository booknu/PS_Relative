///************
//<주소>		: p357
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h> // 디버깅용
//using namespace std;
//
//class First {
//private:
//	char *strOne;
//
//public:
//	First(char *str) {
//		strOne = new char[strlen(str) + 1];
//	}
//	// virtual destructor가 아니면 Static Type에 따라 소멸자가 불려지므로, 메모리 누수 발생할수도!
//	// 실제로 여기서 virtual 키워드 없이 실행해본다면 이 소멸자 밖에 실행 안 되고 Second의 소멸자는 실행이 안 됨!
//	virtual ~First() {
//		cout << "~First();" << endl;
//		delete[] strOne;
//	}
//};
//
//class Second : public First {
//private:
//	char *strTwo;
//
//public:
//	Second(char *str1, char *str2) : First(str1){
//		int len = strlen(str2) + 1;
//		strTwo = new char[len];
//		strcpy_s(strTwo, len, str2);
//	}
//	~Second() {
//		cout << "~Second();" << endl;
//		delete[] strTwo;
//	}
//};
//
//int main() {
//	First *p = new Second("first", "second");
//	delete p;
//
//	_CrtDumpMemoryLeaks(); // F5로 디버깅 모드로 실행하면 메모리 누수가 있는지 확인 가능! (출력 로그 확인)
//
//	return 0;
//}