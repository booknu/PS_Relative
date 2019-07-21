///************
//<주소>		: p163
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
//class SinivelCap {
//public:
//	void take() const { cout << "콧물용" << endl; }
//};
//
//class SneezeCap {
//public:
//	void take() const { cout << "재채기용" << endl; }
//};
//
//class SnuffleCap {
//public:
//	void take() const { cout << "코막힘용" << endl; }
//};
//
//class Contac600 {
//private:
//	SinivelCap sinCap;
//	SneezeCap snzCap;
//	SnuffleCap snfCap;
//	
//public:
//	void take() const {
//		sinCap.take();
//		snzCap.take();
//		snfCap.take();
//	}
//};
//
//class ColdPatient {
//public:
//	void takeContac600(const Contac600 &cap) const { cap.take(); }
//};
//
//int main(void) {
//	// 캡슐화를 하면 하나의 기능을 표현 가능
//	// 순서에 대해 고민하지 않아도 됨
//	Contac600 contac;
//	ColdPatient *p = new ColdPatient();
//	p->takeContac600(contac);
//
//	delete p;
//}