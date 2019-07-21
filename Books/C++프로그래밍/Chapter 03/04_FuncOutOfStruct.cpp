///************
//<주소>		: p118
//**********
//<해결방안>	:
//
//함수의 원형 선언은 struct 내부에 두고,
//그 정의는 구조체 밖에서 한다.
//
//이것으로 인해 구조체를 처음 봤을 때 "변수정보", "함수정보"가 한 눈에 들어와 가독성이 좋아진다.
//
//**********
//<오답노트>	:
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
//// C++에서 struct는 class의 일종으로 간주된다. (struct 키워드 대신 class 사용하면 됨) (다만 Car a = {};로 선언하지 못하게 됨)
//// 따라서 struct를 class라고 표현해도 틀리지 않는다.
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
//// 함수의 원형은 구조체 내부에 놓고,
//// 그 정의는 구조체 밖에서 한 모습
//// 가독성이 높아진다.
//// 함수를 정의할 때는 Car::을 붙여 Car의 함수임을 명시해야 한다.
//void Car::showCarStatus() {
//	cout << "----- status -----" << endl;
//	cout << "소유자ID: " << gamerID << endl;
//	cout << "연료: " << fuel << endl;
//	cout << "속도: " << speed << endl << endl;
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