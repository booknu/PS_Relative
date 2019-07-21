///************
//<주소>		: p347
//**********
//<해결방안>	:
//
//원래는 함수가 Override 되었을 때는 Static Type에 따라 함수가 호출되는데,
//virtual 키워드를 통해 해당 함수가 가상함수가 되었다면
//Dynamic Type에 따라 함수가 호출된다!
//==> 따라서 소멸자는 반드시 virtual 키워드를 사용해야 Dynamic Type에 따라 소멸자를 호출하게 된다.
//
//또한 virtual 함수를 Override 한 함수들은 모두 자동으로 virtual 함수가 된다.
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
//	virtual void myFunc() { cout << "First" << endl; }
//};
//
//class Second : public First {
//public:
//	// 사실은 virtual 함수를 override 한 함수들은 모두 virtual 함수가 된다.
//	// 따라서 여기의 virtual 키워드는 필요가 없긴 하다.
//	virtual void myFunc() { cout << "Second" << endl; }
//};
//
//class Third : public Second {
//public:
//	// 사실은 virtual 함수를 override 한 함수들은 모두 virtual 함수가 된다.
//	// 따라서 여기의 virtual 키워드는 필요가 없긴 하다.
//	virtual void myFunc() { cout << "Third" << endl; }
//};
//
//int main() {
//	Third *p3 = new Third();
//	Second *p2 = p3;
//	First *p1 = p2;
//
//	// 셋 모두 Dynamic Type이 Third인 객체를 가리키고 있음!
//	// 또한 myFunc()는 가상함수이므로 Dynamic Type에 따라 Override 된 함수가 호출된다.
//	p3->myFunc();
//	p2->myFunc();
//	p1->myFunc();
//
//	delete p3;
//}