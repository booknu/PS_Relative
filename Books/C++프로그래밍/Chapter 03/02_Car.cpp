/************
<�ּ�>		: p129 - 3���� File �� Car ���� ����
**********
<�ذ���>	:
3���� ���ҵ� ���� �� Car�� ��������

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <cstring>
#include "02_Car.h" // Car.h�� ����� ���� ������
using namespace std;
using namespace carNormal;

void Car::init(char *ID, int fuel) {
	strcpy_s(Car::gamerID, CAR_CONST::ID_LEN, ID);
	Car::fuel = fuel;
	Car::speed = 0;
}

void Car::showCarStatus() {
	cout << "----- status -----" << endl;
	cout << "������ID: " << gamerID << endl;
	cout << "����: " << fuel << endl;
	cout << "�ӵ�: " << speed << endl << endl;
}

void Car::accel() {
	if (fuel <= 0) {
		return;
	} else {
		fuel -= CAR_CONST::FUEL_STEP;
	}

	if (speed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		speed = CAR_CONST::MAX_SPD;
	} else {
		speed += CAR_CONST::ACC_STEP;
	}
}

void Car::stop() {
	if (speed < CAR_CONST::BRK_STEP) {
		speed = 0;
	} else {
		speed -= CAR_CONST::BRK_STEP;
	}
}
