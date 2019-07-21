///************
//<�ּ�>		: p186
//**********
//<�ذ���>	:
//�����ڴ� public �� �ƴ϶� private���ε� ��� ����
//�� ���� ��ü ���ο����� ��� ����.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Obj {
//private:
//	const int num;
//
//public:
//	// public ������
//	Obj() : num(0) {
//
//	}
//	
//	Obj& createObject(int n) const {
//		Obj *ret = new Obj(n); // private �����ڸ� ���� ��ü ���� (Stack�� �����ϸ� �Լ� ���� �� ������ϱ� heap�� �Ҵ�)
//		return *ret; // heap�� ������� ��ü�� ������ ��ȯ
//	}
//	
//	void print() {
//		cout << "num = " << num << endl;
//	}
//
//private:
//	// private ������ (��ü ���ο����� ���)
//	Obj(int n) : num(n) {
//
//	}
//};
//
//int main(void) {
//	Obj base; // public �����ڸ� ���� ����
//	base.print();
//
//	Obj &o1 = base.createObject(10); // private �����ڸ� ���� ����
//	o1.print();
//
//	Obj &o2 = base.createObject(20); // private �����ڸ� ���� ����
//	o2.print();
//
//	// �����Ҵ� �Ǿ����Ƿ� delete�� �ؾ���
//	delete &o1; // �����ڴ� �̷������� delete
//	delete &o2;
//}