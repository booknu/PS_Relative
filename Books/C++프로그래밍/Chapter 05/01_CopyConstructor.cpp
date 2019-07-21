///************
//<주소>		: p216
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
//	int num1, num2;
//
//public:
//	Class(int n1, int n2) : num1(n1), num2(n2) { }
//	// 복사 생성자
//	Class(const Class &another) : num1(another.num1), num2(another.num2) {
//		cout << "called Class(Class &another)" << endl;
//	}
//	void print() {
//		cout << num1 << endl << num2 << endl;
//	}
//};
//
//int main(void) {
//	Class c1(100, 200);
//	cout << "생성 및 초기화 직전" << endl;
//	Class c2 = c1; // Class c2(c1); 으로 변환됨!
//	cout << "생성 및 초기화 직후" << endl;
//	c2.print();
//
//	return 0;
//}