///************
//<�ּ�>		: p528
//**********
//<�ذ���>	:
//
//[ �Լ� ���ø� ]
//�Ʒ��� ���� �����ڰ� ���ø��� �����Ͽ� ����ϴ� �� (=�Լ��� "���ø�")
//ex) template <typename T>
//    T add(T a, T b);
//
//[ ���ø� �Լ� ]
//�Լ� ���ø��� ������� �����Ϸ��� ������ �Լ��� (=���ø��� "�Լ�")
//ex) int add<int>(int a, int b);
//    double add<double>(double a, double b);
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//// template <typename T>
//template <class T>
//T add(T a, T b) {
//	return a + b;
//}
//
//int main() {
//	cout << add<int>(15, 20)		<< endl;
//	cout << add<double>(1.1, 3.3)	<< endl;
//	cout << add<int>(3.9, 3.9)		<< endl; // int�� �ڵ� ����ȯ �Ǿ ���ڷ� �Ѿ
//	cout << add(3.9, 3.9)			<< endl; // <> ���� ȣ���ϸ� �����Ϸ��� �˾Ƽ� �ڷ����� �����Ͽ� ȣ��!
////	cout << add(3, 3.9)				<< endl; // �̰� ���� �ٸ� �ڷ����� ���ڷ� �Ѿ�µ�, �׿� �´� �Լ��� ���� Error
//
//	return 0;
//}