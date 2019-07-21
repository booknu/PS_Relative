///************
//<주소>		: p446
//**********
//<해결방안>	:
//
//operator= 함수를 오버로딩하지 않고 객체간 대입 연산을 했을 때 생기는 문제
//(얕은 복사)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
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
//	friend ostream& operator<<(ostream &os, Person &p);
//
//	~Person() {
//		cout << "called destructor" << endl;
//		delete name;
//	}
//};
//
//ostream& operator<<(ostream &os, Person &p) {
//	os << "[ " << p.name << ", " << p.age << " ]";
//	return os;
//}
//
//int main() {
//	Person p1("Lee Dong Woo", 29);
//	Person p2("Yoon Ji Yul", 22);
//	p1 = p2; // default 대입 연산자 호출 (얕은 복사)
//	cout << "p1: " << p1 << endl;
//	cout << "p2: " << p2 << endl;
//
//	// p1, p2의 destructor가 호출되면서 각각의 *name을 지우려고 할텐데,
//	// p1의 *name과 p2의 *name이 얕은 복사를 했기 때문에 같은 heap 주소를 가리킴.
//	// 따라서 같은 주소를 2번 반복해서 지우기 때문에 error 발생
//	return 0;
//}