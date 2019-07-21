/************
<주소>		: p133 - 3개 파일 중 Car 정의 파일
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include "03_CarInline.h" // Car.h에 선언된 것을 구현함
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
