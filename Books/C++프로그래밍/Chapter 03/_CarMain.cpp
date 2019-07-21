///************
//<주소>		: p130 - 3개 파일 중 Main 부분
//**********
//<해결방안>	:
//위의 02_Car, 03_CarInline을 시험하고 싶으면 이것을 사용
//VERSION에 따라 02, 03을 사용함
//
//**********
//<오답노트>	:
//
//*/
//
//// 여러 버전의 Car 사용 가능!
//#define VERSION 1 // 1: CarNormal, 2: CarInline
//
//#if VERSION == 1
//#include "02_Car.h"
//#include <iostream>
//using namespace std;
//using namespace carNormal;
//
//#elif VERSION == 2
//#include "03_CarInline.h"
//using namespace carInline;
//// carInline.h에서 std를 using namespace 했으니 필요X, iostream include도 마찬가지
//
//#endif
//
//
//int main(void) {
//	cout << "----- version " << VERSION << " -----" << endl;
//	Car A;
//	A.init("A", 100);
//	A.accel();
//	A.accel();
//	A.showCarStatus();
//	A.stop();
//	A.showCarStatus();
//
//	Car B;
//	B.init("B", 100);
//	B.accel();
//	B.stop();
//	B.showCarStatus();
//
//	return 0;
//}