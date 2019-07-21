///************
//<주소>		: p465
//**********
//<해결방안>	:
//
//"객체 포인터"의 배열을 만들어 사용함.
//이 방법이 주로 쓰임 (깊은, 얕은 복사 신경 안 써도 되서)
//==> typedef를 통해 "객체 포인터"를 하나의 자료형으로 선언하면 가독성이 높아짐
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
//// typedef를 통해 Point*을 다른 이름으로 불러줌
//// 배열을 저장할 때 "n차원 객체 배열" 인지, "n-1차원 객체 포인터의 배열"인지 쉽게 알게 해줌
//typedef Point* POINT_PTR;
//
///*
//	@class	BoundArray
//	@brief	배열에 접근할 때 경계를 검사하는 Array
//			"객체의 포인터"의 배열이다.
//*/
//class BoundArray {
//private:
//	POINT_PTR *arr; // 저장 대상을 "Point의 포인터"로 변경
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new POINT_PTR[len];
//	}
//	/*
//		반환형이 POINT_PTR&로 바뀜
//		@param idx 접근할 index
//		@return	Point& 이므로 접근, 수정 모두 가능!
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
//		반환형이 POINT_PTR로 바뀜
//		@param idx 접근할 index
//		@return Point 이므로 접근만 가능!
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
//	// "객체 포인터"의 배열이므로 포인터를 배열 원소에 넣어줘야 함
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