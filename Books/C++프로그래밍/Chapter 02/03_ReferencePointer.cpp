///************
//<�ּ�>		: p73
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
//	int num = 12;
//	int *p = &num; // ������
//	int **dp = &p; // ���� ������
//
//	int &ref = num;
//	int *(&pref) = p; // int*�� ref�ε�, �װ��� int* p�� �����Ѵ�.
//	int **(&dpref) = dp; // int**�� ref�ε�, �װ��� int** dp�� �����Ѵ�.
//
//	cout << ref << ' ' << *pref << ' ' << **dpref << endl;
//}