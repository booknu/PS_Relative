/************
<�ּ�>		: p636
**********
<�ذ���>	:

static_cast�� primitive type�� ��ȯ, ��Ӱ��谣 ��ȯ �� ����
C ����ȯ�� ��� ���� ����

[ ������� ]
Derived -> Base
Base -> Derived

[ ��� ]
��������, ��������

[ å�� ]
Base -> Derived å���� ���α׷��Ӱ� ���� ��
�ش��ϴ� �����Ͱ� ��ȯ�Ǳ�� ������, Derived���� �ִ� ����� ���ؼ��� ��� �������� ��

[ ���� ]
Derived -> Base: dynamic_cast ��� (������)
Base -> Derived: static_cast ��� (���������� ����ϱ�)

but �ӵ��� static_cast > dynamic_cast

**********
<�����Ʈ>	:

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