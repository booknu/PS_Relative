///************
//<�ּ�>		: p163
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class SinivelCap {
//public:
//	void take() const { cout << "�๰��" << endl; }
//};
//
//class SneezeCap {
//public:
//	void take() const { cout << "��ä���" << endl; }
//};
//
//class SnuffleCap {
//public:
//	void take() const { cout << "�ڸ�����" << endl; }
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
//	// ĸ��ȭ�� �ϸ� �ϳ��� ����� ǥ�� ����
//	// ������ ���� ������� �ʾƵ� ��
//	Contac600 contac;
//	ColdPatient *p = new ColdPatient();
//	p->takeContac600(contac);
//
//	delete p;
//}