///************
//<�ּ�>		: p87
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int& refRetFunc(int &n) {
//	int num = n; // num�� local
//	num += 100;
//	return num;
//}
//
//// �ǹ� ���� �Լ� (�ܼ� ȣ���)
//int notMeaningfulFunc(int a, int b, int c, int d) {
//	return 100;
//}
//
//int main(void) {
//	int n = 1;
//	int &ret = refRetFunc(n); // �����Ͻ� Warning�� ������, Error�� ���� ����
//	// �� �Լ� ȣ�� ���� �����ϸ� ret ���� 101�� ���������� ����.
//	// but �װ��� ���� Stack�� �׿��ִ� local variable�� num�� ��������� �ʾұ� ����.
//	// �̷��� �ٸ� �Լ��� ȣ���Ͽ� Stack�� ����������� �̹� ������ num���� �̻��� ������ �������
//	notMeaningfulFunc(1, 2, 3, 4);
//	cout << ret << endl;
//}