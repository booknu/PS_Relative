///************
//<주소>		: p87
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
//int& refRetFunc(int &n) {
//	int num = n; // num은 local
//	num += 100;
//	return num;
//}
//
//// 의미 없는 함수 (단순 호출용)
//int notMeaningfulFunc(int a, int b, int c, int d) {
//	return 100;
//}
//
//int main(void) {
//	int n = 1;
//	int &ret = refRetFunc(n); // 컴파일시 Warning은 뜨지만, Error은 뜨지 않음
//	// 이 함수 호출 없이 실행하면 ret 값은 101로 정상적으로 나옴.
//	// but 그것은 아직 Stack에 쌓여있는 local variable인 num이 덮어씌워지지 않았기 때문.
//	// 이렇게 다른 함수를 호출하여 Stack을 덮어씌워버리면 이미 없어진 num값은 이상한 값으로 덮어씌워짐
//	notMeaningfulFunc(1, 2, 3, 4);
//	cout << ret << endl;
//}