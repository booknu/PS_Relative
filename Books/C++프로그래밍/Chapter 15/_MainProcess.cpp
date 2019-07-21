/**
 *	include에서 실행할 main이 들어있는 파일을 지정한 후 실행하기
 *	전역함수 중 중복되는 것이 있으면 컴파일 안 됨
 *
 *	중복되는 것이 없더라고 include 하는 파일에 전역함수가 있다면, 이미 있는 전역함수를 또 include 하는 격이기 때문에 오류남!!
 *	==> Main 클래스 안에 넣어주기
 *	==> 만약 cout << 을 오버로딩 한 것이면 friend 선언한 그 자리에서 구현해주기
 *	==> .h 파일과 .cpp 파일이 따로 있으면 괜찮은데 .h 파일에 전역함수 있으면 무조건 오류
 */
#include <crtdbg.h>
#include "OOP_Main.cpp"

/**
 *	main을 한 번이라도 수정을 해야 다른 수정 결과가 반영됨
 *	따라서 대충 ;이라도 달았다가 지우고 컴파일 실행해야 함
 */
int main() {
	Main::main();
	_CrtMemDumpAllObjectsSince(0);;
	return 0;
}