// Local Define !!!! --> 이 파일을 실행하므로 Local에 선언하고 싶은거 선언
#include <cstdio>
#include <iostream>
int main(void) {
	std::cout << "TESTING START" << std::endl;
    freopen("__IO/input.txt", "r", stdin);
	while(!std::cin.eof()) system("exe\\Execute.exe");
    return 0;
}