/************
<주소>		: p553 - OOP 프로젝트 10단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String {
private:
	char *str;
	int len;

public:
	String();
	String(const char *str);
	String(const String &copy);

	String& operator=(const String &copy);
	String operator+(const String &op) const;
	String& operator+=(const String &op);
	bool operator==(const String &op) const;
	friend ostream& operator<<(ostream& os, const String &s);
	friend istream& operator >> (istream& is, String &s);

	int length() const;

	~String();
};

#endif