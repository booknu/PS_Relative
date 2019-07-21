/************
<�ּ�>		: p132 - 3�� ���� �� �������
**********
<�ذ���>	:
02_Car.h���� init, showCarStatus�� inline �Լ��� ����
����ο� ���� ������ ���ǵǾ�� �Ѵ�.
(inline �Լ��� ��ó���Ⱑ ó���ϹǷ� ���� ���Ͽ� �־�� ��!)

**********
<�����Ʈ>	:

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

	// inline �Լ��� ����ο� ���� ���Ͽ�!
	inline void Car::init(char *ID, int fuel) {
	strcpy_s(Car::gamerID, CAR_CONST::ID_LEN, ID);
	Car::fuel = fuel;
	Car::speed = 0;
	}

	inline void Car::showCarStatus() {
	cout << "----- status -----" << endl;
	cout << "������ID: " << gamerID << endl;
	cout << "����: " << fuel << endl;
	cout << "�ӵ�: " << speed << endl << endl;
	}
}
#endif