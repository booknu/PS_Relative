///************
//<주소>		: p123
//**********
//<해결방안>	:
//접근제어 지시자를 선언하지 않았을 때
//class는 private, struct는 public으로 간주.
//그 외에는 class와 struct는 동일
//
//**********
//<오답노트>	:
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
//// class와 struct의 차이점은 키워드와,
//// struct의 경우는 Car c = {}; 로 생성할 수 있는데 반해, 
//// class의 경우는 이렇게 생성하지 못하고 Constructor로만 생성이 가능하다.
//class Car {
//// class 내에서만 접근 허용
//private:
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuel;
//	int speed;
//// 어디서나 접근 허용
//public:
//	void init(char *ID, int fuel); // Constructor 역할 함수 추가
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