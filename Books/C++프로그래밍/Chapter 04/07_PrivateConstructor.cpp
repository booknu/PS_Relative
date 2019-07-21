///************
//<주소>		: p186
//**********
//<해결방안>	:
//생성자는 public 뿐 아니라 private으로도 사용 가능
//이 때는 객체 내부에서만 사용 가능.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Obj {
//private:
//	const int num;
//
//public:
//	// public 생성자
//	Obj() : num(0) {
//
//	}
//	
//	Obj& createObject(int n) const {
//		Obj *ret = new Obj(n); // private 생성자를 통해 객체 생성 (Stack에 생성하면 함수 종료 후 사라지니까 heap에 할당)
//		return *ret; // heap에 만들어진 객체의 참조를 반환
//	}
//	
//	void print() {
//		cout << "num = " << num << endl;
//	}
//
//private:
//	// private 생성자 (객체 내부에서만 사용)
//	Obj(int n) : num(n) {
//
//	}
//};
//
//int main(void) {
//	Obj base; // public 생성자를 통해 생성
//	base.print();
//
//	Obj &o1 = base.createObject(10); // private 생성자를 통해 생성
//	o1.print();
//
//	Obj &o2 = base.createObject(20); // private 생성자를 통해 생성
//	o2.print();
//
//	// 동적할당 되었으므로 delete를 해야함
//	delete &o1; // 참조자는 이런식으로 delete
//	delete &o2;
//}