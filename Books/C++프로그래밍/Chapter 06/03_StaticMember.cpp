///************
//<�ּ�>		: p259
//**********
//<�ذ���>	:
//Ư�� Class�������� ���� ������ �ʿ��� ��Ȳ.
//
//���� Class���� cnt�� static ���� ������ ����Ǿ�
//���α׷� ���� �� �� �� �� �޸𸮿� �Ҵ��. (�ʱ�ȭ�� ���� ����)
//���α׷��� ����� ������ ������� ����
//
//static ��� ������ static �����ʹ� �ٸ��� �ʱ�ȭ�� �ؾ���.
//static ������ �ڵ����� 0���� �ʱ�ȭ ������,
//static ��� ������ ����� ������ Ư�� ������ �ʱ�ȭ �ϸ� ��ü�� ������ ������ �� ������ �ٲ�.
//���� ��ü �ܺο���
//int ClassName::var = default; �� ���� �ʱ�ȭ�� �ؾ� ��
//==> �� ������ �ǹ̴� ClassName�� static ���� var�� �޸𸮿� �Ҵ�� �� default ������ �ʱ�ȭ �϶�� ��
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class AAA {
//private:
//	static int cnt; // static ��� ���� (���� ���⼭ �ʱ�ȭ �ϸ� ��ü�� ������ ������ �� ������ �ʱ�ȭ ��)
//public:
//	AAA() {
//		static int cnt2;
//		cout << ++cnt << "��° AAA ��ü ����" << endl;
//	}
//};
//int AAA::cnt = 0; // static ��� ������ �ʱ�ȭ (AAA::cnt�� �޸𸮿� �Ҵ�� �� 0���� �ʱ�ȭ �϶�)
//
//class BBB {
//private:
//	static int cnt; // static ��� ����
//public:
//	BBB() {
//		cout << ++cnt << "��° BBB ��ü ����" << endl;
//	}
//	BBB(BBB &another) {
//		cout << ++cnt << "��° BBB ��ü ����" << endl;
//	}
//};
//int BBB::cnt = 0; // static ��� ������ �ʱ�ȭ
//
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