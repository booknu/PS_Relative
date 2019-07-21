/************
<주소>		: p132 - 3개 파일 중 헤더파일
**********
<해결방안>	:
02_Car.h에서 init, showCarStatus가 inline 함수일 때는
선언부와 같은 곳에서 정의되어야 한다.
(inline 함수는 전처리기가 처리하므로 같은 파일에 있어야 함!)

**********
<오답노트>	:

*/

#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>
#include <cstring>
using namespace std;

namespace carInline {
	namespace CAR_CONST {
		enum {
			ID_LEN = 20,
			MAX_SPD = 200,
			FUEL_STEP = 2,
			ACC_STEP = 10,
			BRK_STEP = 10
		};
	}

	class Car {
	private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuel;
	int speed;
	public:
	void init(char *ID, int fuel);
	void showCarStatus();
	void accel();
	void stop();
	};

	// inline 함수는 선언부와 같은 파일에!
	inline void Car::init(char *ID, int fuel) {
	strcpy_s(Car::gamerID, CAR_CONST::ID_LEN, ID);
	Car::fuel = fuel;
	Car::speed = 0;
	}

	inline void Car::showCarStatus() {
	cout << "----- status -----" << endl;
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료: " << fuel << endl;
	cout << "속도: " << speed << endl << endl;
	}
}
#endif