///************
//<�ּ�>		: p377
//**********
//<�ذ���>	:
//
//��� �Լ��� ������ ��� �����ϴ��� �˱� ����.
//Struct�� Function Pointer�� ���� Class�� �䳻��
//
//������ ��ü�� �̿� ���� ��� �Լ��� �޸� ���� �ٸ� ������ �ְ�,
//���� ��ü�� �̸� �����ϴ� �����̴�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//typedef struct Data {
//	int data;
//
//	// �Լ� �����͸� ���� ����Լ� �䳻
//	void(*print)(Data *data); 
//	void(*add)(Data *data, int n);
//} Data;
//
//void print(Data *THIS) {
//	cout << "data: " << THIS->data << endl;
//}
//
//void add(Data *THIS, int n) {
//	THIS->data += n;
//}
//
//int main() {
//	Data o1 = { 15, print, add }; // ����ü�� ������ �� �Լ� �����͵� ���� �Ѱ���� ��
//	Data o2 = { 7, print, add };
//
//	o1.add(&o1, 17);
//	o2.add(&o2, 9);
//	o1.print(&o1);
//	o2.print(&o2);
//	return 0;
//}