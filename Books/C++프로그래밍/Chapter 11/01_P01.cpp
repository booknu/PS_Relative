///************
//<�ּ�>		: p452 - ���� 1
//**********
//<�ذ���>	:
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
//
//	// ���� ������
//	Police(Police &copy) : handcuffs(copy.handcuffs) {
//		if (copy.pistol == NULL) {
//			pistol = NULL;
//		} else {
//			pistol = new Gun(*copy.pistol); // �� ����
//		}
//	}
//	
//	// ���� ������ �����ε�
//	Police& operator=(Police &copy) {
//		// �켱 �޸� ���� (!!! �߿� !!!)
//		delete pistol;
//
//		handcuffs = copy.handcuffs;
//		if (copy.pistol == NULL) {
//			pistol = NULL;
//		} else {
//			pistol = new Gun(*copy.pistol); // �� ����
//		}
//
//		return *this;
//	}
//
//	void shot() {
//		if (pistol == NULL) {
//			cout << "Don't have a pistol..." << endl;
//		} else {
//			cout << "Police: BBANG!" << endl;
//		}
//	}
//
//	void putHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//
//	~Police() {
//		// ��� pistol�� NULL������ Ȯ�� �� �ص� delete�� �˾Ƽ� Ȯ�����ش�.
//		if (pistol != NULL) {
//			delete pistol;
//		}
//	}
//};
//
//int main() {
//	/////// pistol != NULL ///////
//	cout << "[ pistol != NULL ]" << endl;
//	cout << "origin: " << endl;
//	Police p1(10, 5);
//	p1.putHandcuff();
//	p1.shot();
//	cout << endl;
//
//	// ���� ������
//	cout << "copy constructor: " << endl;
//	Police p1CpyConst = p1;
//	p1CpyConst.putHandcuff();
//	p1CpyConst.shot();
//	cout << endl;
//
//	// ���� ������
//	cout << "operator=: " << endl;
//	Police p1CpyOper(0, 0);
//	p1CpyOper = p1;
//	p1CpyOper.putHandcuff();
//	p1CpyOper.shot();
//	cout << endl;
//
//	/////// pistol == NULL ///////
//	cout << "[ pistol == NULL ]" << endl;
//	cout << "origin: " << endl;
//	Police p2(0, 5);
//	p2.putHandcuff();
//	p2.shot();
//	cout << endl;
//
//	// ���� ������
//	cout << "copy constructor: " << endl;
//	Police p2CpyConst = p2;
//	p2CpyConst.putHandcuff();
//	p2CpyConst.shot();
//	cout << endl;
//
//	// ���� ������
//	cout << "operator=: " << endl;
//	Police p2CpyOper(0, 0);
//	p2CpyOper = p2;
//	p2CpyOper.putHandcuff();
//	p2CpyOper.shot();
//	cout << endl;
//
//	return 0;
//}