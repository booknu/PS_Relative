/************
<주소>		: p597
**********
<해결방안>	:

Exception이 throw 되는 지역과 try-catch 되는 위치가 다른 경우

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Main {
public:
	static int parseInt(char *str) {
		int len = strlen(str);
		int num = 0;

		for (int i = 0; i < len; i++) {
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
			try {
				int parse1 = parseInt(str1);
				int parse2 = parseInt(str2);
				cout << parse1 << " + " << parse2 << " = " << parse1 + parse2 << endl;
				break;
			} catch (char expn) {
				cout << "Error: 문자 " << expn << "이(가) 입력되었습니다." << endl;
				cout << "재입력을 해주세요." << endl << endl;
			}
		}

		cout << "프로그램 종료..." << endl;

		return 0;
	}
};