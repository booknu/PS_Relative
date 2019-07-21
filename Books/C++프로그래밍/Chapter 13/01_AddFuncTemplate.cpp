///************
//<주소>		: p528
//**********
//<해결방안>	:
//
//[ 함수 템플릿 ]
//아래와 같이 개발자가 템플릿을 지정하여 사용하는 것 (=함수의 "템플릿")
//ex) template <typename T>
//    T add(T a, T b);
//
//[ 템플릿 함수 ]
//함수 템플릿을 기반으로 컴파일러가 만들어내는 함수들 (=템플릿의 "함수")
//ex) int add<int>(int a, int b);
//    double add<double>(double a, double b);
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//// template <typename T>
//template <class T>
//T add(T a, T b) {
//	return a + b;
//}
//
//int main() {
//	cout << add<int>(15, 20)		<< endl;
//	cout << add<double>(1.1, 3.3)	<< endl;
//	cout << add<int>(3.9, 3.9)		<< endl; // int로 자동 형변환 되어서 인자로 넘어감
//	cout << add(3.9, 3.9)			<< endl; // <> 없이 호출하면 컴파일러가 알아서 자료형을 참조하여 호출!
////	cout << add(3, 3.9)				<< endl; // 이건 서로 다른 자료형이 인자로 넘어가는데, 그에 맞는 함수가 없어 Error
//
//	return 0;
//}