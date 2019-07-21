///************
//<주소>		: p232
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
//class Class {
//private:
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class(Class &another) : num(another.num) {
//		cout << "called copy constructor: Class(Class &another)" << endl;
//	}
//	Class& add(int operand) {
//		cout << "add(" << operand << ")" << endl;
//		num += operand;
//		return *this;
//	}
//	void print() {
//		cout << "num = " << num << endl;
//	}
//};
//
//Class objReturnFunc(Class obj) {
//	cout << "return 이전" << endl;
//	return obj;
//}
//
//int main(void) {
//	Class c(100);
//	objReturnFunc(c).add(30).print(); // 함수가 호출되며 인자를 복사하며 생성자 호출 한 번,
//									  // 반환 값을 복사하며 생성자 호출 한 번
//	c.print();
//
//	return 0;
//}