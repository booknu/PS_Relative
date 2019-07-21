///************
//<�ּ�>		: p225
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
//	Person(char *name, int age) : age(age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//	}
//
//	// Deep Copy�� ���� Copy Constructor
//	Person(Person &another) : age(another.age) {
//		int len = strlen(another.name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, another.name);
//	}
//
//	void print() {
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//
//	~Person() {
//		delete[] name;
//		cout << "called destructor!" << endl;
//	}
//};
//
//int main(void) {
//	Person p1("Mr. Lee", 29);
//	Person p2 = p1; // Deep Copy�� �Ǳ� ������ p1, p2�� name�� ���� heap�� �ٸ� ��ġ�� �ִ� ���ڿ��� ����Ŵ
//	p1.print();
//	p2.print();
//
//	return 0;
//}