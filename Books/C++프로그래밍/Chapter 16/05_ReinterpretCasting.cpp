/************
<�ּ�>		: p642
**********
<�ذ���>	:

[ ������� ]
��� Ÿ��

[ ��� ]
��� ���

[ ��� �� ]
1. ������ ���� 1byte �� �����ϰ� ���� ��
2. �ּҰ�(*)�� int�� ��ȯ�ϰ� ���� ��
3. int�� �ּҰ�(*)���� ��ȯ�ϰ� ���� ��


**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		//// ������ ���� Ư�� byte ������ ���� ����!
		int n = 0x010203; // 16���� = 4bit
		char *ptr = reinterpret_cast<char*>(&n); // char* ptr�� 1byte ������ ���� ����

		for (int i = 0; i < sizeof(n); i++) {
			// char* �����Ϳ� ������ �ϸ� 1byte�� ����
			cout << static_cast<int>(*(ptr + i)) << endl;
		}


		int num = 72;
		int *iptr = &num;

		//// �ּҰ�(*)�� int�� ��ȯ ����!
		int addr = reinterpret_cast<int>(iptr); // �ּҰ�(*)�� ������ ��ȯ ����!
		cout << "addr: " << addr << endl;

		//// int�� �ּҰ�(*)���� ��ȯ ����!
		int* rptr = reinterpret_cast<int*>(addr);
		cout << "value: " << *rptr << endl;

		return 0;
	}
};