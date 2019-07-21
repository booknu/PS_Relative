///************
//<�ּ�>		: p296 - ���� 2
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
//class MyFriendInfo {
//private:
//	char *name;
//	int age;
//
//public:
//	MyFriendInfo(char *name, int age) : age(age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//	}
//
//	void print() {
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//
//	~MyFriendInfo() {
//		delete[] name;
//	}
//};
//
//class MyFriendDetailInfo : public MyFriendInfo {
//private:
//	char *addr, *phone;
//
//public:
//	MyFriendDetailInfo(char *name, int age, char *addr, char *phone)
//		: MyFriendInfo(name, age) {
//		int len = strlen(addr) + 1;
//		this->addr = new char[len];
//		strcpy_s(this->addr, len, addr);
//		
//		len = strlen(phone) + 1;
//		this->phone = new char[len];
//		strcpy_s(this->phone, len, phone);
//	}
//
//	void print() {
//		MyFriendInfo::print();
//		cout << "�ּ�: " << addr << endl;
//		cout << "��ȭ: " << phone << endl;
//		cout << endl;
//	}
//
//	~MyFriendDetailInfo() {
//		delete[] addr;
//		delete[] phone;
//	}
//};
//
//int main() {
//	MyFriendDetailInfo f1("A��", 10, "�ּ�A", "��ȭA");
//	MyFriendDetailInfo f2("B��", 20, "�ּ�B", "��ȭB");
//	MyFriendDetailInfo f3("C��", 30, "�ּ�C", "��ȭC");
//	MyFriendDetailInfo f4("D��", 40, "�ּ�D", "��ȭD");
//	MyFriendDetailInfo f5("E��", 50, "�ּ�E", "��ȭE");
//
//	f1.print();
//	f2.print();
//	f3.print();
//	f4.print();
//	f5.print();
//}