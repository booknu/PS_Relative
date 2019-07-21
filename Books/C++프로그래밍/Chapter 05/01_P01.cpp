///************
//<�ּ�>		: p226 - ����
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
//namespace RANK_CONST {
//	enum { CLERK, SENIOR, ASSIST, MANAGER };
//
//	void printRank(int rank) {
//		switch (rank) {
//		case RANK_CONST::CLERK:
//			cout << "Clerk" << endl;
//			break;
//		case RANK_CONST::SENIOR:
//			cout << "Senior" << endl;
//			break;
//		case RANK_CONST::ASSIST:
//			cout << "Assist" << endl;
//			break;
//		case RANK_CONST::MANAGER:
//			cout << "Manager" << endl;
//			break;
//		default:
//			cout << "ERROR: Unknown Rank" << endl;
//		}
//	}
//}
//
//class NameCard {
//private:
//	char *name, *company, *phone;
//	int rank;
//
//public:
//	NameCard(const char *name, const char *company, const char *phone, int rank)
//		:rank(rank) {
//		int len = strlen(name) + 1;
//		this->name = new char[len]; // this->name = new char[strlen(name) + 1] �� �� �������� ����!
//		strcpy_s(this->name, len, name);
//
//		len = strlen(company) + 1;
//		this->company = new char[len];
//		strcpy_s(this->company, len, company);
//
//		len = strlen(phone) + 1;
//		this->phone = new char[len];
//		strcpy_s(this->phone, len, phone);
//	}
//
//	// deep copy�� ���� copy constructor
//	NameCard(NameCard &another) : rank(rank) {
//		int len = strlen(another.name) + 1;
//		this->name = new char[len]; // this->name = new char[strlen(name) + 1] �� �� �������� ����!
//		strcpy_s(this->name, len, another.name);
//
//		len = strlen(another.company) + 1;
//		this->company = new char[len];
//		strcpy_s(this->company, len, another.company);
//
//		len = strlen(another.phone) + 1;
//		this->phone = new char[len];
//		strcpy_s(this->phone, len, another.phone);
//	}
//
//	void print() {
//		cout << "�̸�: " << name << endl;
//		cout << "ȸ��: " << company << endl;
//		cout << "��ȭ��ȣ: " << phone << endl;
//		cout << "����: ";
//		RANK_CONST::printRank(rank);
//
//		cout << endl;
//	}
//
//	// ���ڿ����� �����Ҵ� �ϱ� ������ �� delete�� ����� ��!
//	~NameCard() {
//		cout << "destructor called! (" << name << ')' << endl;
//		delete[] name;
//		delete[] company;
//		delete[] phone;
//	}
//};
//
//int main(void) {
//	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", RANK_CONST::CLERK);
//	NameCard clerkCopy = manClerk;
//	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", RANK_CONST::SENIOR);
//	NameCard seniorCopy = manSenior;
//	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", RANK_CONST::ASSIST);
//	NameCard assistCopy = manAssist;
//
//	cout << "----- Originals -----" << endl;
//	manClerk.print();
//	manSenior.print();
//	manAssist.print();
//
//	cout << "----- Copies -----" << endl;
//	clerkCopy.print();
//	seniorCopy.print();
//	assistCopy.print();
//
//	cout << "----- end -----" << endl;
//
//	return 0;
//}