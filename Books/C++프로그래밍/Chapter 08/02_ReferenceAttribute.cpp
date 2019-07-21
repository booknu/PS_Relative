///************
//<주소>		: p361
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
//class First {
//public:
//	void firstFunc() {
//		cout << "firstFunc();" << endl;
//	}
//	virtual void sameFunc() {
//		cout << "First's sameFunc();" << endl;
//	}
//};
//
//class Second : public First {
//public:
//	void secondFunc() {
//		cout << "secondFunc();" << endl;
//	}
//	virtual void sameFunc() {
//		cout << "Second's sameFunc();" << endl;
//	}
//};
//
//class Third : public Second {
//public:
//	void thirdFunc() {
//		cout << "thirdFunc();" << endl;
//	}
//	virtual void sameFunc() {
//		cout << "Third's sameFunc();" << endl;
//	}
//};
//
//int main() {
//	Third obj;
//	obj.firstFunc();
//	obj.secondFunc();
//	obj.thirdFunc();
//	obj.sameFunc();
//
//	Second &ref2 = obj;
//	ref2.firstFunc();
//	ref2.secondFunc();
//	ref2.sameFunc();
//
//	First &ref1 = obj;
//	ref1.firstFunc();
//	ref1.sameFunc();
//}