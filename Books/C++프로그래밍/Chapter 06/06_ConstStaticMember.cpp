///************
//<�ּ�>		: p264
//**********
//<�ذ���>	:
//
//const ��� ������ �̴ϼȶ�����(�ʱ�ȭ ����Ʈ)�� ���ؼ��� �ʱ�ȭ ����
//
//const static ��� ������ = �����ڸ� ���� �ʱ�ȭ ���� 
//(static ��� ������ ����������, ��ü�� ������ ������ static ��� ������ �ʱ�ȭ�Ǵ� ���� �߻�!)
//(���� ���� �ٲ��� �ʴ� const static�� ��쿡 �� ��� ���)
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class CountryArea {
//public:
//	// �̷������� const static ��� ���� �ʱ�ȭ ����!
//	const static int RUSSIA = 1707540;
//	const static int CANADA = 998467;
//	const static int CHINA = 957290;
//	const static int SOUTH_KOREA = 9922;
//	const static int UNKNOWN_COUNTRY;
//};
//
//// �̷������ε� const static ��� ���� �ʱ�ȭ ����!
//const int CountryArea::UNKNOWN_COUNTRY = -1;
//
//int main() {
//	cout << "���þ�: " << CountryArea::RUSSIA << endl;
//	cout << "ĳ����: " << CountryArea::CANADA << endl;
//	cout << "�߱�: " << CountryArea::CHINA << endl;
//	cout << "�ѱ�: " << CountryArea::SOUTH_KOREA << endl;
//	cout << "�˷����� ����: " << CountryArea::UNKNOWN_COUNTRY << endl;
//}
