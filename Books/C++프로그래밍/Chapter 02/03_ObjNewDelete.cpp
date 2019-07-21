///************
//<주소>		: p94
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
//using namespace std;
//
//class Simple {
//public:
//	Simple() {
//		cout << "Constructor called" << endl;
//	}
//};
//
//int main(void) {
//	cout << "----- use new -----" << endl;
//	Simple *s1 = new Simple;
//
//	cout << "----- use malloc -----" << endl;
//	Simple *s2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc을 사용하면 Constructor가 호출되지 않음!
//
//	cout << "----- delete / free -----" << endl;
//	delete s1;
//	free(s2);
//	return 0;
//}