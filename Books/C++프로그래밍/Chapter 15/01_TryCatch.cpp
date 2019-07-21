/************
<주소>		: p591
**********
<해결방안>	:

예외처리를 try-catch문으로 사용했을 시

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		int n1, n2;
		cout << "두 개의 숫자 입력: ";
		cin >> n1 >> n2;

		// n2 = 0일 때 ArithmeticException 발생 (Divided by Zero)
		// try-catch문을 통해서 예외처리를 한 모습
		try {
			if (n2 == 0) {
				throw n2; // 예외 객체를 던짐
			}
			cout << "나눗셈의 몫: " << n1 / n2 << endl;
			cout << "나눗셈의 나머지: " << n1 % n2 << endl;
		} catch(int expn) {
			cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
			cout << "프로그램을 종료합니다..." << endl;
		}
		cout << "end of main" << endl;

		return 0;
	}
};