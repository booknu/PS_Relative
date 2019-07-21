///************
//<주소>		: p107
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
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
//// C++에서는 typedef를 사용하지 않아도 struct 없이 사용 가능
//struct Car {
//	char gamerID[ID_LEN];
//	int fuel;
//	int speed;
//};
//
//// car에 대해 수정을 하지 않으므로 const를 붙인 것에 주의!
//void showCarStatus(const Car &car) {
//	cout << "----- status -----" << endl;
//	cout << "소유자ID: " << car.gamerID << endl;
//	cout << "연료: " << car.fuel << endl;
//	cout << "속도: " << car.speed << endl << endl;
//}
//
//// car에 대해 수정을 하므로 그냥 Car의 참조자를 사용한 것에 주의!
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