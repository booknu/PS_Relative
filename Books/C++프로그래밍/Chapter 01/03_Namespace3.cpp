///************
//<�ּ�>		: p41
//**********
//<�ذ���>	:
//
//���� namespace�� ���ǵ� �Լ� ȣ��ÿ��� namespace�� ����� �ʿ䰡 ����.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//namespace name1 {
//	void sameFunc(void);
//}
//
//namespace name1 {
//	void inName1Func(void);
//}
//
//namespace name2 {
//	void sameFunc(void);
//}
//
//int main(void) {
//	name1::sameFunc();
//}
//
//void inName1Func(void) {
//	std::cout << "global inFunc called" << std::endl;
//}
//void name1::inName1Func(void) {
//	std::cout << "name1's inFunc called" << std::endl;
//}
//
//void name2::sameFunc(void) {
//	std::cout << "name2's func called" << std::endl;
//}
//
//void name1::sameFunc(void) {
//	std::cout << "name1's func called" << std::endl;
//	inName1Func(); // namespace�� ����� �ʿ䰡 ����! (���� namespace)
//	::inName1Func(); // ����� ����
//	name2::sameFunc(); // namespace�� ����ؾ���! (�ٸ� namespace)
//}