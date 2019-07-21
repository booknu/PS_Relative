/************
<�ּ�>		: p597
**********
<�ذ���>	:

Exception�� throw �Ǵ� ������ try-catch �Ǵ� ��ġ�� �ٸ� ���

**********
<�����Ʈ>	:

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
			cout << "���� �� �� �Է�: ";
			cin >> str1 >> str2;
			try {
				int parse1 = parseInt(str1);
				int parse2 = parseInt(str2);
				cout << parse1 << " + " << parse2 << " = " << parse1 + parse2 << endl;
				break;
			} catch (char expn) {
				cout << "Error: ���� " << expn << "��(��) �ԷµǾ����ϴ�." << endl;
				cout << "���Է��� ���ּ���." << endl << endl;
			}
		}

		cout << "���α׷� ����..." << endl;

		return 0;
	}
};