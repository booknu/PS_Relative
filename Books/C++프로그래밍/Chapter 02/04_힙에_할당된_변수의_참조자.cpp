///************
//<주소>		: p95
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
//int main(void) {
//	// new 사용
//	int *p = new int;
//	int &ref = *p;
//	ref = 20; // 포인터를 사용하지 않고 heap에 접근 가능!
//	cout << *p << endl;
//
//	// malloc 사용
//	int *p2 = (int*)malloc(sizeof(int) * 1);
//	int &ref2 = *p2;
//	ref2 = 30; // malloc의 경우도 사용가능
//	cout << *p2 << endl;
//}