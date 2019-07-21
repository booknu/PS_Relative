///************
//<주소>		: p468 - 문제 2
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h>
//using namespace std;
//
///*
//@class	BoundArray
//@brief	배열에 접근할 때 경계를 검사하는 Array
//Java의 기본 Array와 비슷하게 구현함
//*/
//class Array {
//private:
//	int *arr;
//	Array(const Array &copy) : length(0) { }
//	Array& operator=(Array &copy) { }
//
//public:
//	const int length;
//	Array(int len) : length(len) {
//		arr = new int[len];
//	}
//	/*
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
//	~Array() {
//		delete[] arr;
//	}
//};
//
//typedef Array* ARR_PTR;
//
///*
//	@class	Array2D
//	@brief	"Array의 포인터들"의 배열을 통해 만든 2차원 배열
//			
//*/
//class Array2D {
//private:
//	ARR_PTR *arr;
//	Array2D(Array2D &copy) : length(0) {}
//	Array2D& operator=(Array2D& copy) {}
//
//public:
//	const int length;
//
//public:
//	Array2D(int row, int col) : length(row) {
//		arr = new ARR_PTR[row];
//		for (int i = 0; i < row; i++) {
//			arr[i] = new Array(col);
//		}
//	}
//
//	Array& operator[](const int row) {
//		// 반환값인 Array&에 맞춰주기 위해 Array*의 상태인 arr[row]의 값의 참조를 반환
//		return *arr[row];
//	}
//
//	~Array2D() {
//		// 배열의 원소들이 가리키는 Array 객체들을 삭제
//		for (int i = 0; i < length; i++) {
//			delete arr[i];
//		}
//		// 배열 삭제
//		delete[] arr;
//	}
//};
//
//int main() {
//	Array2D *arr = new Array2D(3, 4); // 메모리 누수 검사를 위해 heap에 할당
//									  // *arr 로 접근해야 함
//
//	// 원소 넣기
//	for (int i = 0; i < arr->length; i++) {
//		for (int j = 0; j < (*arr)[0].length; j++) {
//			(*arr)[i][j] = i * 4 + j;
//		}
//	}
//
//	// 원소들 print
//	for (int i = 0; i < arr->length; i++) {
//		for (int j = 0; j < (*arr)[0].length; j++) {
//			cout << (*arr)[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	// 주소 차이 print
//	long prev = (long)&(*arr)[0][0];
//	for (int i = 0; i < arr->length; i++) {
//		for (int j = 0; j < (*arr)[0].length; j++) {
//			long curr = (long)&(*arr)[i][j];
//			cout << curr - prev << ' ';
//			prev = curr;
//		}
//		cout << endl;
//	}
//
//	delete arr;
//
//	_CrtDumpMemoryLeaks();
//}