///************
//<�ּ�>		: p256
//**********
//<�ذ���>	:
//Ư�� Class�������� ���� ������ �ʿ��� ��Ȳ.
//
//aaaCnt, bbbCnt�� Ŭ���� �������� �ʿ��� ���������ε�, ������ �������� �־ ������
//���� static ���� ����(Ŭ���� ����)�� �ʿ�
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//int aaaCnt = 0; // Ŭ���� �������� �ʿ��ѵ�, ������ �������� �־ ����!
//int bbbCnt = 0;
//
//class AAA {
//public:
//	AAA() {
//		cout << ++aaaCnt << "��° AAA ��ü ����" << endl;
//	}
//};
//
//class BBB {
//public:
//	BBB() {
//		cout << ++bbbCnt << "��° BBB ��ü ����" << endl;
//	}
//	BBB(BBB &another) {
//		cout << ++bbbCnt << "��° BBB ��ü ����" << endl;
//	}
//};
//
//int main(void) {
//	AAA a1;
//	AAA a2;
//
//	BBB b1;
//	BBB b2 = b1;
//	BBB();
//
//	return 0;
//}