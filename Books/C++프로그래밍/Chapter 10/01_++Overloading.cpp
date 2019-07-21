//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	Point& operator++() {
//		x++;
//		y++;
//		return *this;
//	}
//	friend Point& operator--(Point &op);
//};
//
//Point& operator--(Point &op) {
//	op.x--;
//	op.y--;
//	return op;
//}
//
//int main() {
//	Point p(1, 2);
//	// ++이 p 뒤에 오면 컴파일 에러 발생
//	p.print();
//	++p;
//	p.print();
//	--p;
//	p.print();
//
//	// p.operator++();을 수행 후 반환된 참조자(객체=p)에 또다시 operator++();을 수행
//	// 결론은 같은 객체에 ++을 두 번 수행
//	// 만약 p.operator++();이 객체의 참조가 아닌 임시객체를 반환한다면, 그 다음 ++은 임시 객체에 수행될 것이고, 결국 p에는 1번의 ++밖에 안 될 것이다. 
//	++(++p);
//	p.print();
//	// operator--(p);를 수행 후 반환된 참조자(객체=p)에 또다시 operator--(p);를 수행
//	--(--p);
//	p.print();
//}