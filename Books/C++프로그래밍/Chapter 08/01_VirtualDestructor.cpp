///************
//<�ּ�>		: p357
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <crtdbg.h> // ������
//using namespace std;
//
//class First {
//private:
//	char *strOne;
//
//public:
//	First(char *str) {
//		strOne = new char[strlen(str) + 1];
//	}
//	// virtual destructor�� �ƴϸ� Static Type�� ���� �Ҹ��ڰ� �ҷ����Ƿ�, �޸� ���� �߻��Ҽ���!
//	// ������ ���⼭ virtual Ű���� ���� �����غ��ٸ� �� �Ҹ��� �ۿ� ���� �� �ǰ� Second�� �Ҹ��ڴ� ������ �� ��!
//	virtual ~First() {
//		cout << "~First();" << endl;
//		delete[] strOne;
//	}
//};
//
//class Second : public First {
//private:
//	char *strTwo;
//
//public:
//	Second(char *str1, char *str2) : First(str1){
//		int len = strlen(str2) + 1;
//		strTwo = new char[len];
//		strcpy_s(strTwo, len, str2);
//	}
//	~Second() {
//		cout << "~Second();" << endl;
//		delete[] strTwo;
//	}
//};
//
//int main() {
//	First *p = new Second("first", "second");
//	delete p;
//
//	_CrtDumpMemoryLeaks(); // F5�� ����� ���� �����ϸ� �޸� ������ �ִ��� Ȯ�� ����! (��� �α� Ȯ��)
//
//	return 0;
//}