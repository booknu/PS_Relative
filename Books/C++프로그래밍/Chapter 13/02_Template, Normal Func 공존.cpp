///************
//<주소>		: p532
//**********
//<해결방안>	:
//
//Template 함수, Normal 함수가 공존할 때는
//func();			: Normal 함수 호출
//func<타입>();	: Template 함수 호출
//
//즉, Template 함수를 호출하려면 타입을 명시하고 호출해야 함
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template<typename T>
//T add(T a, T b) {
//	cout << "template" << endl;
//	return a + b;
//}
//
//int add(int a, int b) {
//	cout << "int func" << endl;
//	return a + b;
//}
//
//double add(double a, double b) {
//	cout << "double func" << endl;
//	return a + b;
//}
//
//int main() {
//	// Normal Func 호출
//	cout << add(1, 2)					<< endl;
//	cout << add(1.1, 2.2)				<< endl;
//	// Template Func 호출
//	cout << add<int>(5, 7)				<< endl;
//	cout << add<double>(10.10, 20.20)	<< endl;
//
//	return 0;
//}