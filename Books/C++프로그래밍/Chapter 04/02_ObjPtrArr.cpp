///************
//<�ּ�>		: p194
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Person {
//private:
//	char *name;
//	int age;
//
//public:
//	Person(char *name, int age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//		this->age = age;
//	}
//
//	Person() {
//		name = NULL;
//		age = 0;
//		cout << "called Person();" << endl;
//	}
//
//	void setPerson(char *name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//
//	void print() const {
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//
//	~Person() {
//		delete[] name;
//		cout << "called destructor" << endl;
//	}
//};
//
//int main(void) {
//	Person *arr[3]; // Person�̶�� ��ü�� �����͵��� �迭 (�ּҵ��� �迭)
//	char namestr[100];
//	int age;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "�̸�: ";
//		cin >> namestr;
//		cout << "����: ";
//		cin >> age;
//		arr[i] = new Person(namestr, age); // �� �迭 ���Ҹ��� ���� �Ҵ� (�� �� ������ ȣ��)
//	}
//
//	for (int i = 0; i < 3; i++) {
//		arr[i]->print(); // -> ������ ���� ȣ��
//	}
//
//	for (int i = 0; i < 3; i++) {
//		delete arr[i]; // ���� �迭�� ��ü�� �����Ҵ� �����Ƿ� delete�� ����� ��
//	}
//}