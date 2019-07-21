///************
//<주소>		: p183
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//// AAA 클래스에서 생성자를 명시적으로 선언하지 않았지만, AAA 객체를 생성할 때 묵시적으로 default 생성자가 호출됨
//// 이것은 new로 heap에 객체를 할당할 때도 마찬가지
//// but, malloc 사용시에는 그냥 AAA 객체의 크기만큼만 할당하는 것이기 때문에 생성자 호출X
//class AAA {
//public:
//	AAA() {
//		cout << "비어있는 객체" << endl;
//	}
//
//	void print() {
//		cout << "AAA 클래스" << endl;
//	}
//};
//
//class BBB {
//private:
//	AAA &ref; // 객체를 멤버로 가질 때 참조자로 선언 가능 (멤버 이니셜라이저 사용시)
//	const int &constNum; // 상수도 초기화 가능 (멤버 이니셜라이저 사용시)
//
//public:
//	BBB(AAA &ref, const int &n)
//		:ref(ref), constNum(n) {
//		// 상수는 물론 참조자도 초기화 가능!
//	}
//
//	void print() {
//		ref.print();
//		cout << "AND" << endl;
//		cout << "BBB 클래스의 num: " << constNum << endl;
//	}
//};
//
//int main(void) {
//	AAA obj1;
//	BBB obj2(obj1, 100);
//	obj2.print();
//
//	return 0;
//}