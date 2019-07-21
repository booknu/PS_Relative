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
//	// ++�� p �ڿ� ���� ������ ���� �߻�
//	p.print();
//	++p;
//	p.print();
//	--p;
//	p.print();
//
//	// p.operator++();�� ���� �� ��ȯ�� ������(��ü=p)�� �Ǵٽ� operator++();�� ����
//	// ����� ���� ��ü�� ++�� �� �� ����
//	// ���� p.operator++();�� ��ü�� ������ �ƴ� �ӽð�ü�� ��ȯ�Ѵٸ�, �� ���� ++�� �ӽ� ��ü�� ����� ���̰�, �ᱹ p���� 1���� ++�ۿ� �� �� ���̴�. 
//	++(++p);
//	p.print();
//	// operator--(p);�� ���� �� ��ȯ�� ������(��ü=p)�� �Ǵٽ� operator--(p);�� ����
//	--(--p);
//	p.print();
//}