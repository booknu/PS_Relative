///************
//<주소>		: p221
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
//	Person p2 = p1; // shallow copy가 되기 때문에, p1과 p2의 name은 heap의 같은 공간을 가리키게 됨.
//					// 따라서 destructor에서 delete[] name을 할 때, p1에서 지운 같은 heap의 공간을 p2에서도 지우려고 하니까 error 발생
//	p1.print();
//	p2.print();
//
//	return 0;
//}