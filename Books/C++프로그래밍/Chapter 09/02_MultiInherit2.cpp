///************
//<�ּ�>		: p385
//**********
//<�ذ���>	:
//
//[ ���� ����� ������ 1 ]
//����� �������� Ŭ������ �� ���� �̸��� ����� �ִٸ�?
//==> Ŭ����::��� �������� ���� �̸��� �����������μ� �ذ� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class BaseOne {
//public:
//	void sameFunc() { cout << "Base1" << endl; }
//};
//
//class BaseTwo {
//public:
//	void sameFunc() { cout << "Base2" << endl; }
//};
//
//class MultiDerived : public BaseOne, protected BaseTwo {
//public:
//	void allFunc() {
//		BaseOne::sameFunc();
//		BaseTwo::sameFunc();
//	}
//};
//
//int main() {
//	MultiDerived m;
//	m.allFunc();
//	// m.sameFunc(); �̰� ambiguous�ϱ� ������ �Ұ�!
//	m.BaseOne::sameFunc(); // �̷��� ���� �������ָ� ����!
//}