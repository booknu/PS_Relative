///************
//<주소>		: p194
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
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
//	}
//
//	~Person() {
//		delete[] name;
//		cout << "called destructor" << endl;
//	}
//};
//
//int main(void) {
//	Person *arr[3]; // Person이라는 객체의 포인터들의 배열 (주소들의 배열)
//	char namestr[100];
//	int age;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "이름: ";
//		cin >> namestr;
//		cout << "나이: ";
//		cin >> age;
//		arr[i] = new Person(namestr, age); // 각 배열 원소마다 동적 할당 (이 때 생성자 호출)
//	}
//
//	for (int i = 0; i < 3; i++) {
//		arr[i]->print(); // -> 연산을 통해 호출
//	}
//
//	for (int i = 0; i < 3; i++) {
//		delete arr[i]; // 각각 배열의 객체를 동적할당 했으므로 delete를 해줘야 함
//	}
//}