///************
//<주소>		: p452 - 문제 1
//**********
//<해결방안>	:
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
//
//	// 복사 생성자
//	Police(Police &copy) : handcuffs(copy.handcuffs) {
//		if (copy.pistol == NULL) {
//			pistol = NULL;
//		} else {
//			pistol = new Gun(*copy.pistol); // 총 복사
//		}
//	}
//	
//	// 대입 연산자 오버로딩
//	Police& operator=(Police &copy) {
//		// 우선 메모리 해제 (!!! 중요 !!!)
//		delete pistol;
//
//		handcuffs = copy.handcuffs;
//		if (copy.pistol == NULL) {
//			pistol = NULL;
//		} else {
//			pistol = new Gun(*copy.pistol); // 총 복사
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
//		// 사실 pistol이 NULL인지는 확인 안 해도 delete가 알아서 확인해준다.
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
//	// 복사 생성자
//	cout << "copy constructor: " << endl;
//	Police p1CpyConst = p1;
//	p1CpyConst.putHandcuff();
//	p1CpyConst.shot();
//	cout << endl;
//
//	// 대입 연산자
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
//	// 복사 생성자
//	cout << "copy constructor: " << endl;
//	Police p2CpyConst = p2;
//	p2CpyConst.putHandcuff();
//	p2CpyConst.shot();
//	cout << endl;
//
//	// 대입 연산자
//	cout << "operator=: " << endl;
//	Police p2CpyOper(0, 0);
//	p2CpyOper = p2;
//	p2CpyOper.putHandcuff();
//	p2CpyOper.shot();
//	cout << endl;
//
//	return 0;
//}