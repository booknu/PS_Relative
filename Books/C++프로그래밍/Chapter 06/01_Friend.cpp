///************
//<�ּ�>		: p249
//**********
//<�ذ���>	:
//�������� ���� 
//class Girl�� ���� �����ؼ� Girl�̶�� class�� �ִٴ� ���� �˷� Boy���� ��� �����ϰ� �߰�,
//(but, friend class Girl ��ü�� Ŭ���� ����� ������������ �����ص� ��)
//showFriendInfo�� ���� ���� �س��� �ڿ��� ������ �� ���� ���� ���� ������ ���� phNum�� ������ ��������
//
//**********
//<�����Ʈ>	:
//friend ������ oop�� ������ "���� ����"�� ���ʶ߸�
//���� ����� ���� ���� �ұ������� ����ؾ� ��!
//but, ������ �����ε��� ��Ȳ������ ������ �� �� ����
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Girl;
//
//class Boy {
//private:
//	int height;
//	friend class Girl; // Girl class�� ���� friend ���� (private ������ ����!)
//
//public:
//	Boy(int h) : height(h) { }
//	void showFriendInfo(Girl &frd) const;
//};
//
//class Girl {
//private:
//	char phNum[20];
//
//public:
//	Girl(char *num) {
//		strcpy_s(phNum, 20, num);
//	}
//	void showFriendInfo(Boy &frd) const;
//	friend class Boy; // Boy class�� ���� friend ���� (public ������ ����!)
//};
//
//void Boy::showFriendInfo(Girl &frd) const {
//	cout << "Her phone number: " << frd.phNum << endl; // Girl class�� private�� ���� ��������!
//}
//
//void Girl::showFriendInfo(Boy &frd) const {
//	cout << "His height: " << frd.height << endl; // Boy class�� private�� ���� ��������!
//}
//
//int main(void) {
//	Boy boy(180);
//	Girl girl("010-1111-2222");
//	boy.showFriendInfo(girl);
//	girl.showFriendInfo(boy);
//
//	return 0;
//}