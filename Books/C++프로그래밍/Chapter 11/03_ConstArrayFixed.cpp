///************
//<주소>		: p461
//**********
//<해결방안>	:
//
//BoundArray& operator[](int index) const가 선언됐으니,
//const BoundArray 객체에 []로 접근이 가능해졌다. (but, 이 경우는 접근만 가능)
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
//	@class	BoundArray
//	@brief	배열에 접근할 때 경계를 검사하는 Array
//	Java의 기본 Array와 비슷하게 구현함
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
//		const 키워드가 없음을 통해 구분 가능.
//		const 키워드가 안 붙은 BoundArray 객체에서 접근 가능
//		@param idx 접근할 index
//		@return	int& 이므로 접근, 수정 모두 가능!
//	*/
//	int& operator[](int idx) {
//		if (idx < 0 || idx >= length) {
//			cout << "Exception: ArrayIndexOutOfBoundException: " << idx << endl;
//			exit(1);
//		} else {
//			return arr[idx];
//		}
//	}
//	/*
//		const 키워드가 있음을 통해 구분 가능.
//		const 키워드가 붙은 BoundArray 객체에서 접근 가능
//		@param idx 접근할 index
//		@return int 이므로 접근만 가능!
//	*/
//	int operator[](int idx) const {
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
//	const 선언이 있는 arr이니까 arr[i]를 호출하면 operator[]() const 가 호출된다.
//	즉, 수정은 할 수 없고 접근만 가능하다.
//	@param arr const 선언이 붙은 것에 유의
//*/
//void printAll(const BoundArray &arr) {
//	for (int i = 0; i <= arr.length; i++) {
//		cout << arr[i] << endl;  // operator[] 함수가 const가 이기 때문에 가능! (접근만 가능)
//	}
//}
//
//int main() {
//	BoundArray arr(10);
//	for (int i = 0; i < arr.length; i++) {
//		arr[i] = i;
//	}
//	printAll(arr);
//}