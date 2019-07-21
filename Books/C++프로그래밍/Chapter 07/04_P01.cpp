///************
//<주소>		: p312 - 문제 1
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
//class Rect {
//private:
//	int w, h;
//
//public:
//	Rect(int w = 0, int h = 0) : w(w), h(h) { }
//	void print() {
//		cout << "width = " << w << ", height = " << h << endl;
//		cout << "area = " << w * h << endl;
//	}
//};
//
//// square에서는 새로 생성할 멤버 변수도 필요 없고,
//// print도 재정의 할 필요가 없다.
//class Square : public Rect {
//public:
//	Square(int l = 0) : Rect(l, l) { }
//};
//
//int main() {
//	Rect rec(4, 3);
//	rec.print();
//
//	Square sq(5);
//	sq.print();
//
//	return 0;
//}