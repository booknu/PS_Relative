///************
//<주소>		: p304
//**********
//<해결방안>	:
//
//is a (일종) 관계이면 상속이 가능하다는 점을 보여주는 예제
//상속은 is a 관계만 된다!
//
//NoteBook은 Computer의 일종
//Tablet은 Computer의 일종, 또한 NoteBook의 일종
//
//따라서 IS-A 관계가 성립!
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
//class Computer {
//private:
//	char owner[50];
//
//public:
//	Computer(char *name) {
//		strcpy_s(owner, 50, name);
//	}
//	void calc() {
//		cout << "계산 기능" << endl;
//	}
//};
//
//class NoteBook : public Computer {
//private:
//	int battery;
//
//public:
//	NoteBook(char *name, int battery) 
//		: Computer(name), battery(battery) { }
//	void charging() {
//		battery += 5;
//	}
//	void useBattery() {
//		battery -= 1;
//	}
//	void mobileCalc() {
//		if (getBattery() < 1) {
//			cout << "충전이 필요합니다." << endl;
//			return;
//		}
//		cout << "이동하면서 ";
//		calc();
//		useBattery();
//	}
//	int getBattery() {
//		return battery;
//	}
//};
//
//class TabletNoteBook : public NoteBook {
//private:
//	char regstPenModel[50];
//
//public:
//	TabletNoteBook(char *name, int battery, char *pen)
//		: NoteBook(name, battery) {
//		strcpy_s(regstPenModel, 50, pen);
//	}
//	void write(char *penInfo) {
//		if (getBattery() < 1) {
//			cout << "충전이 필요합니다." << endl;
//			return;
//		}
//		if (strcmp(regstPenModel, penInfo) != 0) {
//			cout << "지원하는 전자펜이 아닙니다." << endl;
//			return;
//		}
//		cout << "필기 기능" << endl;
//		useBattery();
//	}
//};
//
//int main() {
//	NoteBook nc("NoteBook 주인", 5);
//	TabletNoteBook tn("Tablet 주인", 5, "ISE-241-242");
//	nc.mobileCalc();
//	tn.write("ISE-241-242");
//
//	return 0;
//}