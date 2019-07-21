///************
//<주소>		: p453
//**********
//<해결방안>	:
//
//멤버 변수: Obj mem
//생성자 인자: Obj &param 일 때
//
//[ 이니셜라이저를 사용한 경우 ]
//Obj mem = param;  ==> 복사 생성자
//
//[ 생성자 내부에서 초기화 한 경우 ]
//Obj mem;  ==> 생성자
//mem = param;  ==> 대입 연산자
//
//따라서 이니셜라이저를 사용하는 것이 효율적임
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
///*
//	@class	AAA
//	@brief	BBB, CCC 클래스의 멤버 객체로 쓰이기 위한 클래스
//*/
//class AAA {
//private:
//	int n;
//
//public:
//	AAA(int n = 0) : n(n) {
//		cout << "AAA const" << endl;
//	}
//	AAA(const AAA &ref) : n(ref.n) {
//		cout << "AAA copy const" << endl;
//	}
//	AAA& operator=(const AAA &copy) {
//		n = copy.n;
//		cout << "AAA operator=" << endl;
//		return *this;
//	}
//};
//
///*
//	@class	BBB
//	@brief	생성자에서 이니셜라이저를 사용함
//*/
//class BBB {
//private:
//	AAA a;
//
//public:
//	BBB(const AAA &ref) : a(ref) { }
//};
//
///*
//	@class	CCC
//	@brief	생성자에서 이니셜라이저를 사용하지 않음
//*/
//class CCC {
//private:
//	AAA a;
//
//public:
//	CCC(const AAA &ref) {
//		a = ref;
//	}
//};
//
//int main() {
//	AAA a(12);
//	cout << "----- b 선언 -----" << endl;
//	BBB b(a);
//	cout << "----- c 선언 -----" << endl;
//	CCC c(a);
//	return 0;
//}