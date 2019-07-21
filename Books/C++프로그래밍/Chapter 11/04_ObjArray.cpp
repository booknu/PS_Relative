///************
//<주소>		: p463
//**********
//<해결방안>	:
//
//객체를 있는 그대로 대입 연산자(=)를 통해 배열에 저장
//그 배열은 heap에 있음
//
//**********
//<오답노트>	:
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
//	@brief	배열에 접근할 때 경계를 검사하는 Array
//	Java의 기본 Array와 비슷하게 구현함
//*/
//class BoundArray {
//private:
//	Point *arr; // 저장 대상을 Point로 변경
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new Point[len];
//	}
//	/*
//		반환형이 Point&로 바뀜
//		@param idx 접근할 index
//		@return	Point& 이므로 접근, 수정 모두 가능!
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
//		반환형이 Point로 바뀜
//		@param idx 접근할 index
//		@return Point 이므로 접근만 가능!
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
//	// 객체간 연산은 객체의 대입 연산(=)을 기반 ==> =을 재정의 해줘야 함
//	arr[0] = Point(3, 4);
//	arr[1] = Point(5, 6);
//	arr[2] = Point(7, 8);
//
//	for (int i = 0; i < arr.length; i++) {
//		cout << arr[i] << endl;
//	}
//}