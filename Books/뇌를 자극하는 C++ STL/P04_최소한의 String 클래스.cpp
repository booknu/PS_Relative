/************
<주소>		: p55
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	char *str;

public:
	String(const char* _str) {
		int len = strlen(_str) + 1;
		str = new char[len];
		strcpy_s(str, len, _str);
	}

	const String& operator=(String& cpy) {
		delete[] str;

		int len = strlen(cpy.str) + 1;
		str = new char[len];
		strcpy_s(str, len, cpy.str);

		return *this;
	}

	operator const char*() const {
		return str;
	}


	~String() {
		delete[] str;
	}
};

int main(void) {
	String s("Hello!");
	const char* sz = s;
	cout << sz << endl;

	const char* sz2 = "Hello World";
	String s2("Hi~");
	s2 = (String)sz2;
	cout << s2 << endl;
}