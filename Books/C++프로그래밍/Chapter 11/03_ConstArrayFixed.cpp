///************
//<�ּ�>		: p461
//**********
//<�ذ���>	:
//
//BoundArray& operator[](int index) const�� ���������,
//const BoundArray ��ü�� []�� ������ ����������. (but, �� ���� ���ٸ� ����)
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
//	Java�� �⺻ Array�� ����ϰ� ������
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
//		const Ű���尡 ������ ���� ���� ����.
//		const Ű���尡 �� ���� BoundArray ��ü���� ���� ����
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
//		const Ű���尡 ������ ���� ���� ����.
//		const Ű���尡 ���� BoundArray ��ü���� ���� ����
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
//	~BoundArray() {
//		delete[] arr;
//	}
//};
//
///*
//	const ������ �ִ� arr�̴ϱ� arr[i]�� ȣ���ϸ� operator[]() const �� ȣ��ȴ�.
//	��, ������ �� �� ���� ���ٸ� �����ϴ�.
//	@param arr const ������ ���� �Ϳ� ����
//*/
//void printAll(const BoundArray &arr) {
//	for (int i = 0; i <= arr.length; i++) {
//		cout << arr[i] << endl;  // operator[] �Լ��� const�� �̱� ������ ����! (���ٸ� ����)
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