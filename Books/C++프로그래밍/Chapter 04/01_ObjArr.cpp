///************
//<주소>		: p192
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
//	Person arr[3]; // 배열 선언 시 공간이 확보되고, 바로 생성자를 불러 초기화 됨
//	char namestr[100];
//	char *strptr;
//	int age;
//	int len;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "이름: ";
//		cin >> namestr;
//		cout << "나이: ";
//		cin >> age;
//
//		// new를 통해 heap에 문자열 메모리 할당.
//		// 이렇게 밖에서 동적할당을 하고, 다른 곳에서 해제를 하는 것은 좋지 않음
//		// 따라서 여기서 그냥 name을 인자로 넘기고, 그것을 복사해 동적할당 하는 것은 안에서 하는게 좋음
//		len = strlen(namestr) + 1;
//		strptr = new char[len];
//		strcpy_s(strptr, len, namestr);
//
//		arr[i].setPerson(strptr, age);
//
//		// arr[i].setPerson(namestr, age); // 이렇게 하면 안 되는 이유: namestr의 같은 메모리 주소에 계속 새로운 입력이 들어옴.
//										   // 따라서 new를 통해 각각 문자열을 heap에 생성해 그 주소를 넘겨주는게 맞음
//	}
//
//	for (int i = 0; i < 3; i++) {
//		arr[i].print();
//	}
//}