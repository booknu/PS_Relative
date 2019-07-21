///************
//<주소>		: p110
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//#define ID_LEN		20
//#define MAX_SPD		200
//#define FUEL_STEP	2
//#define ACC_STEP	10
//#define BRK_STEP	10
//
//// struct 내부에 함수들이 들어간 것에 유의
//// 이 때 안에 들어간 함수들은 묵시적으로 "inline 함수"로 처리된다.
//struct Car {
//	char gamerID[ID_LEN];
//	int fuel;
//	int speed;
//
//	// 현재 Car에 대한 함수이므로 Car을 인자로 받을 필요가 없음!
//	void showCarStatus() {
//		cout << "----- status -----" << endl;
//		cout << "소유자ID: " << gamerID << endl;
//		cout << "연료: " << fuel << endl;
//		cout << "속도: " << speed << endl << endl;
//	}
//
//	void accel() {
//		if (fuel <= 0) {
//			return;
//		} else {
//			fuel -= FUEL_STEP;
//		}
//
//		if (speed + ACC_STEP >= MAX_SPD) {
//			speed = MAX_SPD;
//		} else {
//			speed += ACC_STEP;
//		}
//	}
//
//	void stop() {
//		if (speed < BRK_STEP) {
//			speed = 0;
//		} else {
//			speed -= BRK_STEP;
//		}
//	}
//};
//
//int main(void) {
//	Car A = { "A", 100, 0 };
//	A.accel();
//	A.accel();
//	A.showCarStatus();
//	A.stop();
//	A.showCarStatus();
//
//	Car B = { "B", 100, 0 };
//	B.accel();
//	B.stop();
//	B.showCarStatus();
//
//	return 0;
//}