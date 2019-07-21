/************
<주소>		: p636
**********
<해결방안>	:

static_cast는 primitive type간 변환, 상속관계간 변환 만 지원
C 형변환은 모든 것을 지원

[ 사용조건 ]
Derived -> Base
Base -> Derived

[ 대상 ]
포인터형, 참조자형

[ 책임 ]
Base -> Derived 책임은 프로그래머가 져야 함
해당하는 포인터가 반환되기는 하지만, Derived에만 있는 멤버에 대해서는 어떻게 동작할지 모름

[ 따라서 ]
Derived -> Base: dynamic_cast 사용 (안정적)
Base -> Derived: static_cast 사용 (제한적으로 사용하기)

but 속도는 static_cast > dynamic_cast

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
		// OK! static: (Base -> Derived), dynamic: (Derived -> Derived)
		Car *c1 = new Truck(80, 200);
		Truck *t1 = static_cast<Truck*>(c1);
		t1->print();

		// OK! static: (Base -> Derived), dynamic: (Base -> Derived)
		// but... dynamic
		Car *c2 = new Car(120);
		Truck *t2 = static_cast<Truck*>(c2);
		t2->print();

		delete c1;
		delete c2;

		return 0;
	}
};