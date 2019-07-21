///************
//<주소>		: p283
//**********
//<해결방안>	:
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
//	// 부모 class에 virtual 키워드를 사용하지 않으면 Person a = new UnivStudent();와 같이 선언되었을 때
//	// UnivStudent의 소멸자가 호출되지 않음
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
//	// Person(age, name)으로 부모 생성자를 통해 부모의 상태 변수들을 초기하는 것에 집중!
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