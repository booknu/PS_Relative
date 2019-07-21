///************
//<주소>		: p449
//**********
//<해결방안>	:
//
//02번 문제를 = 연산자 오버로딩으로 해결
//operator= 의 반환형은 Obj& 임에 주의!!!
//
//[ 순 서 ]
//1. 기존 메모리 해제 (!!! 중요 !!!)
//2. 깊은 복사 실행
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
//	Person& operator=(Person &copy) {
//		// 우선 기존 name 메모리를 해제해야함 (!!! 중요 !!!)
//		delete name; // Person::~Person(); 사용해도 됨
//
//		// 깊은 복사
//		int len = strlen(copy.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, copy.name);
//		age = copy.age;
//		
//		// = 연산자 연속 실행을 위한 현재 객체 참조 반환 (이 때는 복사 생성자 실행)
//		return *this;
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