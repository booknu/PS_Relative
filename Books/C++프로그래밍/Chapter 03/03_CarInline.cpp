/************
<�ּ�>		: p133 - 3�� ���� �� Car ���� ����
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <cstring>
#include "03_CarInline.h" // Car.h�� ����� ���� ������
using namespace std;
using namespace carInline;

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
