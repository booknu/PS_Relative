///************
//<주소>		: p80 - 문제 3
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include<iostream>
//
//using namespace std;
//
//void swapPtr(int *&p1, int *&p2);
//void printPtr(int *&p1, int *&p2);
//
//int main(void) {
//	int num1 = 5;
//	int *p1 = &num1;
//	int num2 = 10;
//	int *p2 = &num2;
//
//	printPtr(p1, p2);
//	swapPtr(p1, p2);
//	printPtr(p1, p2);
//}
//
//void swapPtr(int *&p1, int *&p2) {
//	int *temp = p1;
//	p1 = p2;
//	p2 = temp;
//}
//
//void printPtr(int *&p1, int *&p2) {
//	cout << "p1 = (" << *p1 << ", " << p1 << "), p2 = (" << *p2 << ", " << p2 << ")" << endl;
//}