///************
//<주소>		: p256
//**********
//<해결방안>	:
//특정 Class에서만의 전역 변수가 필요한 상황.
//
//aaaCnt, bbbCnt가 클래스 내에서만 필요한 전역변수인데, 밖으로 빠져나와 있어서 위험함
//따라서 static 상태 변수(클래스 변수)가 필요
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//int aaaCnt = 0; // 클래스 내에서만 필요한데, 밖으로 빠져나와 있어서 위험!
//int bbbCnt = 0;
//
//class AAA {
//public:
//	AAA() {
//		cout << ++aaaCnt << "번째 AAA 객체 생성" << endl;
//	}
//};
//
//class BBB {
//public:
//	BBB() {
//		cout << ++bbbCnt << "번째 BBB 객체 생성" << endl;
//	}
//	BBB(BBB &another) {
//		cout << ++bbbCnt << "번째 BBB 객체 생성" << endl;
//	}
//};
//
//int main(void) {
//	AAA a1;
//	AAA a2;
//
//	BBB b1;
//	BBB b2 = b1;
//	BBB();
//
//	return 0;
//}