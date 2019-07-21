///************
//<�ּ�>		: p457
//**********
//<�ذ���>	:
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
///*
//	@class	BoundArray
//	@brief	�迭�� ������ �� ��踦 �˻��ϴ� Array
//			Java�� �⺻ Array�� ����ϰ� ������
//*/
//class BoundArray {
//private:
//	int *arr;
//	// �迭�̶� "���ϼ�"�� ����Ǿ� �ϹǷ� ����, ������ �ʿ� ����
//	// �Ʒ��� ���� ���� ������, ���� �����ڸ� private���� �����س�����
//	// �ܺο��� ����� �� ���� ������ �������� ���� ����, ������ ��õ������ ���� �� �ִ�.
//	BoundArray(const BoundArray &copy) : length(0) { }
//	BoundArray& operator=(BoundArray &copy) { }
//
//public:
//	const int length;
//	BoundArray(int len) : length(len) {
//		arr = new int[len];
//	}
//	/*
//		@param idx ������ index
//		@return	��ȯ���� int&�̱� ������, ���� �������� �� �� �ƴ϶� �������� ����!!
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