///************
//<�ּ�>		: p38
//**********
//<�ذ���>	:
//
//using namespace Name; // ::�� ������� �ʾƵ� Name���� �Լ��� ����ϴ°ɷ� ����
//func();   // ������ ����
//::func(); // ����� ����
//Name::func(); // Name�� func�� �ҷ���
//
//:: = �������� ������ (scope resolution operator)
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//namespace name1 {
//	void sameFunc(void) {
//		std::cout << "name1's function" << std::endl;
//	}
//}
//
//namespace name2 {
//	void sameFunc(void) {
//		std::cout << "name1's function" << std::endl;
//	}
//}
//
//void sameFunc(void) {
//	std::cout << "global function" << std::endl;
//}
//
//int main(void) {
//	// Ư�� Namespace ȣ��� name::function() ���� ȣ��
//	name1::sameFunc();
//	name2::sameFunc();
//	sameFunc();   // ������ ����
//	::sameFunc(); // ����� ����
//
//	std::cout << std::endl << "----- after using namespace name1 -----" << std::endl;
//	using namespace name1;
//	//sameFunc(); // �̰��� global�� name1�� �Լ��� ���ÿ� ���ϹǷ� ������ ������ �߻���
//	::sameFunc(); // ����� ����
//
//	return 0;
//}