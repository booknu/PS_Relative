///************
//<�ּ�>		:
//**********
//<�ذ���>	:
//
//3���� "��ü �迭" ����, Ȱ���
//
//1. Obj ***arr; �������� 3���� ������ ����
//
//2. arr = new Obj**[z] �� ���� ���� �ܺ� �迭 �Ҵ�
//
//3. arr[0, z) = new Obj*[y] �� ���� �߰� �迭 �Ҵ�
//
//4. arr[0, z)[0, y) = new Obj[x] �� ���� ���� ���� �迭 �Ҵ� (�� ��, 1���� ��ü �迭�� �Ҵ��ϴ� �Ͱ� �����Ƿ� ������ ȣ���)
//
//5. arr[z][y][x].~~~~ �� ��ü ����
//
//6. delete[] arr[0, z)[0, y) �� ���� ���� ���� �迭 ����
//
//7. delete[] arr[0, z) �� ���� �߰� �迭 ����
//
//8. delete[] arr �� ���� ���� �ٱ� �迭 ����
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
//	Obj() : num(-1) { } // �⺻ ������ (��ü �迭 ���� �� �ڵ� ȣ��)
//	Obj(int num) : num(num) { }
//
//	int getNum() const {
//		return num;
//	}
//
//	void setNum(int n) {
//		num = n;
//	}
//
//	~Obj() {
//		cout << num << ' ';
//	}
//};
//
//int main(void) {
//	int x = 5, y = 10, z = 3;
//
//	// z �Ҵ�
//	Obj *** objArr = new Obj**[z];
//	// y �Ҵ�
//	for (int i = 0; i < z; i++) {
//		objArr[i] = new Obj*[y];
//	}
//	// x �Ҵ�
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			objArr[i][j] = new Obj[x]; // �⺻ �����ڰ� ȣ���!
//		}
//	}
//
//	// 3���� ��ü �迭�� ���� set
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			for (int k = 0; k < x; k++) {
//				objArr[i][j][k].setNum(i * y * x + j * x + k);
//			}
//		}
//	}
//
//	// 3���� ��ü �迭�� ���� print
//	for (int i = 0; i < z; i++) {
//		cout << "<< z = " << i << " >>" << endl;
//		for (int j = 0; j < y; j++) {
//			for (int k = 0; k < x; k++) {
//				cout << objArr[i][j][k].getNum() << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//	}
//
//	cout << "[ destructor called ]" << endl;
//	// delete x
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			delete[] objArr[i][j];
//		}
//	}
//	// delete y
//	for (int i = 0; i < z; i++) {
//		delete[] objArr[i];
//	}
//	// delete z
//	delete[] objArr;
//}