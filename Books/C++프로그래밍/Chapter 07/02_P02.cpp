///************
//<주소>		: p296 - 문제 2
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
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
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
//		cout << "주소: " << addr << endl;
//		cout << "전화: " << phone << endl;
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
//	MyFriendDetailInfo f1("A씨", 10, "주소A", "전화A");
//	MyFriendDetailInfo f2("B씨", 20, "주소B", "전화B");
//	MyFriendDetailInfo f3("C씨", 30, "주소C", "전화C");
//	MyFriendDetailInfo f4("D씨", 40, "주소D", "전화D");
//	MyFriendDetailInfo f5("E씨", 50, "주소E", "전화E");
//
//	f1.print();
//	f2.print();
//	f3.print();
//	f4.print();
//	f5.print();
//}