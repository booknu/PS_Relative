///************
//<주소>		: p307
//**********
//<해결방안>	:
//
//has a (소유) 관계도 상속의 조건은 되지만, 복합 관계로 나타내는 것이 일반적임
//
//여기서는 그것을 상속 관계로 표현했다. but, 확장성이 나쁘고 별로 좋지 않은 방법!
//
//**********
//<오답노트>	:
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
//// 상속은 되지만 뭔가 Police가 Gun의 일종인것 같아 이상함!
//// Police의 멤버 변수로 Gun을 가지고 있을 수 있는데 상속을 한다는건 낭비임!
//class Police : public Gun {
//private:
//	int handcuffs; // 소유한 수갑의 수
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