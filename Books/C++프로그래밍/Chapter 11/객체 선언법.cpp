///************
//<주소>		:
//**********
//<해결방안>	:
//
//참조형(&, *)이 아닌 이상 다형성을 주장하면 안 된다! (여러 오류 발생)
//초기화 할 때 뿐만 아니라,
//대입 연산자를 통해 참조형(&, *)이 아닌데 다형성을 통해 대입 연산자를 사용하면 안 된다.
//ex)
//Base b;
//Derived d;
//b = d; ==> X
//
//[ 결 론 ]
//Base b = Derived(); ==> X
//Base &ref = Derived(); ==> O
//Base b = Base(); ==> O
//
//**********
//<오답노트>	:
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
//	Base b1 = Base(); // 이 때는 Base 생성자만 실행됨 (그 결과 생긴 메모리가 b1)
//	cout << "----- after b1 -----" << endl;
//
//	// 1. Derived 생성자가 실행됨
//	// 2. 1번 안에서 Base(n1)을 따라 Base 생성자가 실행됨
//	// 3. 1, 2번을 통해 우변의 Derived(2, 3); 객체가 만들어짐 (임시 객체)
//	// 4. 3번의 객체를 Base b1의 복사 생성자를 통해 복사함
//	// 5. 임시 객체 Derived(2, 3); 을 삭제
//	// ==> 따라서 이렇게 선언해봤자 Base 용도로 밖에 쓰지 못하고, 쓸데없는 오버헤드만 붙음
//	Base b2 = Derived(2, 3); // X
//	cout << "----- after b2 -----" << endl;
//
//	// 1. Derived 생성자가 실행됨
//	// 2. 1번 안에서 Base(n1)을 따라 Base 생성자가 실행됨
//	// 3. 1, 2번을 통해 우변의 Derived(10, 20); 객체가 만들어짐 (임시 객체)
//	// 4. Base &b3 참조자가 3번 객체를 가리킴 (유효하다!)
//	// ==> 따라서 이런 방법은 유효함
//	Base &b3 = Derived(10, 20); // O
//	cout << "----- after &b3 -----" << endl;
//
//	b1.print();
//	b2.print();
//	cout << "----- end -----" << endl;
//}