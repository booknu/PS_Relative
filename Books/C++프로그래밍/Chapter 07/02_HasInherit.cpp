///************
//<�ּ�>		: p307
//**********
//<�ذ���>	:
//
//has a (����) ���赵 ����� ������ ������, ���� ����� ��Ÿ���� ���� �Ϲ�����
//
//���⼭�� �װ��� ��� ����� ǥ���ߴ�. but, Ȯ�强�� ���ڰ� ���� ���� ���� ���!
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
//// ����� ������ ���� Police�� Gun�� �����ΰ� ���� �̻���!
//// Police�� ��� ������ Gun�� ������ ���� �� �ִµ� ����� �Ѵٴ°� ������!
//class Police : public Gun {
//private:
//	int handcuffs; // ������ ������ ��
//
//public:
//	Police(int bnum, int hnum) : Gun(bnum), handcuffs(hnum) { }
//	void putHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//};
//
//int main() {
//	Police p(10, 5);
//	p.putHandcuff();
//	p.shot();
//
//	return 0;
//}