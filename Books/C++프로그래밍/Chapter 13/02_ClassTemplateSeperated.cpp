///************
//<�ּ�>		: p543
//**********
//<�ذ���>	:
//
//Ŭ���� ���ø��� ����� ������ �и�
//
//������ �� ���� template<class T> �� ��������� �Ѵ�.
//���� �ش� �Լ��� Ŭ������ ����� ���� Object<T>::func() {} �� ���� �ؾ� �Ѵ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template <class T>
//class Point {
//private:
//	T x, y;
//
//public:
//	Point(T x = 0, T y = 0); // default ���� ���𿡼�
//	void print() const;
//};
//
//template <class T>
//Point<T>::Point(T x, T y) : x(x), y(y) { } // �̴ϼȶ������� ��������
//
//template <class T>
//void Point<T>::print() const {
//	cout << '(' << x << ", " << y << ')' << endl;
//}
//
//int main() {
//	Point<int> pos1(1, 4);
//	pos1.print();
//
//	Point<double> pos2(1.1, 2.2);
//	pos2.print();
//
//	Point<char> pos3('A', 'Z');
//	pos3.print();
//}