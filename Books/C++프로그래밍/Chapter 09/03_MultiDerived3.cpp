///************
//<�ּ�>		: p386
//**********
//<�ذ���>	:
//
//[ ���� ����� ������ 2 ]
//����ϴ� �� ��ü�� Base�� ���� ��ü�Ͻ�, Base�� ����� �� �� �����ϰ� �ȴ�.
//(���� Base�� ����� ������ �� ���� �̸��� ��������� �Ѵ�.)
//==> ����ϴ� �� ��ü�� Base�� virtual ����ϰ� ������ �ذ� ����
//
//[ ���� ���� ]
//LastDerived�� Base�� 2�� ���� ����ϰ� �ȴ�.
//�� �� Base�� virtual ������� �ʾҴٸ� Base�� ����� �� �� ���ԵǾ��� ���̴�.
//���� �� ��쿡�� Base Ŭ������ �Լ� baseFunc();�� �̸������� ȣ���� �� ���Եȴ�.
//
//[ virtual ��� ]
//���� ��ӽ� ����ϴ� �������� Ŭ���� �� Base�� �����ϴ� Ŭ������ �ִٸ�,
//Base�� virtual ��������μ� ������ �����ڰ� ȣ��Ǿ� �ߺ� ���ԵǴ� ���� ���� �� �ִ�.
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
//public:
//	Base() { cout << "Base Constructor" << endl; }
//	void baseFunc() { cout << "baseFunc();" << endl; }
//};
//
//// ���� ���
//class MidDerivedOne : virtual public Base {
//public:
//	MidDerivedOne() : Base() {
//		cout << "MidDerived1 Constructor" << endl;
//	}
//	void midFunc1() {
//		baseFunc();
//		cout << "midFunc1();" << endl;
//	}
//};
//
//// ���� ���
//class MidDerivedTwo : virtual public Base {
//public:
//	MidDerivedTwo() : Base() {
//		cout << "MidDerived2 Constructor" << endl;
//	}
//	void midFunc2() {
//		baseFunc();
//		cout << "midFunc2();" << endl;
//	}
//};
//
//class LastDerived : public MidDerivedOne, public MidDerivedTwo {
//public:
//	LastDerived() : MidDerivedOne(), MidDerivedTwo() {
//		cout << "LastDerived Constructor" << endl;
//	}
//	void lastFunc() {
//		midFunc1();
//		midFunc2();
//		baseFunc();
//	}
//};
//
//int main() {
//	cout << "----- ��ü ���� �� -----" << endl;
//	LastDerived ld;
//	cout << "----- ��ü ���� �� -----" << endl;
//	ld.lastFunc();
//
//	return 0;
//}