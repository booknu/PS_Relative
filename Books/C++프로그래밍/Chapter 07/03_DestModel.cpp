///************
//<�ּ�>		: p293
//**********
//<�ذ���>	:
//
//01_���� �� 02_UnivStudentInherit�� ���� �ڵ�
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
//	int age;
//	char *name;
//
//public:
//	// name ���� ������ ���� �Ҵ�
//	Person(int age, char *name) : age(age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//	}
//
//	void printAge() const {
//		cout << "age = " << age << endl;
//	}
//
//	void printName() const {
//		cout << "name = " << name << endl;
//	}
//
//	// �θ� class�� virtual Ű���带 ������� ������ Person a = new UnivStudent();�� ���� ����Ǿ��� ��
//	// UnivStudent�� �Ҹ��ڰ� ȣ����� ����
//	virtual ~Person() {
//		delete[] name;
//		cout << "destructor Person: delete[] name;" << endl;
//	}
//};
//
//class UnivStudent : public Person {
//private:
//	char *major;
//
//public:
//	UnivStudent(char *name, int age, char *major) : Person(age, name) {
//		int len = strlen(major) + 1;
//		this->major = new char[len];
//		strcpy_s(this->major, len, major);
//	}
//
//	void printAll() const {
//		printAge();
//		printName();
//		cout << "major = " << major << endl;
//	}
//
//	// derived ��ü�� ������� derived -> base ������ �Ҹ��ڰ� ȣ���.
//	// but ��ü�� static type�� base�� ����Ǿ� ������ ���?
//	// ( StaticType var = new DynamicType(); )
//	// ==> derived ��ü�� �Ҹ��ڴ� ȣ����� �ʰ� base �Ҹ��ڸ� ȣ���! (virtual Ű������ �ʿ伺)
//	~UnivStudent() {
//		delete[] major;
//		cout << "destructor UnivStudent: delete[] major;" << endl;
//	}
//};
//
//int main(void) {
//	UnivStudent ustd1("Lee", 22, "Computer Science");
//	ustd1.printAll();
//
//	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
//	ustd2.printAll();
//
//	return 0;
//}