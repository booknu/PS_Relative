///************
//<주소>		: p220
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
//	explicit Class(const Class &another) : num(another.num) { } // explicit으로 묵시적 변환이 일어나지 않음!
//	void print() { cout << num << endl; }
//};
//
//int main(void) {
//	Class c1(100);
//	// Class c2 = c1; 은 explicit 때문에 불가!
//	Class c2(c1);
//	c2.print();
//}