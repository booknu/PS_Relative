///************
//<주소>		: p244
//**********
//<해결방안>	:
//const 객체에서는 const 함수만 호출 가능!
//따라서 상태 변수를 수정하지 않는 함수는 가급적 const로 선언하는게 좋음!
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class& add(int operand) {
//		num += operand;
//		return *this;
//	}
//	void print() const{
//		cout << "num = " << num << endl;
//	}
//};
//
//int main(void) {
//	const Class obj(100); // const 객체
//	// obj.add(10); 은 불가! (const 함수만 사용 가능)
//	obj.print();
//
//	return 0;
//}