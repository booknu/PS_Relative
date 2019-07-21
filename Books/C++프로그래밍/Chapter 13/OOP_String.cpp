/************
<주소>		: p553 - OOP 프로젝트 10단계
**********
<해결방안>	:

**********
<오답노트>	:

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
	이 부분 잘 보기
*/
String String::operator+(const String &op) const {
	char *tmp = new char[this->len + op.len + 1];
	strcpy_s(tmp, len + 1, str);
	strcat_s(tmp, len + op.len + 1, op.str);

	// 책에 있는건 생성자를 또 호출하기 때문에 비효율적
	String ret;
	ret.str = tmp;
	ret.len = this->len + op.len + 1;

	return ret;
}

/*
	이 부분 잘 보기
*/
String& String::operator+=(const String &op) {
	// *this = *this + op  로도 가능하다. (operator+ 이용)
	// but, 이 때는 operator+의 결과로 String 객체가 하나 더 생기기 때문에 좋지 않다.
	len += op.len;
	char *tmp = new char[len + 1]; // 합친 문자열 임시 저장
	strcpy_s(tmp, len + 1, str);
	strcat_s(tmp, len + op.len + 1, op.str);

	delete[] str; // 원래 가리키고 있던 문자열 소멸

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