///************
//<�ּ�>		: p110
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
//#define ID_LEN		20
//#define MAX_SPD		200
//#define FUEL_STEP	2
//#define ACC_STEP	10
//#define BRK_STEP	10
//
//// struct ���ο� �Լ����� �� �Ϳ� ����
//// �� �� �ȿ� �� �Լ����� ���������� "inline �Լ�"�� ó���ȴ�.
//struct Car {
//	char gamerID[ID_LEN];
//	int fuel;
//	int speed;
//
//	// ���� Car�� ���� �Լ��̹Ƿ� Car�� ���ڷ� ���� �ʿ䰡 ����!
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