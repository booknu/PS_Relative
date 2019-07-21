///************
//<주소>		: p198
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using std::cout;
//using std::endl;
//
//class TwoNum {
//private:
//	int num1, num2;
//
//public:
//	TwoNum(int num1, int num2) {
//		// 이런 식으로 상태변수, 지역변수의 구분 가능!
//		// this 포인터는 해당 객체의 포인터.
//		this->num1 = num1;
//		this->num2 = num2;
//	}
//
//	void print() {
//		cout << num1 << ' ' << num2 << endl;
//	}
//};
//
//int main(void) {
//	TwoNum tn(100, 200);
//	tn.print();
//
//	return 0;
//}