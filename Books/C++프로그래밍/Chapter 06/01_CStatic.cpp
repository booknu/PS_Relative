///************
//<주소>		: p255
//**********
//<해결방안>	:
//C언어에서의 static의 기능
//
//지역변수로 선언: 함수가 끝나도 소멸되지 않음
//전역변수로 선언: 선언된 파일 내에서만 참조 허용
//
//<static 변수>
//1. 선언 위치는 지역변수와 같다.
//2. 특정 선언 위치에서만 접근 가능
//3. 메모리 상에서 저장 공간은 전역변수와 같음
//4. 항상 0으로 초기화 (프로그램 시작 시 딱 한번 초기화)
//==> 이런 특성들 때문에 위와 같은 효과
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//void counter() {
//	static int cnt; // 함수에서 빠져나가도 소멸되지 않음!
//	cnt++;
//	cout << "Curr cnt: " << cnt << endl;
//}
//
//int main() {
//	for (int i = 0; i < 10; i++) {
//		counter();
//	}
//
//	return 0;
//}
