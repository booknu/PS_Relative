///************
//<�ּ�>		:
//**********
//<�ذ���>	:
//
//2���� "��ü ������ �迭" ����, Ȱ���
//
//1. Obj ***arr; �������� 3���� ������ ����
//
//2. arr = new **[y] �� ���� �� �Ҵ�
//
//3. arr[0, y) = new *[x] �� ���� �� �Ҵ�
//
//4. arr[y][x] = new Obj(������); �� �����Ͱ� ����Ű�� ��ü�� ���� �Ҵ� (��ü�� "������" �̹Ƿ� ���� ��ü�� �ʿ�) 
//
//5. arr[y][x]->~~~~ �� ��ü ����
//
//6. delete[] arr[0, y) �� �� ����
//
//7. delete[] arr �� �� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Obj {
//private:
//	int num;
//
//public:
//	Obj(int num): num(num) { }
//	
//	int getNum() {
//		return num;
//	}
//};
//
//int main(void) {
//	int x = 5, y = 10; // y = ��, x = ��
//
//	// �� �Ҵ�
//	Obj *** objArr = new Obj**[y];
//	// �� �Ҵ�
//	for (int i = 0; i < y; i++) {
//		objArr[i] = new Obj*[x];
//	}
//
//	// 2���� �迭 �����ʹ� ���� ��ü�� ���� ����
//	for (int i = 0; i < y; i++) {
//		for (int j = 0; j < x; j++) {
//			objArr[i][j] = new Obj(i * x + j);
//		}
//	}
//
//	// 2���� ��ü �������� �迭�� ���� print
//	for (int i = 0; i < y; i++) {
//		for (int j = 0; j < x; j++) {
//			cout << objArr[i][j]->getNum() << ' ';
//		}
//		cout << endl;
//	}
//
//	// delete
//	for (int i = 0; i < y; i++) {
//		delete[] objArr[i];
//	}
//	delete[] objArr;
//}