/************
<�ּ�>		: p615
**********
<�ذ���>	:

new ������ �� ��
�޸� ���� �Ҵ��� �����ϸ� "bad_alloc" �̶�� ���ܰ� �߻��Ѵ�.
==> �ڹ��� Heap Space Exception�� ���?

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		int n = 0;

		try {
			// ������ heap ������ �޸𸮸� �Ҵ��ϰ� �ִ�.
			// heap�� ���������� new ������ bad_alloc�� �߻���ų ���̴�.
			while (1) {
				n++;
				cout << n << "��° �Ҵ� �õ�" << endl;
				new int[10000][10000];
			}
		} catch (bad_alloc &e) {
			cout << e.what() << endl;
			cout << "�� �̻� �Ҵ� �Ұ�!" << endl;
		}

		return 0;
	}
};