/************
<�ּ�>		: p632
**********
<�ذ���>	:

���� C�� ����ȯ �����ڴ� �ʹ� �����ؼ� ��ȯ���� ���ϴ� ����� ����.
==> ���� Ȯ���� ��������.

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
		// Base Ŭ������ �����͸� Derived Ŭ������ �����ͷ� ����ȯ �ϴ� ���� �Ϲ������� ����!

		Car *c1 = new Truck(80, 200);
		Truck *t1 = (Truck *)c1; // ���� ���� ����ȯ
		t1->print();

		Car *c2 = new Car(120);
		Truck *t2 = (Truck *)c2; // ���� �ִ� ����ȯ
		t2->print();

		delete t1;
		delete t2;

		// ������ const int* -> int* �� ��ȯ�� �����ϴ�! (�����Ͱ� ��ȯ)
		const int num = 20;
		int *ptr = (int*)&num;
		*ptr = 100; // ������ const ���� �ٲ��!
		cout << *ptr << ' ' << num << endl;

		// int* -> float* ��ȯ�� ����!
		float *fp = (float*)ptr;
		cout << *fp << endl; // float ������ �ؼ��ؼ� ���

		return 0;
	}
};