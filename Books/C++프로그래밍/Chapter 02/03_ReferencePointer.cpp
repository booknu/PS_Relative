///************
//<주소>		: p73
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
//	int num = 12;
//	int *p = &num; // 포인터
//	int **dp = &p; // 더블 포인터
//
//	int &ref = num;
//	int *(&pref) = p; // int*형 ref인데, 그것이 int* p를 참조한다.
//	int **(&dpref) = dp; // int**형 ref인데, 그것이 int** dp를 참조한다.
//
//	cout << ref << ' ' << *pref << ' ' << **dpref << endl;
//}