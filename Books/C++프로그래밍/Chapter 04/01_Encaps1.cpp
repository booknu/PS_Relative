///************
//<주소>		: p161
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
//class ColdPatient {
//public:
//	void takeSinivelCap(const SinivelCap &cap) const { cap.take(); }
//	void takeSneezeCap(const SneezeCap &cap) const { cap.take(); }
//	void takeSnuffleCap(const SnuffleCap &cap) const { cap.take(); }
//};
//
//int main(void) {
//	// heap 영역에 동적 할당
//	SinivelCap *sinCap = new SinivelCap();
//	SneezeCap *snzCap = new SneezeCap();
//	SnuffleCap *snfCap = new SnuffleCap();
//
//	// 이렇게 하나의 기능을 하는 것을 귀찮게 여러줄을 써야함
//	// 캡슐화가 무너짐
//	ColdPatient *p = new ColdPatient();
//	p->takeSinivelCap(*sinCap);
//	p->takeSneezeCap(*snzCap);
//	p->takeSnuffleCap(*snfCap);
//
//	delete sinCap;
//	delete snzCap;
//	delete snfCap;
//	delete p;
//}