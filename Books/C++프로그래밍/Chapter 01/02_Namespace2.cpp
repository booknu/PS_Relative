///************
//<�ּ�>		: p40
//**********
//<�ذ���>	: 
//
//"�Լ��� ����"�� ������Ͽ� �����ϰ�,
//"�Լ��� ����"�� �ҽ����Ͽ� �����ϴ°��� �����̹Ƿ�
//
//namespace ���ο��� "�Լ��� ����"�� �ϰ�,
//�� �ܺο� "�Լ��� ����"�� �Ѵ�.
//
//**********
//<�����Ʈ>	: 
//
//*/
//
//#include <iostream>
//
//// ���⼭�� "�Լ��� ����"
//namespace name1 {
//	void sameFunc(void);
//}
//
//namespace name2 {
//	void sameFunc(void);
//}
//
//int main(void) {
//	name1::sameFunc();
//	name2::sameFunc();
//}
//
//// ���⼭�� "�Լ��� ����"
//void name1::sameFunc(void) {
//	std::cout << "name1's function" << std::endl;
//}
//
//void name2::sameFunc(void) {
//	std::cout << "name2's function" << std::endl;
//}