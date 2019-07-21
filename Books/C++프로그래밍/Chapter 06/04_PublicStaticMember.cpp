//#include <iostream>
//using namespace std;
//
//class AAA {
//public:
//	static int cnt; // public으로 static 멤버 변수 선언
//
//public:
//	AAA() {
//		cnt++;
//	}
//};
//int AAA::cnt = 0; // static 멤버 변수 초기화
//
//int main() {
//	cout << AAA::cnt << "번째 AAA 객체 생성" << endl;
//	AAA a1;
//	AAA a2;
//
//	cout << AAA::cnt << "번째 AAA 객체 생성" << endl; // public static 멤버 변수는 이렇게 접근 가능
//	cout << a1.cnt << "번째 AAA 객체 생성" << endl; // public static 멤버 변수는 이렇게 접근 가능 but 안 좋은 방법
//	cout << a2.cnt << "번째 AAA 객체 생성" << endl; // public static 멤버 변수는 이렇게 접근 가능 but 안 좋은 방법
//}