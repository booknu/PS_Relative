///************
//<�ּ�>		: p161
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
//class ColdPatient {
//public:
//	void takeSinivelCap(const SinivelCap &cap) const { cap.take(); }
//	void takeSneezeCap(const SneezeCap &cap) const { cap.take(); }
//	void takeSnuffleCap(const SnuffleCap &cap) const { cap.take(); }
//};
//
//int main(void) {
//	// heap ������ ���� �Ҵ�
//	SinivelCap *sinCap = new SinivelCap();
//	SneezeCap *snzCap = new SneezeCap();
//	SnuffleCap *snfCap = new SnuffleCap();
//
//	// �̷��� �ϳ��� ����� �ϴ� ���� ������ �������� �����
//	// ĸ��ȭ�� ������
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