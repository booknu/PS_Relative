///************
//<주소>		: p45
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
//using namespace std; // iostream의 std라는 namespace를 사용하기 때문에 "cout, cin, endl"로 그냥 함수를 사용 가능
//
//namespace name {
//	void func(void) {
//		cout << "name's func" << endl; // std를 명시하지 않아도 됨
//	}
//	void func2(void) {
//		cout << "name's func2" << endl;
//	}
//}
//
//int main(void) {
//	using name::func; // 선언된 지역을 벗어나면 효력을 잃게 됨 (지역변수 같이)
//	func();
//	name::func2(); // name의 func2 함수는 using을 하지 않았으니까 그냥 사용은 불가능
//}