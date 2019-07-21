///************
//<주소>		: p327
//**********
//<해결방안>	:
//
//base를 상속하는 derived 클래스는
//StaticType var = DynamicType(생성자); 와 같이 선언할 수 있다.
//단, 사용할 수 있는 멤버 함수는 StaticType에 따라 결정된다. (컴파일 타임에 결정되야 하므로)
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
//public:
//	void sleep() {
//		cout << "Sleep" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	void study() {
//		cout << "Study" << endl;
//	}
//};
//
//class PartTimeStudent : public Student {
//public:
//	void work() {
//		cout << "Work" << endl;
//	}
//};
//
//int main(void) {
//	// StaticType var = DynamicType(생성자); 가 가능하다!
//	Person *a = new Student(); // 동적 할당
//	Person b = PartTimeStudent(); // 일반 할당
//	Student *c = new PartTimeStudent();
//
//	// 호출할 수 있는 함수는 Static Type에 따라 결정됨! (컴파일 타임에 결정되야 하므로)
//	a->sleep();
//	b.sleep();
//	c->study();
//
//	delete a;
//	delete c;
//}