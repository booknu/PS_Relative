///************
//<�ּ�>		: p283
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
//	int age;
//	char *name;
//
//public:
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
//	void printName() const{
//		cout << "name = " << name << endl;
//	}
//
//	// �θ� class�� virtual Ű���带 ������� ������ Person a = new UnivStudent();�� ���� ����Ǿ��� ��
//	// UnivStudent�� �Ҹ��ڰ� ȣ����� ����
//	virtual ~Person() {
//		delete[] name;
//	}
//};
//
//class UnivStudent : public Person {
//private:
//	char *major;
//	
//public:
//	// Person(age, name)���� �θ� �����ڸ� ���� �θ��� ���� �������� �ʱ��ϴ� �Ϳ� ����!
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
//	~UnivStudent() {
//		delete[] major;
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