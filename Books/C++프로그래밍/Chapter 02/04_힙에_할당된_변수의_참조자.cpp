///************
//<�ּ�>		: p95
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
//int main(void) {
//	// new ���
//	int *p = new int;
//	int &ref = *p;
//	ref = 20; // �����͸� ������� �ʰ� heap�� ���� ����!
//	cout << *p << endl;
//
//	// malloc ���
//	int *p2 = (int*)malloc(sizeof(int) * 1);
//	int &ref2 = *p2;
//	ref2 = 30; // malloc�� ��쵵 ��밡��
//	cout << *p2 << endl;
//}