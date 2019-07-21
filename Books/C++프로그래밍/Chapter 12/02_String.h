///************
//<주소>		: p510 - String 클래스 선언부
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class String {
//private:
//	char *str;
//	int len;
//
//public:
//	String();
//	String(const char *str);
//	String(const String &copy);
//
//	String& operator=(const String &copy);
//	String operator+(const String &op) const;
//	String& operator+=(const String &op);
//	bool operator==(const String &op) const;
//	friend ostream& operator<<(ostream& os, const String &s);
//	friend istream& operator >> (istream& is, String &s);
//
//	int length() const;
//
//	~String();
//};