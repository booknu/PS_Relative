///************
//<주소>		: p230
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
//	void print() {
//		cout << "num = " << num << endl;
//	}
//};
//
//void objCallByValue(Class obj) {
//	obj.print();
//}
//
//int main(void) {
//	Class c(100);
//	cout << "함수 호출 전" << endl;
//	objCallByValue(c); // 여기서 Class obj = c; 가 일어남 (복사 생성자) (따라서 explicit 키워드가 붙으면 불가)
//	cout << "함수 호출 후" << endl;
//
//	return 0;
//}