///************
//<�ּ�>		: p94
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//class Simple {
//public:
//	Simple() {
//		cout << "Constructor called" << endl;
//	}
//};
//
//int main(void) {
//	cout << "----- use new -----" << endl;
//	Simple *s1 = new Simple;
//
//	cout << "----- use malloc -----" << endl;
//	Simple *s2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc�� ����ϸ� Constructor�� ȣ����� ����!
//
//	cout << "----- delete / free -----" << endl;
//	delete s1;
//	free(s2);
//	return 0;
//}