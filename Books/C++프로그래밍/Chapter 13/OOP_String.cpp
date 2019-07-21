/************
<�ּ�>		: p553 - OOP ������Ʈ 10�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_String.h"

String::String() {
	len = 0;
	str = NULL;
}

String::String(const char *str) {
	len = strlen(str);
	this->str = new char[len + 1];
	strcpy_s(this->str, len + 1, str);
}

String::String(const String &copy) {
	len = copy.len;
	this->str = new char[len + 1];
	strcpy_s(this->str, len + 1, copy.str);
}

String& String::operator=(const String &copy) {
	delete[] str;

	len = copy.len;
	this->str = new char[len + 1];
	strcpy_s(this->str, len + 1, copy.str);

	return *this;
}

/*
	�� �κ� �� ����
*/
String String::operator+(const String &op) const {
	char *tmp = new char[this->len + op.len + 1];
	strcpy_s(tmp, len + 1, str);
	strcat_s(tmp, len + op.len + 1, op.str);

	// å�� �ִ°� �����ڸ� �� ȣ���ϱ� ������ ��ȿ����
	String ret;
	ret.str = tmp;
	ret.len = this->len + op.len + 1;

	return ret;
}

/*
	�� �κ� �� ����
*/
String& String::operator+=(const String &op) {
	// *this = *this + op  �ε� �����ϴ�. (operator+ �̿�)
	// but, �� ���� operator+�� ����� String ��ü�� �ϳ� �� ����� ������ ���� �ʴ�.
	len += op.len;
	char *tmp = new char[len + 1]; // ��ģ ���ڿ� �ӽ� ����
	strcpy_s(tmp, len + 1, str);
	strcat_s(tmp, len + op.len + 1, op.str);

	delete[] str; // ���� ����Ű�� �ִ� ���ڿ� �Ҹ�

	str = tmp;
	return *this;
}

bool String::operator==(const String &op) const {
	return strcmp(this->str, op.str) == 0;
}

ostream& operator<<(ostream& os, const String &s) {
	os << s.str;
	return os;
}

istream& operator >> (istream& is, String &s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int String::length() const {
	return len;
}

String::~String() {
	delete[] str;
}