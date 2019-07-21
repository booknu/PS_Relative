///************
//<�ּ�>		: p107
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
//// C++������ typedef�� ������� �ʾƵ� struct ���� ��� ����
//struct Car {
//	char gamerID[ID_LEN];
//	int fuel;
//	int speed;
//};
//
//// car�� ���� ������ ���� �����Ƿ� const�� ���� �Ϳ� ����!
//void showCarStatus(const Car &car) {
//	cout << "----- status -----" << endl;
//	cout << "������ID: " << car.gamerID << endl;
//	cout << "����: " << car.fuel << endl;
//	cout << "�ӵ�: " << car.speed << endl << endl;
//}
//
//// car�� ���� ������ �ϹǷ� �׳� Car�� �����ڸ� ����� �Ϳ� ����!
//void accel(Car &car) {
//	if (car.fuel <= 0) {
//		return;
//	} else {
//		car.fuel -= FUEL_STEP;
//	}
//
//	if (car.speed + ACC_STEP >= MAX_SPD) {
//		car.speed = MAX_SPD;
//	} else {
//		car.speed += ACC_STEP;
//	}
//}
//
//void stop(Car &car) {
//	if (car.speed < BRK_STEP) {
//		car.speed = 0;
//	} else {
//		car.speed -= BRK_STEP;
//	}
//}
//
//int main(void) {
//	Car A = { "A", 100, 0 };
//	accel(A);
//	accel(A);
//	showCarStatus(A);
//	stop(A);
//	showCarStatus(A);
//
//	Car B = { "B", 100, 0 };
//	accel(B);
//	stop(B);
//	showCarStatus(B);
//
//	return 0;
//}