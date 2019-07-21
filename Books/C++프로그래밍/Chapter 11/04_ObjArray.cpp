///************
//<�ּ�>		: p463
//**********
//<�ذ���>	:
//
//��ü�� �ִ� �״�� ���� ������(=)�� ���� �迭�� ����
//�� �迭�� heap�� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	friend ostream& operator<<(ostream &os, Point &p);
//};
//
//ostream& operator<<(ostream &os, Point &p) {
//	os << "(" << p.x << ", " << p.y << ")";
//	return os;
//}
//
///*
//	@class	BoundArray
//	@brief	�迭�� ������ �� ��踦 �˻��ϴ� Array
//	Java�� �⺻ Array�� ����ϰ� ������
//*/
//class BoundArray {
//private:
//	Point *arr; // ���� ����� Point�� ����
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new Point[len];
//	}
//	/*
//		��ȯ���� Point&�� �ٲ�
//		@param idx ������ index
//		@return	Point& �̹Ƿ� ����, ���� ��� ����!
//	*/
//	Point& operator[](int idx) {
//		if (idx < 0 || idx >= length) {
//			cout << "Exception: ArrayIndexOutOfBoundException: " << idx << endl;
//			exit(1);
//		} else {
//			return arr[idx];
//		}
//	}
//	/*
//		��ȯ���� Point�� �ٲ�
//		@param idx ������ index
//		@return Point �̹Ƿ� ���ٸ� ����!
//	*/
//	Point operator[](int idx) const {
//		if (idx < 0 || idx >= length) {
//			cout << "Exception: ArrayIndexOutOfBoundException: " << idx << endl;
//			exit(1);
//		} else {
//			return arr[idx];
//		}
//	}
//	~BoundArray() {
//		delete[] arr;
//	}
//};
//
//int main() {
//	BoundArray arr(3);
//	// ��ü�� ������ ��ü�� ���� ����(=)�� ��� ==> =�� ������ ����� ��
//	arr[0] = Point(3, 4);
//	arr[1] = Point(5, 6);
//	arr[2] = Point(7, 8);
//
//	for (int i = 0; i < arr.length; i++) {
//		cout << arr[i] << endl;
//	}
//}