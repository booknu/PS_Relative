///************
//<�ּ�>		: p435
//**********
//<�ذ���>	:
//
//cout << Point ������ �����ε� �����ν�
//��� �Լ� print(); ��� cout << Point ��ü << ... ������ ���� �� �� �ְ� ����
//(�ڹ��� toString(); �� ����� ���, �ٸ� ����)
//(toString()�� String�� ��ȯ������, c++�� cout << ������ ���� operator<< �Լ��� ȣ����, �� ������ ����� �ǽ���
//
//std�� ostream �ȿ� �� ����Լ��� �߰��ϴ� ���� �Ұ����ϹǷ�, �����Լ��� �����ε� �Ͽ��� �Ѵ�.
//
//���� �Լ� ���´� ostream& operator<<(ostream&, Point) �� �ȴ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) {
//		cout << "const: " << x << ", " << y << endl;
//	}
//	// �����Լ��� operator<<�� �����ε� �ϹǷ�
//	// ���ڴ� ostream&, Point�� �Ǿ�� �Ѵ�.
//	// (ȣ��� operator<<(cout, p);)
//	friend ostream& operator<<(ostream&, const Point &p);
//};
//
//ostream& operator<<(ostream& os, const Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
//int main() {
//	Point p(3, 4);
//	cout << p << endl; // ������ �̷��� Point�� ���ڷ� operator<<(cout, p); ȣ�� ����!
//	operator<<(cout, p).operator<<(endl); // �� ���� �̰Ͱ� ���� ����� �Ѵ�.
//}