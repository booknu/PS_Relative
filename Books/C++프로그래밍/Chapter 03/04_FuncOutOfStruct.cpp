///************
//<�ּ�>		: p118
//**********
//<�ذ���>	:
//
//�Լ��� ���� ������ struct ���ο� �ΰ�,
//�� ���Ǵ� ����ü �ۿ��� �Ѵ�.
//
//�̰����� ���� ����ü�� ó�� ���� �� "��������", "�Լ�����"�� �� ���� ���� �������� ��������.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//namespace CAR_CONST {
//	enum {
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//}
//
//// C++���� struct�� class�� �������� ���ֵȴ�. (struct Ű���� ��� class ����ϸ� ��) (�ٸ� Car a = {};�� �������� ���ϰ� ��)
//// ���� struct�� class��� ǥ���ص� Ʋ���� �ʴ´�.
//struct Car {
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuel;
//	int speed;
//
//	void showCarStatus();
//	void accel();
//	void stop();
//};
//
//// �Լ��� ������ ����ü ���ο� ����,
//// �� ���Ǵ� ����ü �ۿ��� �� ���
//// �������� ��������.
//// �Լ��� ������ ���� Car::�� �ٿ� Car�� �Լ����� ����ؾ� �Ѵ�.
//void Car::showCarStatus() {
//	cout << "----- status -----" << endl;
//	cout << "������ID: " << gamerID << endl;
//	cout << "����: " << fuel << endl;
//	cout << "�ӵ�: " << speed << endl << endl;
//}
//
//void Car::accel() {
//	if (fuel <= 0) {
//		return;
//	} else {
//		fuel -= CAR_CONST::FUEL_STEP;
//	}
//
//	if (speed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
//		speed = CAR_CONST::MAX_SPD;
//	} else {
//		speed += CAR_CONST::ACC_STEP;
//	}
//}
//
//void Car::stop() {
//	if (speed < CAR_CONST::BRK_STEP) {
//		speed = 0;
//	} else {
//		speed -= CAR_CONST::BRK_STEP;
//	}
//}
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