///************
//<�ּ�>		: p42
//**********
//<�ذ���>	:
//
//namespace�ȿ� namespace�� ���Ե� �� ����
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