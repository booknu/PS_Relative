///************
//<�ּ�>		: p532
//**********
//<�ذ���>	:
//
//Template �Լ�, Normal �Լ��� ������ ����
//func();			: Normal �Լ� ȣ��
//func<Ÿ��>();	: Template �Լ� ȣ��
//
//��, Template �Լ��� ȣ���Ϸ��� Ÿ���� ����ϰ� ȣ���ؾ� ��
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template<typename T>
//T add(T a, T b) {
//	cout << "template" << endl;
//	return a + b;
//}
//
//int add(int a, int b) {
//	cout << "int func" << endl;
//	return a + b;
//}
//
//double add(double a, double b) {
//	cout << "double func" << endl;
//	return a + b;
//}
//
//int main() {
//	// Normal Func ȣ��
//	cout << add(1, 2)					<< endl;
//	cout << add(1.1, 2.2)				<< endl;
//	// Template Func ȣ��
//	cout << add<int>(5, 7)				<< endl;
//	cout << add<double>(10.10, 20.20)	<< endl;
//
//	return 0;
//}