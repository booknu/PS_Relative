///************
//<�ּ�>		: p183
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//// AAA Ŭ�������� �����ڸ� ��������� �������� �ʾ�����, AAA ��ü�� ������ �� ���������� default �����ڰ� ȣ���
//// �̰��� new�� heap�� ��ü�� �Ҵ��� ���� ��������
//// but, malloc ���ÿ��� �׳� AAA ��ü�� ũ�⸸ŭ�� �Ҵ��ϴ� ���̱� ������ ������ ȣ��X
//class AAA {
//public:
//	AAA() {
//		cout << "����ִ� ��ü" << endl;
//	}
//
//	void print() {
//		cout << "AAA Ŭ����" << endl;
//	}
//};
//
//class BBB {
//private:
//	AAA &ref; // ��ü�� ����� ���� �� �����ڷ� ���� ���� (��� �̴ϼȶ����� ����)
//	const int &constNum; // ����� �ʱ�ȭ ���� (��� �̴ϼȶ����� ����)
//
//public:
//	BBB(AAA &ref, const int &n)
//		:ref(ref), constNum(n) {
//		// ����� ���� �����ڵ� �ʱ�ȭ ����!
//	}
//
//	void print() {
//		ref.print();
//		cout << "AND" << endl;
//		cout << "BBB Ŭ������ num: " << constNum << endl;
//	}
//};
//
//int main(void) {
//	AAA obj1;
//	BBB obj2(obj1, 100);
//	obj2.print();
//
//	return 0;
//}