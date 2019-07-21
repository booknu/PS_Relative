/************
<�ּ�>		: p599
**********
<�ذ���>	:

�Լ��� ȣ���� �������� ���� �����Ͱ� ���޵Ǵ� ����

[ �� �� ]
�Լ��� ȣ���� ������ Stack Frame�� ���̴µ�,
Ư�� �Լ����� Exception�� throw �Ǹ�,
catch�� �� ������ Stack Frame�� �Ž��� �ö�´�.
�̷� ������ Unwinding �̶�� �Ѵ�.

[ catch�� �� �Ǹ�? ]
���� main������ Unwinding �Ǿ ó������ �ʴ´ٸ�,
terminate �Լ��� ȣ��Ǹ� ���α׷��� ����ȴ�.

[ Exception ��ü���� ��ġ���� ������? ]
catch�� ���� �ʰ�, �� ���� ��� Unwinding �ȴ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static void func1() {
		cout << "func1()" << endl;
		func2();
	}

	static void func2() {
		cout << "func2()" << endl;
		func3();
	}

	static void func3() {
		cout << "func3()" << endl;
		throw -1;
	}

	static int main() {
		try {
			func1();
		} catch (int e) {
			cout << "Exeption code: " << e << endl;
		}
		return 0;
	}
};