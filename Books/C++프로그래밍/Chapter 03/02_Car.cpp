/************
<주소>		: p129 - 3개의 File 중 Car 정의 파일
**********
<해결방안>	:
3개로 분할된 파일 중 Car의 정의파일

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include "02_Car.h" // Car.h에 선언된 것을 구현함
using namespace std;
using namespace carNormal;

void Car::init(char *ID, int fuel) {
	strcpy_s(Car::gamerID, CAR_CONST::ID_LEN, ID);
	Car::fuel = fuel;
	Car::speed = 0;
}

void Car::showCarStatus() {
	cout << "----- status -----" << endl;
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료: " << fuel << endl;
	cout << "속도: " << speed << endl << endl;
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
