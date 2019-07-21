///************
//<주소>		: p172
//**********
//<해결방안>	:
//Class c1(); 와 같이 객체 생성이 안 되는 이유
//
//Class c1(); 은 함수의 원형일 수도 있기 때문
//(Class라는 객체의 복사본을 반환하는 c1이라는 함수의 원형)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int n1, n2;
//	
//public:
//	Class(int n1 = 0, int n2 = 0) {
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//
//	void print() {
//		cout << n1 << " " << n2 << endl;
//	}
//};
//
//int main(void) {
//	Class sc1(); // 함수의 원형 선언
//	Class mysc = sc1(); // Class 객체를 반환하는 sc1()이라는 함수를 호출
//	mysc.print();
//
//	return 0;
//}
//
//// Class 객체를 반환하는 sc1()이라는 이름의 함수
//// 이런 경우도 있기 때문에 Class sc1(); 과 같이 객체 생성은 안 됨 (함수의 원형인지, 객체 생성인지 구분 안 감)
//Class sc1() {
//	Class sc(20, 30);
//	return sc;
//}