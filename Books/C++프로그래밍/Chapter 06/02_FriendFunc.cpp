///************
//<�ּ�>		: p252
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
//class Point; // class �̸��� ���� ����
//
//class PointOP {
//private:
//	int opcnt;
//
//public:
//	PointOP() : opcnt(0) { }
//	Point pointAdd(const Point&, const Point&); // �Լ� ���� ����
//	Point pointSub(const Point&, const Point&); // �Լ� ���� ����
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
//	friend Point PointOP::pointAdd(const Point&, const Point&); // �Լ� ������ ���� friend ����
//	friend Point PointOP::pointSub(const Point&, const Point&); // �Լ� ������ ���� friend ����
//	friend void print(const Point&); // �Լ��� ���� ����� ���ÿ� friend ����
//};
//
//Point PointOP::pointAdd(const Point &p1, const Point &p2) {
//	opcnt++;
//	return Point(p1.x + p2.x, p1.y + p2.y); // Point���� �� �Լ��� ���� friend ������ �߱� ������ private ���� ���� (�ٵ� �� ���� ǥ��??)
//}
//
//Point PointOP::pointSub(const Point &p1, const Point &p2) {
//	opcnt++;
//	return Point(p1.x - p2.x, p1.y - p2.y); // Point���� �� �Լ��� ���� friend ������ �߱� ������ private ���� ����
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