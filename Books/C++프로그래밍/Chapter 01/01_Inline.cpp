///************
//<�ּ�>		: p34
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
//
///*
//	�ζ��� �Լ��� ��ũ�� �Լ��� �Ȱ��� ����� �Ѵ�.
//	������, ��������� �ڷ����� ǥ���ؾ� �ϹǷ�, ��ũ�θ� ����ϴ� �Ͱ��� ���� �ٸ���.
//	�̷� ������ ���ø��� ��������μ� �ذ��� �� �ִ�.
//*/
//inline int max(int a, int b) {
//	return a > b ? a : b;
//}
//
///*
//	�ζ��� �Լ��� ���ø��� Ȱ���� ������ ���.
//	��ũ�ο� ��Ȯ�� ���� ����� �Ѵ�.
//*/
//template <typename T>
//inline T min(T a, T b) {
//	return a < b ? a : b;
//}
//
//int main(void) {
//	std::cout << "----- inline function -----" << std::endl;
//	std::cout << max(10, 5) << std::endl;
//	std::cout << max(-1, 1) << std::endl;
//
//	std::cout << "----- use template -----" << std::endl;
//	std::cout << min(10, 5) << std::endl;
//	std::cout << min(-1, 1) << std::endl;
//	return 0;
//}