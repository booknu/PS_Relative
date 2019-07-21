///************
//<주소>		: p188
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
//	Person(char *name, int age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//		this->age = age;
//	}
//
//	void print() const {
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
//	}
//
//	~Person() {
//		delete []name; // 배열 형태로 삭제 하는 것에 주의!, 객체 소멸시 해야할 작업 명시
//		cout << "destructor called" << endl;
//	}
//};
//
//int main(void) {
//	Person man1("Lim", 18);
//	Person man2("Kim", 25);
//	man1.print();
//	man2.print();
//	// 객체들이 사라질 때 destructor 호출
//
//	return 0;
//}