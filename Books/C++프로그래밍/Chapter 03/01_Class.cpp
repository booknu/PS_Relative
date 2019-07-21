///************
//<�ּ�>		: p123
//**********
//<�ذ���>	:
//�������� �����ڸ� �������� �ʾ��� ��
//class�� private, struct�� public���� ����.
//�� �ܿ��� class�� struct�� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
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
//// class�� struct�� �������� Ű�����,
//// struct�� ���� Car c = {}; �� ������ �� �ִµ� ����, 
//// class�� ���� �̷��� �������� ���ϰ� Constructor�θ� ������ �����ϴ�.
//class Car {
//// class �������� ���� ���
//private:
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuel;
//	int speed;
//// ��𼭳� ���� ���
//public:
//	void init(char *ID, int fuel); // Constructor ���� �Լ� �߰�
//	void showCarStatus();
//	void accel();
//	void stop();
//};
//
//void Car::init(char *ID, int fuel) {
//	strcpy_s(Car::gamerID, CAR_CONST::ID_LEN, ID);
//	Car::fuel = fuel;
//	Car::speed = 0;
//}
//
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