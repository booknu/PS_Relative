///************
//<주소>		: p225
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
//	// Deep Copy를 위한 Copy Constructor
//	Person(Person &another) : age(another.age) {
//		int len = strlen(another.name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, another.name);
//	}
//
//	void print() {
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
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
//	Person p2 = p1; // Deep Copy가 되기 때문에 p1, p2의 name은 각각 heap의 다른 위치에 있는 문자열을 가리킴
//	p1.print();
//	p2.print();
//
//	return 0;
//}