///************
//<주소>		: p199 - 문제 2
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
//namespace RANK_CONST {
//	enum { CLERK, SENIOR, ASSIST, MANAGER };
//}
//
//class NameCard {
//private:
//	char *name, *company, *phone; // 한 줄에 포인터를 여러개 선언할 때는 각각 해줘야 함!
//	int rank;
//
//public:
//	NameCard(const char *name, const char *company, const char *phone, int rank)
//		:rank(rank) {
//		int len = strlen(name) + 1;
//		this->name = new char[len]; // this->name = new char[strlen(name) + 1] 로 한 문장으로 가능!
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
//	void print() {
//		cout << "이름: " << name << endl;
//		cout << "회사: " << company << endl;
//		cout << "전화번호: " << phone << endl;
//		cout << "직급: ";
//		// 이것은 RANK_CONST namespace의 내부에 함수 형태로 존재하는 것이 좋을듯
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
//		cout << endl;
//	}
//
//	// 문자열들을 동적할당 하기 때문에 꼭 delete를 해줘야 함!
//	~NameCard() {
//		delete[] name;
//		delete[] company;
//		delete[] phone;
//	}
//};
//
//int main(void) {
//	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", RANK_CONST::CLERK);
//	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", RANK_CONST::SENIOR);
//	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", RANK_CONST::ASSIST);
//	manClerk.print();
//	manSenior.print();
//	manAssist.print();
//
//	return 0;
//}