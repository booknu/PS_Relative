///************
//<�ּ�>		: p172
//**********
//<�ذ���>	:
//Class c1(); �� ���� ��ü ������ �� �Ǵ� ����
//
//Class c1(); �� �Լ��� ������ ���� �ֱ� ����
//(Class��� ��ü�� ���纻�� ��ȯ�ϴ� c1�̶�� �Լ��� ����)
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int n1, n2;
//	
//public:
//	Class(int n1 = 0, int n2 = 0) {
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//
//	void print() {
//		cout << n1 << " " << n2 << endl;
//	}
//};
//
//int main(void) {
//	Class sc1(); // �Լ��� ���� ����
//	Class mysc = sc1(); // Class ��ü�� ��ȯ�ϴ� sc1()�̶�� �Լ��� ȣ��
//	mysc.print();
//
//	return 0;
//}
//
//// Class ��ü�� ��ȯ�ϴ� sc1()�̶�� �̸��� �Լ�
//// �̷� ��쵵 �ֱ� ������ Class sc1(); �� ���� ��ü ������ �� �� (�Լ��� ��������, ��ü �������� ���� �� ��)
//Class sc1() {
//	Class sc(20, 30);
//	return sc;
//}