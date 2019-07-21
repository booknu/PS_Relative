///************
//<주소>		: p69
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int num1 = 1020;
//	int &num2 = num1; // num1의 공간에 num2라는 이름을 하나 더 붙인 것과 마찬가지
//
//	num2 = 3047;
//	// 변수와 그 참조자의 값 확인
//	cout << "VAL: " << num1 << endl;
//	cout << "REF: " << num2 << endl << endl;
//
//	// 변수와 그 참조자의 주소 확인
//	cout << "VAL: " << &num1 << endl;
//	cout << "REF: " << &num2 << endl << endl;
//
//	// 포인터의 경우 //
//	int *ptr1 = &num2;
//	int *&ptr2 = ptr1;
//
//	cout << "----- pointer -----" << endl;
//
//	// 포인터가 가리키는 주소
//	cout << "VAL: " << ptr1 << endl;
//	cout << "REF: " << ptr2 << endl << endl;
//
//	// 포인터가 가리키는 주소의 값
//	cout << "VAL: " << *ptr1 << endl;
//	cout << "REF: " << *ptr2 << endl << endl;
//
//	// 포인터의 주소
//	cout << "VAL: " << &ptr1 << endl;
//	cout << "REF: " << &ptr2 << endl << endl;
//
//	///// 불가능한 참조자의 경우 /////
//	//int &ref = 20;
//	//int &ref;
//	//int &ref = NULL;
//}