///************
//<�ּ�>		: p465
//**********
//<�ذ���>	:
//
//"��ü ������"�� �迭�� ����� �����.
//�� ����� �ַ� ���� (����, ���� ���� �Ű� �� �ᵵ �Ǽ�)
//==> typedef�� ���� "��ü ������"�� �ϳ��� �ڷ������� �����ϸ� �������� ������
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
//// typedef�� ���� Point*�� �ٸ� �̸����� �ҷ���
//// �迭�� ������ �� "n���� ��ü �迭" ����, "n-1���� ��ü �������� �迭"���� ���� �˰� ����
//typedef Point* POINT_PTR;
//
///*
//	@class	BoundArray
//	@brief	�迭�� ������ �� ��踦 �˻��ϴ� Array
//			"��ü�� ������"�� �迭�̴�.
//*/
//class BoundArray {
//private:
//	POINT_PTR *arr; // ���� ����� "Point�� ������"�� ����
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new POINT_PTR[len];
//	}
//	/*
//		��ȯ���� POINT_PTR&�� �ٲ�
//		@param idx ������ index
//		@return	Point& �̹Ƿ� ����, ���� ��� ����!
//	*/
//	POINT_PTR& operator[](int idx) {
//		if (idx < 0 || idx >= length) {
//			cout << "Exception: ArrayIndexOutOfBoundException: " << idx << endl;
//			exit(1);
//		} else {
//			return arr[idx];
//		}
//	}
//	/*
//		��ȯ���� POINT_PTR�� �ٲ�
//		@param idx ������ index
//		@return Point �̹Ƿ� ���ٸ� ����!
//	*/
//	POINT_PTR operator[](int idx) const {
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
//	// "��ü ������"�� �迭�̹Ƿ� �����͸� �迭 ���ҿ� �־���� ��
//	arr[0] = new Point(3, 4);
//	arr[1] = new Point(5, 6);
//	arr[2] = new Point(7, 8);
//
//	for (int i = 0; i < arr.length; i++) {
//		cout << arr[i] << endl;
//	}
//	for (int i = 0; i < arr.length; i++) {
//		delete arr[i];
//	}
//}