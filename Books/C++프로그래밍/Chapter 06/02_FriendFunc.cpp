///************
//<주소>		: p252
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
//class Point; // class 이름을 먼저 선언
//
//class PointOP {
//private:
//	int opcnt;
//
//public:
//	PointOP() : opcnt(0) { }
//	Point pointAdd(const Point&, const Point&); // 함수 원형 선언
//	Point pointSub(const Point&, const Point&); // 함수 원형 선언
//	~PointOP() {
//		cout << "Operation time: " << opcnt << endl;
//	}
//};
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x, int y) : x(x), y(y) { }
//	friend Point PointOP::pointAdd(const Point&, const Point&); // 함수 원형에 대해 friend 선언
//	friend Point PointOP::pointSub(const Point&, const Point&); // 함수 원형에 대해 friend 선언
//	friend void print(const Point&); // 함수에 대한 선언과 동시에 friend 선언
//};
//
//Point PointOP::pointAdd(const Point &p1, const Point &p2) {
//	opcnt++;
//	return Point(p1.x + p2.x, p1.y + p2.y); // Point에서 이 함수에 대해 friend 선언을 했기 때문에 private 접근 가능 (근데 왜 오류 표시??)
//}
//
//Point PointOP::pointSub(const Point &p1, const Point &p2) {
//	opcnt++;
//	return Point(p1.x - p2.x, p1.y - p2.y); // Point에서 이 함수에 대해 friend 선언을 했기 때문에 private 접근 가능
//}
//
//void print(const Point& p) {
//	cout << "(" << p.x << ", " << p.y << ")" << endl;
//}
//
//int main(void) {
//	Point p1(1, 2);
//	Point p2(2, 4);
//	PointOP op;
//
//	print(op.pointAdd(p1, p2));
//	print(op.pointSub(p1, p2));
//	return 0;
//}