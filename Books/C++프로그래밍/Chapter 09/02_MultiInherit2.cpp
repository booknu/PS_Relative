///************
//<주소>		: p385
//**********
//<해결방안>	:
//
//[ 다중 상속의 문제점 1 ]
//상속한 여러개의 클래스들 중 같은 이름의 멤버가 있다면?
//==> 클래스::멤버 형식으로 직접 이름을 지정해줌으로서 해결 가능
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class BaseOne {
//public:
//	void sameFunc() { cout << "Base1" << endl; }
//};
//
//class BaseTwo {
//public:
//	void sameFunc() { cout << "Base2" << endl; }
//};
//
//class MultiDerived : public BaseOne, protected BaseTwo {
//public:
//	void allFunc() {
//		BaseOne::sameFunc();
//		BaseTwo::sameFunc();
//	}
//};
//
//int main() {
//	MultiDerived m;
//	m.allFunc();
//	// m.sameFunc(); 이건 ambiguous하기 때문에 불가!
//	m.BaseOne::sameFunc(); // 이렇게 직접 지정해주면 가능!
//}