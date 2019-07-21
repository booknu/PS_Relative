/************
<�ּ�>		: p537
**********
<�ذ���>	:

�Լ� ���ø����� �Ѳ����� ó���� �� ���� Ư���� ��찡 ���ڷ� ���´ٸ�,
Specialization�� ���� ���� ó������� �Ѵ�.

���⼭�� �� ���� ���ڰ� char*�� ���, const char*�� ��츦 Specialization �ߴ�.

[ ���ڿ� ]
char[] a = "dasdsa";
���� ���� char * �� ���ڰ� �Ѿ��,

"dasdasdas"
char *b = "dsadsadasd"
���� ���� const char * �� ���ڰ� �Ѿ��.

**********
<�����Ʈ>	:

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
	*	char*, char*�� ������ ��츦 Ư���ϰ� ó���ϱ� ����
	*	= char* max<char*> (char *a, char *b) {}
	*/
	template <>
	static char* max(char *a, char *b) {
		cout << "specialized char*" << endl;
		return strlen(a) > strlen(b) ? a : b;
	}

	/**
	*	Specialization
	*	const char*, const char*�� ������ ��츦 Ư���ϰ� ó���ϱ� ����
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