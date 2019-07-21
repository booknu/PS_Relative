/************
<주소>		: p632
**********
<해결방안>	:

기존 C의 형변환 연산자는 너무 강력해서 변환하지 못하는 대상이 없다.
==> 오류 확률이 높아진다.

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
		// Base 클래스의 포인터를 Derived 클래스의 포인터로 형변환 하는 것은 일반적이지 않음!

		Car *c1 = new Truck(80, 200);
		Truck *t1 = (Truck *)c1; // 문제 없는 형변환
		t1->print();

		Car *c2 = new Car(120);
		Truck *t2 = (Truck *)c2; // 문제 있는 형변환
		t2->print();

		delete t1;
		delete t2;

		// 심지어 const int* -> int* 의 변환도 가능하다! (포인터간 변환)
		const int num = 20;
		int *ptr = (int*)&num;
		*ptr = 100; // 실제로 const 값이 바뀐다!
		cout << *ptr << ' ' << num << endl;

		// int* -> float* 변환도 가능!
		float *fp = (float*)ptr;
		cout << *fp << endl; // float 값으로 해석해서 출력

		return 0;
	}
};