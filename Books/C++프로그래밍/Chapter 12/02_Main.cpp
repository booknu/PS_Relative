///************
//<�ּ�>		:
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h>
//#include "02_String.h"
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//	String *s1 = new String("I like ");
//	String *s2 = new String("string class");
//	String *cat = new String(*s1 + *s2);
//
//	// << �����ڵ� �����ε� ��
//	cout << *s1 << endl;
//	cout << *s2 << endl;
//	cout << *cat << endl;
//
//	// == �����ڵ� �����ε� ��
//	if (*s1 == *s2) {
//		cout << "���� ���ڿ�" << endl;
//	} else {
//		cout << "�ٸ� ���ڿ�" << endl;
//	}
//
//	// >> �����ڵ� �����ε� ��
//	String *in = new String();
//	cout << "���ڿ� �Է�: ";
//	cin >> *in;
//	cout << "�Է��� ���ڿ�: " << *in << endl;
//
//	delete s1;
//	delete s2;
//	delete in;
//	delete cat;
//
//	_CrtDumpMemoryLeaks();
//}