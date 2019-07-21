///************
//<주소>		: p294 - 문제 1
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
//class Car {
//private:
//	int gas;
//
//public:
//	Car(int gas = 0) : gas(gas) { }
//	int getGas() {
//		return gas;
//	}
//};
//
//class HybridCar : public Car {
//private:
//	int elec;
//
//public:
//	HybridCar(int gas = 0, int elec = 0) : Car(gas), elec(elec) { }
//	int getElec() {
//		return elec;
//	}
//};
//
//class HybridWaterCar : public HybridCar {
//private:
//	int water;
//
//public:
//	HybridWaterCar(int gas = 0, int elec = 0, int water = 0)
//		: HybridCar(gas, elec), water(water) { }
//	void printState() {
//		cout << "gas: " << getGas() << endl;
//		cout << "elec: " << getElec() << endl;
//		cout << "water: " << water << endl << endl;
//	}
//};
//
//int main() {
//	HybridWaterCar car1(10, 200, 3000);
//	car1.printState();
//
//	HybridWaterCar car2(10, 200);
//	car2.printState();
//
//	HybridWaterCar car3(10);
//	car3.printState();
//
//	HybridWaterCar car4;
//	car4.printState();
//
//	return 0;
//}