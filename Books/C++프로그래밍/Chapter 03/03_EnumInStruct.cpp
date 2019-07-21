///************
//<주소>		: p115
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
//// namespace를 통해 상수들을 관리할 수도 있음
//// 혹은 enum을 구조체 내부에 삽입해서 사용할 수도 있음
//namespace CAR_CONST {
//	// enum을 통해 현재 구조체에서만 필요한 상수들 정의!
//	enum {
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//}
//
//struct Car {
//
//	// 여기에 enum을 넣고 사용해도 됨 (이 때는 namespace 필요 없음)
//
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuel;
//	int speed;
//
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
//			fuel -= CAR_CONST::FUEL_STEP;
//		}
//
//		if (speed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
//			speed = CAR_CONST::MAX_SPD;
//		} else {
//			speed += CAR_CONST::ACC_STEP;
//		}
//	}
//
//	void stop() {
//		if (speed < CAR_CONST::BRK_STEP) {
//			speed = 0;
//		} else {
//			speed -= CAR_CONST::BRK_STEP;
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