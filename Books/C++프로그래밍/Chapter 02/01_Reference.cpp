///************
//<�ּ�>		: p69
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
//	int num1 = 1020;
//	int &num2 = num1; // num1�� ������ num2��� �̸��� �ϳ� �� ���� �Ͱ� ��������
//
//	num2 = 3047;
//	// ������ �� �������� �� Ȯ��
//	cout << "VAL: " << num1 << endl;
//	cout << "REF: " << num2 << endl << endl;
//
//	// ������ �� �������� �ּ� Ȯ��
//	cout << "VAL: " << &num1 << endl;
//	cout << "REF: " << &num2 << endl << endl;
//
//	// �������� ��� //
//	int *ptr1 = &num2;
//	int *&ptr2 = ptr1;
//
//	cout << "----- pointer -----" << endl;
//
//	// �����Ͱ� ����Ű�� �ּ�
//	cout << "VAL: " << ptr1 << endl;
//	cout << "REF: " << ptr2 << endl << endl;
//
//	// �����Ͱ� ����Ű�� �ּ��� ��
//	cout << "VAL: " << *ptr1 << endl;
//	cout << "REF: " << *ptr2 << endl << endl;
//
//	// �������� �ּ�
//	cout << "VAL: " << &ptr1 << endl;
//	cout << "REF: " << &ptr2 << endl << endl;
//
//	///// �Ұ����� �������� ��� /////
//	//int &ref = 20;
//	//int &ref;
//	//int &ref = NULL;
//}