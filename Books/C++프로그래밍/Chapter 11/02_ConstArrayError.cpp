///************
//<주소>		: p460
//**********
//<해결방안>	:
//
//BoundArray& operator[](int index) const
//같이 const 함수가 오버로딩 되지 않았으니,
//const BoundArray 객체의 arr[i]의 접근이 불가능하다.
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
///*
//@class	BoundArray
//@brief	배열에 접근할 때 경계를 검사하는 Array
//Java의 기본 Array와 비슷하게 구현함
//*/
//class BoundArray {
//private:
//	int *arr;
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new int[len];
//	}
//	/*
//	@param idx 접근할 index
//	@return	반환형이 int&이기 때문에, 값을 가져오는 것 뿐 아니라 수정까지 가능!!
//	*/
//	int& operator[](int idx) {
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
///*
//	const 선언이 있는 arr에는 arr[i]가 불가능하다!
//	==> 따라서 배열 접근, 수정을 따로따로 오버로딩을 해야함!
//	@param arr const 선언이 붙은 것에 유의
//*/
//void printAll(const BoundArray &arr) {
//	for (int i = 0; i < arr.length; i++) {
//		//cout << arr[i] << endl;  operator[] 함수가 const가 아니기 때문에 컴파일 에러!
//	}
//}
//
//int main() {
//	BoundArray arr(10);
//	for (int i = 0; i < arr.length; i++) {
//		arr[i] = i;
//	}
//	for (int i = 0; i <= arr.length; i++) {
//		cout << arr[i] << endl;
//	}
//}