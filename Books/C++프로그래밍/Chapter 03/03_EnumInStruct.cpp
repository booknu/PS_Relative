///************
//<�ּ�>		: p115
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//// namespace�� ���� ������� ������ ���� ����
//// Ȥ�� enum�� ����ü ���ο� �����ؼ� ����� ���� ����
//namespace CAR_CONST {
//	// enum�� ���� ���� ����ü������ �ʿ��� ����� ����!
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
//	// ���⿡ enum�� �ְ� ����ص� �� (�� ���� namespace �ʿ� ����)
//
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuel;
//	int speed;
//
//	void showCarStatus() {
//		cout << "----- status -----" << endl;
//		cout << "������ID: " << gamerID << endl;
//		cout << "����: " << fuel << endl;
//		cout << "�ӵ�: " << speed << endl << endl;
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