///************
//<주소>		: p293
//**********
//<해결방안>	:
//
//01_시작 의 02_UnivStudentInherit과 같은 코드
//
//**********
//<오답노트>	:
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
//	// name 상태 변수를 동적 할당
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
//	// 부모 class에 virtual 키워드를 사용하지 않으면 Person a = new UnivStudent();와 같이 선언되었을 때
//	// UnivStudent의 소멸자가 호출되지 않음
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
//	// derived 객체가 사라지면 derived -> base 순으로 소멸자가 호출됨.
//	// but 객체의 static type이 base로 선언되어 있으면 어떨까?
//	// ( StaticType var = new DynamicType(); )
//	// ==> derived 객체의 소멸자는 호출되지 않고 base 소멸자만 호출됨! (virtual 키워드의 필요성)
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