///************
//<�ּ�>		: p347
//**********
//<�ذ���>	:
//
//������ �Լ��� Override �Ǿ��� ���� Static Type�� ���� �Լ��� ȣ��Ǵµ�,
//virtual Ű���带 ���� �ش� �Լ��� �����Լ��� �Ǿ��ٸ�
//Dynamic Type�� ���� �Լ��� ȣ��ȴ�!
//==> ���� �Ҹ��ڴ� �ݵ�� virtual Ű���带 ����ؾ� Dynamic Type�� ���� �Ҹ��ڸ� ȣ���ϰ� �ȴ�.
//
//���� virtual �Լ��� Override �� �Լ����� ��� �ڵ����� virtual �Լ��� �ȴ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class First {
//public:
//	virtual void myFunc() { cout << "First" << endl; }
//};
//
//class Second : public First {
//public:
//	// ����� virtual �Լ��� override �� �Լ����� ��� virtual �Լ��� �ȴ�.
//	// ���� ������ virtual Ű����� �ʿ䰡 ���� �ϴ�.
//	virtual void myFunc() { cout << "Second" << endl; }
//};
//
//class Third : public Second {
//public:
//	// ����� virtual �Լ��� override �� �Լ����� ��� virtual �Լ��� �ȴ�.
//	// ���� ������ virtual Ű����� �ʿ䰡 ���� �ϴ�.
//	virtual void myFunc() { cout << "Third" << endl; }
//};
//
//int main() {
//	Third *p3 = new Third();
//	Second *p2 = p3;
//	First *p1 = p2;
//
//	// �� ��� Dynamic Type�� Third�� ��ü�� ����Ű�� ����!
//	// ���� myFunc()�� �����Լ��̹Ƿ� Dynamic Type�� ���� Override �� �Լ��� ȣ��ȴ�.
//	p3->myFunc();
//	p2->myFunc();
//	p1->myFunc();
//
//	delete p3;
//}