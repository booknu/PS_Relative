///************
//<�ּ�>		: p304
//**********
//<�ذ���>	:
//
//is a (����) �����̸� ����� �����ϴٴ� ���� �����ִ� ����
//����� is a ���踸 �ȴ�!
//
//NoteBook�� Computer�� ����
//Tablet�� Computer�� ����, ���� NoteBook�� ����
//
//���� IS-A ���谡 ����!
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
//class Computer {
//private:
//	char owner[50];
//
//public:
//	Computer(char *name) {
//		strcpy_s(owner, 50, name);
//	}
//	void calc() {
//		cout << "��� ���" << endl;
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
//			cout << "������ �ʿ��մϴ�." << endl;
//			return;
//		}
//		cout << "�̵��ϸ鼭 ";
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
//			cout << "������ �ʿ��մϴ�." << endl;
//			return;
//		}
//		if (strcmp(regstPenModel, penInfo) != 0) {
//			cout << "�����ϴ� �������� �ƴմϴ�." << endl;
//			return;
//		}
//		cout << "�ʱ� ���" << endl;
//		useBattery();
//	}
//};
//
//int main() {
//	NoteBook nc("NoteBook ����", 5);
//	TabletNoteBook tn("Tablet ����", 5, "ISE-241-242");
//	nc.mobileCalc();
//	tn.write("ISE-241-242");
//
//	return 0;
//}