///************
//<�ּ�>		: p460
//**********
//<�ذ���>	:
//
//BoundArray& operator[](int index) const
//���� const �Լ��� �����ε� ���� �ʾ�����,
//const BoundArray ��ü�� arr[i]�� ������ �Ұ����ϴ�.
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
//@class	BoundArray
//@brief	�迭�� ������ �� ��踦 �˻��ϴ� Array
//Java�� �⺻ Array�� ����ϰ� ������
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
//	@param idx ������ index
//	@return	��ȯ���� int&�̱� ������, ���� �������� �� �� �ƴ϶� �������� ����!!
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
//	const ������ �ִ� arr���� arr[i]�� �Ұ����ϴ�!
//	==> ���� �迭 ����, ������ ���ε��� �����ε��� �ؾ���!
//	@param arr const ������ ���� �Ϳ� ����
//*/
//void printAll(const BoundArray &arr) {
//	for (int i = 0; i < arr.length; i++) {
//		//cout << arr[i] << endl;  operator[] �Լ��� const�� �ƴϱ� ������ ������ ����!
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