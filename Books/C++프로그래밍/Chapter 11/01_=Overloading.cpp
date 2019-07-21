///************
//<주소>		: p443
//**********
//<해결방안>	:
//
//대입 연산자와 복사 생성자는 상당히 유사한데, 그 호출 시기가 다르다
//
//[ 대입 연산자 ]
//Obj src(...);
//Obj cpy;
//cpy = src;
//==> 이미 초기화된 객체에 대입을 하면 대입 연산자 호출
//
//[ 복사 생성자 ]
//Obj src(...);
//Obj cpy = src;
//==> 초기화 하며 대입을 하면 복사 생성자 호출
//
//따라서 객체 내부에 포인터형 변수가 있다면 대입 연산자, 복사 생성자를 모두 사용자 지정 해줘야
//깊은 복사, 초기화가 가능함
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
///**
//	@class	First
//	@date	
//	@author	LimSY
//	@brief	대입 연산자(=)을 오버로딩 하지 않은 클래스
//*/
//class First {
//private:
//	int n1, n2;
//
//public:
//	First(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
//	friend ostream& operator<<(ostream &os, First &target);
//};
//
///*
//	@brief			cout << Second 객체 연산을 가능하게 만들어줌
//	@param os		ostream 객체 (ex: cout)
//	@param target	출력할 Second 객체
// */
//ostream& operator<<(ostream &os, First &target) {
//	os << target.n1 << ", " << target.n2;
//	return os;
//}
//
///**
//	@class	Second
//	@date	
//	@author	LimSY
//	@brief	대입 연산자(=)을 오버로딩한 클래스
//*/
//class Second {
//private:
//	int n3, n4;
//
//public:
//	Second(int n3 = 0, int n4 = 0) : n3(n3), n4(n4) { }
//	Second& operator=(const Second &copy) {
//		n3 = copy.n3;
//		n4 = copy.n4;
//		return *this; // a = b = c 와 같이 연속된 = 을 사용 가능하게 만들어줌
//	}
//	friend ostream& operator<<(ostream &os, Second &target);
//};
//
///*
//	@brief			cout << Second 객체 연산을 가능하게 만들어줌
//	@param os		ostream 객체 (ex: cout)
//	@param target	출력할 Second 객체
//*/
//ostream& operator<<(ostream &os, Second &target) {
//	os << target.n3 << ", " << target.n4;
//	return os;
//}
//
//int main() {
//	//////////////////////////////////////////////////////////////
//	First fsrc(111, 222);
//	First fcpy;
//	Second ssrc(333, 444);
//	Second scpy;
//
//	fcpy = fsrc; // default operator= 함수가 호출됨 (얕은 복사)
//	scpy = ssrc; // 위에서 지정한 operator= 함수가 호출됨 (깊은 복사)
//
//	cout << "fcpy: " << fcpy << endl;
//	cout << "scpy: " << scpy << endl << endl;
//
//	///////////////////////////////////////////////////////////////
//	First fob1, fob2;
//	Second sob1, sob2;
//	
//	// 여러개의 = 연산자가 연속되어 있으면 오른쪽에서부터 진행
//	fob1 = fob2 = fsrc; // default
//	sob1 = sob2 = ssrc; // 오버로딩
//
//	cout << "fob1: " << fob1 << endl;
//	cout << "fob2: " << fob2 << endl;
//	cout << "sob1: " << sob1 << endl;
//	cout << "sob2: " << sob2 << endl;
//
//	return 0;
//}