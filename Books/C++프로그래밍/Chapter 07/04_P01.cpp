///************
//<�ּ�>		: p312 - ���� 1
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
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
//// square������ ���� ������ ��� ������ �ʿ� ����,
//// print�� ������ �� �ʿ䰡 ����.
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