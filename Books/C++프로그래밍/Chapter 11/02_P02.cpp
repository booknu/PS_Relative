///************
//<�ּ�>		: p468 - ���� 2
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h>
//using namespace std;
//
///*
//@class	BoundArray
//@brief	�迭�� ������ �� ��踦 �˻��ϴ� Array
//Java�� �⺻ Array�� ����ϰ� ������
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
//		@param idx ������ index
//		@return	int& �̹Ƿ� ����, ���� ��� ����!
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
//		@param idx ������ index
//		@return int �̹Ƿ� ���ٸ� ����!
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
//	@brief	"Array�� �����͵�"�� �迭�� ���� ���� 2���� �迭
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
//		// ��ȯ���� Array&�� �����ֱ� ���� Array*�� ������ arr[row]�� ���� ������ ��ȯ
//		return *arr[row];
//	}
//
//	~Array2D() {
//		// �迭�� ���ҵ��� ����Ű�� Array ��ü���� ����
//		for (int i = 0; i < length; i++) {
//			delete arr[i];
//		}
//		// �迭 ����
//		delete[] arr;
//	}
//};
//
//int main() {
//	Array2D *arr = new Array2D(3, 4); // �޸� ���� �˻縦 ���� heap�� �Ҵ�
//									  // *arr �� �����ؾ� ��
//
//	// ���� �ֱ�
//	for (int i = 0; i < arr->length; i++) {
//		for (int j = 0; j < (*arr)[0].length; j++) {
//			(*arr)[i][j] = i * 4 + j;
//		}
//	}
//
//	// ���ҵ� print
//	for (int i = 0; i < arr->length; i++) {
//		for (int j = 0; j < (*arr)[0].length; j++) {
//			cout << (*arr)[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	// �ּ� ���� print
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