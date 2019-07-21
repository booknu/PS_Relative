///************
//<주소>		: p42
//**********
//<해결방안>	:
//
//namespace안에 namespace가 삽입될 수 있음
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
//namespace parent1 {
//	int num = 2;
//
//	namespace p1child1 {
//		int num = 3;
//	}
//
//	namespace p2child2 {
//		int num = 4;
//	}
//}
//
//int main(void) {
//	cout << "P1's num: " << parent1::num << endl;
//	cout << "P1's C1's num: " << parent1::p1child1::num << endl;
//	cout << "P1's C2's num: " << parent1::p2child2::num << endl;
//}