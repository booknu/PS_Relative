/************
<주소>		: p602
**********
<해결방안>	:

함수는 여러개의 Exception 자료형에 해당하는 예외를 throw 할 수 있다.

함수의 선언부에
throw (자료형, ...)
을 추가함으로써 직관적으로 해당 함수가 던지는 예외를 알 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Main {
public:
	// 함수가 던지는 Exception 형태를 알려주는게 좋음!
	static int parseInt(char *str) throw (char, int) {
		int len = strlen(str);
		int num = 0;

		// throw Exception
		if (len != 0 && str[0] == '0') {
			throw (int)0;
		}

		for (int i = 0; i < len; i++) {
			// throw Exception
			if (str[i] < '0' || str[i] > '9') {
				throw str[i];
			}
			num += (str[i] - '0') *  (int)(pow(10, len - i - 1));
		}
		return num;
	}

	static int main() {
		char str1[100];
		char str2[100];

		while (1) {
			cout << "숫자 두 개 입력: ";
			cin >> str1 >> str2;
			// Exception 객체의 종류에 따라 catch 할 수 있음!
			try {
				int parse1 = parseInt(str1);
				int parse2 = parseInt(str2);
				cout << parse1 << " + " << parse2 << " = " << parse1 + parse2 << endl;
				break;
			} catch (char expn) {
				cout << "Error: 문자 " << expn << "이(가) 입력되었습니다." << endl;
				cout << "재입력을 해주세요." << endl << endl;
			} catch (int expn) {
				cout << "0으로 시작하는 숫자는 입력불가." << endl;
				cout << "재입력을 해주세요." << endl << endl;
			}
		}

		cout << "프로그램 종료..." << endl;

		return 0;
	}
}; 