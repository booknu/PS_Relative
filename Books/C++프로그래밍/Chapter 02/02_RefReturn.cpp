///************
//<�ּ�>		: p83, p85, p86
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//// ret = ref
//int& refRetFunc1(int &ref) {
//	ref++;
//	return ref;
//}
//
//// ret := ref
//int refRetFunc2(int &ref) {
//	ref++;
//	return ref;
//}
//
//void test1() {
//	cout << "----- test 1 (p83) -----" << endl;
//	int num1 = 1;
//	int &num2 = refRetFunc1(num1); // num2 = num1 = 1++ = 2
//
//	num1++; // num2 = num1 = 2++ = 3
//	num2++; // num2 = num1 = 3++ = 4
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}
//
//void test2() {
//	cout << "----- test 2 (p85) -----" << endl;
//	int num1 = 1;
//	int num2 = refRetFunc1(num1); // num2 := num1 = 1++ = 2 (���� �ٸ� �޸𸮸� ����)
//
//	num1 += 100; // num1 = 2 + 100 = 102
//	num2 += 200; // num2 = 2 + 200 = 202
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}
//
//void test3() {
//	cout << "----- test3 (p86) -----" << endl;
//	int num1 = 1;
//	int num2 = refRetFunc2(num1); // num2 := num1 = 1++ = 2 (���� �ٸ� �޸𸮸� ����)
//	// int &num2 = refRetFunc2(num1) �� �Ұ�! (return�ϴ� ���� �����ڰ� �ƴϰ�, �װ��� �� �� ���ǰ� ������� ����)
//
//	num1 += 100; // num1 = 2 + 100 = 102
//	num2 += 200; // num2 = 2 + 200 = 202
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}
//
//int main(void) {
//	test1();
//	test2();
//	test3();
//}