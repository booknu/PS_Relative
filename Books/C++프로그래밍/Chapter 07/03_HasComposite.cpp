///************
//<주소>		: p309
//**********
//<해결방안>	:
//
//has a (소유) 관계도 상속의 조건은 되지만, 복합 관계로 나타내는 것이 일반적임
//
//소유의 관계는 말 그대로 "소유"이기 때문에, 상속 외에도
//해당 클래스의 멤버 객체로 "소유"하는 것을 통해 표현이 가능하다.
//==> 이 방법으로 하는게 좋음!
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
//class Police {
//private:
//	int handcuffs; // 소유한 수갑의 수
//	Gun *pistol; // Gun을 소유의 관계(멤버 변수)로 표현한 모습
//
//public:
//	Police(int bnum, int hnum) : handcuffs(hnum) {
//		if (bnum > 0) {
//			pistol = new Gun(bnum);
//		} else {
//			pistol = NULL;
//		}
//	}
//	// Gun을 상속이 아닌 멤버 변수로 표현했기 때문에 새로 shot을 정의해줘야 함.
//	// Gun의 shot과 Police의 shot의 기능은 무척 다를 것이기 때문에 어차피 해야할 일이므로 문제 없음
//	// 여기서는 그 다른 기능을 "총을 들지 않은 경찰"로 표현함
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
//		// 사실 pistol이 NULL인지는 확인 안 해도 delete가 알아서 확인해준다.
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