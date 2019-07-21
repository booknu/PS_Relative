///************
//<주소>		: p259
//**********
//<해결방안>	:
//특정 Class에서만의 전역 변수가 필요한 상황.
//
//각각 Class에서 cnt가 static 상태 변수로 선언되어
//프로그램 시작 시 딱 한 번 메모리에 할당됨. (초기화는 되지 않음)
//프로그램이 종료될 때까지 사라지지 않음
//
//static 멤버 변수는 static 변수와는 다르게 초기화를 해야함.
//static 변수는 자동으로 0으로 초기화 되지만,
//static 멤버 변수는 선언된 곳에서 특정 값으로 초기화 하면 객체가 생성될 때마다 그 값으로 바뀜.
//따라서 객체 외부에서
//int ClassName::var = default; 와 같이 초기화를 해야 함
//==> 이 문장의 의미는 ClassName의 static 변수 var이 메모리에 할당될 때 default 값으로 초기화 하라는 뜻
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class AAA {
//private:
//	static int cnt; // static 멤버 변수 (만약 여기서 초기화 하면 객체가 생성될 때마다 그 값으로 초기화 됨)
//public:
//	AAA() {
//		static int cnt2;
//		cout << ++cnt << "번째 AAA 객체 생성" << endl;
//	}
//};
//int AAA::cnt = 0; // static 멤버 변수의 초기화 (AAA::cnt가 메모리에 할당될 때 0으로 초기화 하라)
//
//class BBB {
//private:
//	static int cnt; // static 멤버 변수
//public:
//	BBB() {
//		cout << ++cnt << "번째 BBB 객체 생성" << endl;
//	}
//	BBB(BBB &another) {
//		cout << ++cnt << "번째 BBB 객체 생성" << endl;
//	}
//};
//int BBB::cnt = 0; // static 멤버 변수의 초기화
//
//
//int main(void) {
//	AAA a1;
//	AAA a2;
//
//	BBB b1;
//	BBB b2 = b1;
//	BBB();
//
//	return 0;
//}