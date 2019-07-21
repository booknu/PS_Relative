/************
<주소>		: p595
**********
<해결방안>	:

Exception의 전달.

Exception이 throw됐는데 그것을 처리할 try-catch문이 없다면,
Exception은 해당 함수를 호출한 영역으로 넘어가게 된다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static void divide(int n1, int n2) {
		if (n2 == 0) {
			throw n2; // 예외 객체를 던짐
		}
		cout << "나눗셈의 몫: " << n1 / n2 << endl;
		cout << "나눗셈의 나머지: " << n1 % n2 << endl;
	}

	static int main() {
		int n1, n2;
		cout << "두 개의 숫자 입력: ";
		cin >> n1 >> n2;

		try {
			// n2 = 0일 때 ArithmeticException 발생 (Divided by Zero)
			// divide 함수에서 예외가 발생하면 catch 할 수 있다.
			divide(n1, n2);
		}
		catch (int expn) {
			// divide 함수를 실행했을 때 예외가 던져지면 여기로 옴
			cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
			cout << "프로그램을 종료합니다..." << endl;
		}
		cout << "end of main" << endl;

		return 0;
	}
};