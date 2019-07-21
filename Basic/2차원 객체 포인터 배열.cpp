/************
<�ּ�>		:
**********
<�ذ���>	:

2���� "��ü ������ �迭" ����, Ȱ���
Obj*�� �����ϴ� �迭 ==> Obj*�� typedef�� ���� OBJ_PTR�� �����ϴ� �͵� ���� ���

1. Obj ***arr; �������� 3���� ������ ���� (OBJ_PTR **arr;)

2. arr = new Obj**[y] �� ���� �� �Ҵ� (new OBJ_PTR*[y])

3. arr[0, y) = new Obj*[x] �� ���� �� �Ҵ� (new OBJ_PTR[x])

4. arr[y][x] = new Obj(������); �� �����Ͱ� ����Ű�� ��ü�� ���� �Ҵ� (��ü�� "������" �̹Ƿ� ���� ��ü�� �ʿ�) 

5. arr[y][x]->~~~~ �� ��ü ����

6. delete[] arr[0, y) �� �� ����

7. delete[] arr �� �� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <crtdbg.h>
using namespace std;

class Obj {
private:
	int num;

public:
	Obj(int num): num(num) { }
	
	int getNum() {
		return num;
	}
};

class Main {
public:
	// typedef�� ����ϸ� ������ ������!
	typedef Obj* OBJ_PTR;

	static int main(void) {
		int x = 5, y = 10; // y = ��, x = ��

						   // �� �Ҵ�
		Obj ***objArr = new Obj**[y]; // OBJ_PTR **objArr = new OBJ_PTR*[y];
									  // �� �Ҵ�
		for (int i = 0; i < y; i++) {
			objArr[i] = new Obj*[x]; // objARr[i] = new OBJ_PTR[x];
		}

		// 2���� �迭 �����ʹ� ���� ��ü�� ���� ����
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				objArr[i][j] = new Obj(i * x + j);
			}
		}

		// 2���� ��ü �������� �迭�� ���� print
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << objArr[i][j]->getNum() << ' ';
			}
			cout << endl;
		}

		// 2���� �迭 �����ʹ� ���� ��ü�� �޸� ����
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				delete objArr[i][j];
			}
		}

		// delete
		for (int i = 0; i < y; i++) {
			delete[] objArr[i];
		}
		delete[] objArr;

		// �޸� ���� Ȯ��
		_CrtDumpMemoryLeaks();

		return 0;
	}
};
