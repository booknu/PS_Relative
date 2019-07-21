///************
//<주소>		: p249
//**********
//<해결방안>	:
//컴파일을 위해 
//class Girl을 먼저 선언해서 Girl이라는 class가 있다는 것을 알려 Boy에서 사용 가능하게 했고,
//(but, friend class Girl 자체가 클래스 선언과 마찬가지여서 제외해도 됨)
//showFriendInfo는 원형 선언만 해놓고 뒤에서 구현을 한 것을 통해 아직 나오지 않은 phNum에 접근이 가능해짐
//
//**********
//<오답노트>	:
//friend 선언은 oop의 장점인 "정보 은닉"을 무너뜨림
//따라서 고심을 통해 극히 소극적으로 사용해야 함!
//but, 연산자 오버로딩의 상황에서는 장점이 될 수 있음
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
//	friend class Girl; // Girl class에 대한 friend 선언 (private 에서도 가능!)
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
//	friend class Boy; // Boy class에 대한 friend 선언 (public 에서도 가능!)
//};
//
//void Boy::showFriendInfo(Girl &frd) const {
//	cout << "Her phone number: " << frd.phNum << endl; // Girl class의 private도 접근 가능해짐!
//}
//
//void Girl::showFriendInfo(Boy &frd) const {
//	cout << "His height: " << frd.height << endl; // Boy class의 private도 접근 가능해짐!
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