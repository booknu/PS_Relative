///************
//<�ּ�>		: p188
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
//	void print() const {
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//
//	~Person() {
//		delete []name; // �迭 ���·� ���� �ϴ� �Ϳ� ����!, ��ü �Ҹ�� �ؾ��� �۾� ���
//		cout << "destructor called" << endl;
//	}
//};
//
//int main(void) {
//	Person man1("Lim", 18);
//	Person man2("Kim", 25);
//	man1.print();
//	man2.print();
//	// ��ü���� ����� �� destructor ȣ��
//
//	return 0;
//}