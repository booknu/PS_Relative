///************
//<�ּ�>		: p263
//**********
//<�ذ���>	:
//static ��� �Լ������� static ��� ����, static ��� �Լ��� ���� ����!
//
//1. ����� class�� ��� ��ü�� ����
//2. public���� ����Ǹ�, class�� �̸��� ���� ȣ�� ����
//3. ��ü�� ����� �ƴ�!
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	static int staticNum;
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	// static ��� �Լ�
//	static void func() {
//		// cout << num << endl; �� num�� static ��� ������ �ƴ϶� �Ұ�!
//		cout << staticNum << endl;
//	}
//};
//int Class::staticNum = 10000; // static ��� ���� �ʱ�ȭ
//
//int main() {
//	Class::func(); // static ��� �Լ� ȣ��
//}