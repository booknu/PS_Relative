///************
//<�ּ�>		: p192
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
//	Person arr[3]; // �迭 ���� �� ������ Ȯ���ǰ�, �ٷ� �����ڸ� �ҷ� �ʱ�ȭ ��
//	char namestr[100];
//	char *strptr;
//	int age;
//	int len;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "�̸�: ";
//		cin >> namestr;
//		cout << "����: ";
//		cin >> age;
//
//		// new�� ���� heap�� ���ڿ� �޸� �Ҵ�.
//		// �̷��� �ۿ��� �����Ҵ��� �ϰ�, �ٸ� ������ ������ �ϴ� ���� ���� ����
//		// ���� ���⼭ �׳� name�� ���ڷ� �ѱ��, �װ��� ������ �����Ҵ� �ϴ� ���� �ȿ��� �ϴ°� ����
//		len = strlen(namestr) + 1;
//		strptr = new char[len];
//		strcpy_s(strptr, len, namestr);
//
//		arr[i].setPerson(strptr, age);
//
//		// arr[i].setPerson(namestr, age); // �̷��� �ϸ� �� �Ǵ� ����: namestr�� ���� �޸� �ּҿ� ��� ���ο� �Է��� ����.
//										   // ���� new�� ���� ���� ���ڿ��� heap�� ������ �� �ּҸ� �Ѱ��ִ°� ����
//	}
//
//	for (int i = 0; i < 3; i++) {
//		arr[i].print();
//	}
//}