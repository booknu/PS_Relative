///************
//<�ּ�>		: p309
//**********
//<�ذ���>	:
//
//has a (����) ���赵 ����� ������ ������, ���� ����� ��Ÿ���� ���� �Ϲ�����
//
//������ ����� �� �״�� "����"�̱� ������, ��� �ܿ���
//�ش� Ŭ������ ��� ��ü�� "����"�ϴ� ���� ���� ǥ���� �����ϴ�.
//==> �� ������� �ϴ°� ����!
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Gun {
//private:
//	int bullet;
//
//public:
//	Gun(int initB) : bullet(initB) { }
//	void shot() {
//		cout << "BBANG!" << endl;
//		bullet--;
//	}
//};
//
//class Police {
//private:
//	int handcuffs; // ������ ������ ��
//	Gun *pistol; // Gun�� ������ ����(��� ����)�� ǥ���� ���
//
//public:
//	Police(int bnum, int hnum) : handcuffs(hnum) {
//		if (bnum > 0) {
//			pistol = new Gun(bnum);
//		} else {
//			pistol = NULL;
//		}
//	}
//	// Gun�� ����� �ƴ� ��� ������ ǥ���߱� ������ ���� shot�� ��������� ��.
//	// Gun�� shot�� Police�� shot�� ����� ��ô �ٸ� ���̱� ������ ������ �ؾ��� ���̹Ƿ� ���� ����
//	// ���⼭�� �� �ٸ� ����� "���� ���� ���� ����"�� ǥ����
//	void shot() {
//		if (pistol == NULL) {
//			cout << "Don't have a pistol..." << endl;
//		} else {
//			cout << "Police: BBANG!" << endl;
//		}
//	}
//	void putHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//	~Police() {
//		// ��� pistol�� NULL������ Ȯ�� �� �ص� delete�� �˾Ƽ� Ȯ�����ش�.
//		if (pistol != NULL) {
//			delete pistol;
//		}
//	}
//};
//
//int main() {
//	Police p1(10, 5);
//	p1.putHandcuff();
//	p1.shot();
//
//	Police p2(0, 5);
//	p2.putHandcuff();
//	p2.shot();
//
//	return 0;
//}