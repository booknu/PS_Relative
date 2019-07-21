///************
//<주소>		: p457
//**********
//<해결방안>	:
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
//			Java의 기본 Array와 비슷하게 구현함
//*/
//class BoundArray {
//private:
//	int *arr;
//	// 배열이란 "유일성"이 보장되야 하므로 복사, 대입이 필요 없고
//	// 아래와 같이 복사 생성자, 대입 연산자를 private으로 선언해놓으면
//	// 외부에서 사용할 수 없기 때문에 안전하지 않은 복사, 대입을 원천적으로 막을 수 있다.
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new int[len];
//	}
//	/*
//		@param idx 접근할 index
//		@return	반환형이 int&이기 때문에, 값을 가져오는 것 뿐 아니라 수정까지 가능!!
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
//int main() {
//	BoundArray arr(10);
//	for (int i = 0; i < arr.length; i++) {
//		arr[i] = i;
//	}
//	for (int i = 0; i <= arr.length; i++) {
//		cout << arr[i] << endl;
//	}
//}