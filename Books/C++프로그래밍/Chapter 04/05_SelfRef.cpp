///************
//<주소>		: p200
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class SelfRef {
//private:
//	int num;
//
//public:
//	SelfRef(int num) : num(num) {
//		cout << "객체 생성 (num = " << this->num << ')' << endl;
//	}
//
//	SelfRef& adder(int n) {
//		num += n;
//		return *this; // 객체 자신을 참조할 수 있는 참조 정보 반환
//	}
//
//	SelfRef& showTwoNum() {
//		cout << num << endl;
//		return *this;
//	}
//};
//
//int main(void) {
//	SelfRef obj(3);
//	SelfRef &ref = obj.adder(2);
//
//	obj.showTwoNum();
//	ref.showTwoNum();
//
//	ref.adder(1).showTwoNum().adder(2).showTwoNum(); // adder, showTwoNum은 각각 자기 자신의 참조를 반환하므로 연이어서 .을 통해 객체 연산 가능
//	return 0;
//}