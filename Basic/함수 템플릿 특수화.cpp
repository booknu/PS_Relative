/************
<주소>		: p537
**********
<해결방안>	:

함수 템플릿에서 한꺼번에 처리할 수 없는 특수한 경우가 인자로 들어온다면,
Specialization을 통해 따로 처리해줘야 한다.

여기서는 그 예로 인자가 char*인 경우, const char*인 경우를 Specialization 했다.

[ 문자열 ]
char[] a = "dasdsa";
같은 경우는 char * 로 인자가 넘어가고,

"dasdasdas"
char *b = "dsadsadasd"
같은 경우는 const char * 로 인자가 넘어간다.

**********
<오답노트>	:

*/

#ifndef __TEMPLATE_SPECIALIZATION_H__
#define __TEMPLATE_SPECIALIZATION_H__

#include <iostream>
using namespace std;

class Main {
public:
	template <typename T>
	static T max(T a, T b) {
		return a > b ? a : b;
	}

	/**
	*	Specialization
	*	char*, char*이 인자인 경우를 특수하게 처리하기 위함
	*	= char* max<char*> (char *a, char *b) {}
	*/
	template <>
	static char* max(char *a, char *b) {
		cout << "specialized char*" << endl;
		return strlen(a) > strlen(b) ? a : b;
	}

	/**
	*	Specialization
	*	const char*, const char*이 인자인 경우를 특수하게 처리하기 위함
	*	= const char* max<const char*> (const char *a, const char *b) {}
	*/
	template <>
	static const char* max(const char *a, const char *b) {
		cout << "specialized const char*" << endl;
		return strcmp(a, b) > 0 ? a : b;
	}

	static int main() {
		cout << max(11, 15) << endl;
		cout << max('A', 'Z') << endl;
		cout << max(3.5, 7.5) << endl;
		cout << max("AAA", "ZZZ") << endl; // specialized const char*

		char str1[] = "Short";
		char str2[] = "Long~~~~~~";
		cout << max(str1, str2) << endl; // specialized char*

		return 0;
	}
};

#endif