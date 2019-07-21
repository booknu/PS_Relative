///************
//<�ּ�>		:
//**********
//<�ذ���>	:
//
//������(&, *)�� �ƴ� �̻� �������� �����ϸ� �� �ȴ�! (���� ���� �߻�)
//�ʱ�ȭ �� �� �Ӹ� �ƴ϶�,
//���� �����ڸ� ���� ������(&, *)�� �ƴѵ� �������� ���� ���� �����ڸ� ����ϸ� �� �ȴ�.
//ex)
//Base b;
//Derived d;
//b = d; ==> X
//
//[ �� �� ]
//Base b = Derived(); ==> X
//Base &ref = Derived(); ==> O
//Base b = Base(); ==> O
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Base {
//private:
//	int n1;
//
//public:
//	Base(int n1 = 0) : n1(n1) { cout << "Base const: " << n1 << endl; }
//	Base(Base &copy) : n1(copy.n1) { cout << "Base copy const: " << n1 << endl; }
//	Base& operator=(Base &copy) { cout << "Base oper=" << endl; }
//	virtual void print() { cout << "n1: " << n1 << endl; }
//	virtual ~Base() {
//		cout << "Base dest" << endl;
//	}
//};
//
//class Derived : public Base {
//private:
//	int n2;
//
//public:
//	Derived(int n1 = 0, int n2 = 0) : Base(n1), n2(n2) { cout << "Derived const: " << n1 << ", " << n2 << endl; }
//	Derived(Derived &copy) : Base(copy), n2(copy.n2) { cout << "Derived copy const: " << n2 << endl; }
//	Derived& operator=(Derived &copy) { cout << "Derived oper=" << endl; }
//	virtual void print() { Base::print(); cout << "n2: " << n2 << endl; }
//	virtual ~Derived() {
//		cout << "Derived dest" << endl;
//	}
//};
//
//int main() {
//	Base b1 = Base(); // �� ���� Base �����ڸ� ����� (�� ��� ���� �޸𸮰� b1)
//	cout << "----- after b1 -----" << endl;
//
//	// 1. Derived �����ڰ� �����
//	// 2. 1�� �ȿ��� Base(n1)�� ���� Base �����ڰ� �����
//	// 3. 1, 2���� ���� �캯�� Derived(2, 3); ��ü�� ������� (�ӽ� ��ü)
//	// 4. 3���� ��ü�� Base b1�� ���� �����ڸ� ���� ������
//	// 5. �ӽ� ��ü Derived(2, 3); �� ����
//	// ==> ���� �̷��� �����غ��� Base �뵵�� �ۿ� ���� ���ϰ�, �������� ������常 ����
//	Base b2 = Derived(2, 3); // X
//	cout << "----- after b2 -----" << endl;
//
//	// 1. Derived �����ڰ� �����
//	// 2. 1�� �ȿ��� Base(n1)�� ���� Base �����ڰ� �����
//	// 3. 1, 2���� ���� �캯�� Derived(10, 20); ��ü�� ������� (�ӽ� ��ü)
//	// 4. Base &b3 �����ڰ� 3�� ��ü�� ����Ŵ (��ȿ�ϴ�!)
//	// ==> ���� �̷� ����� ��ȿ��
//	Base &b3 = Derived(10, 20); // O
//	cout << "----- after &b3 -----" << endl;
//
//	b1.print();
//	b2.print();
//	cout << "----- end -----" << endl;
//}