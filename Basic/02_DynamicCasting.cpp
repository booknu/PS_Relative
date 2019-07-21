/************
<주소>		: p635
**********
<해결방안>	:

[ 사용조건 ]
Derive -> Base

[ 대상 ]
포인터형, 참조자형

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Car {
private:
	int fuel;

public:
	Car(int f) : fuel(f) { }
	void print() { cout << "fuel: " << fuel << endl; }
};

class Truck : public Car {
private:
	int weight;

public:
	Truck(int f, int w) : Car(f), weight(w) { }
	void print() {
		Car::print();
		cout << "weight: " << weight << endl;
	}
};

class Main {
public:
	static int main() {
		// 컴파일 에러 (Base -> Derived)
//		Car *c1 = new Truck(80, 200);
//		Truck *t1 = dynamic_cast<Truck*>(c1);

		// 컴파일 에러 (Base -> Derived)
//		Car *c2 = new Car(120);
//		Truck *t2 = dynamic_cast<Truck*>(c2);

		// OK! (Derived -> Base)
		Truck *t3 = new Truck(70, 150);
		Car *c3 = dynamic_cast<Car*>(t3);

		return 0;
	}
};