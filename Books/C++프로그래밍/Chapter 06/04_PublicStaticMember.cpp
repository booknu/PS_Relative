//#include <iostream>
//using namespace std;
//
//class AAA {
//public:
//	static int cnt; // public���� static ��� ���� ����
//
//public:
//	AAA() {
//		cnt++;
//	}
//};
//int AAA::cnt = 0; // static ��� ���� �ʱ�ȭ
//
//int main() {
//	cout << AAA::cnt << "��° AAA ��ü ����" << endl;
//	AAA a1;
//	AAA a2;
//
//	cout << AAA::cnt << "��° AAA ��ü ����" << endl; // public static ��� ������ �̷��� ���� ����
//	cout << a1.cnt << "��° AAA ��ü ����" << endl; // public static ��� ������ �̷��� ���� ���� but �� ���� ���
//	cout << a2.cnt << "��° AAA ��ü ����" << endl; // public static ��� ������ �̷��� ���� ���� but �� ���� ���
//}