///************
//<�ּ�>		: p453
//**********
//<�ذ���>	:
//
//��� ����: Obj mem
//������ ����: Obj &param �� ��
//
//[ �̴ϼȶ������� ����� ��� ]
//Obj mem = param;  ==> ���� ������
//
//[ ������ ���ο��� �ʱ�ȭ �� ��� ]
//Obj mem;  ==> ������
//mem = param;  ==> ���� ������
//
//���� �̴ϼȶ������� ����ϴ� ���� ȿ������
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
///*
//	@class	AAA
//	@brief	BBB, CCC Ŭ������ ��� ��ü�� ���̱� ���� Ŭ����
//*/
//class AAA {
//private:
//	int n;
//
//public:
//	AAA(int n = 0) : n(n) {
//		cout << "AAA const" << endl;
//	}
//	AAA(const AAA &ref) : n(ref.n) {
//		cout << "AAA copy const" << endl;
//	}
//	AAA& operator=(const AAA &copy) {
//		n = copy.n;
//		cout << "AAA operator=" << endl;
//		return *this;
//	}
//};
//
///*
//	@class	BBB
//	@brief	�����ڿ��� �̴ϼȶ������� �����
//*/
//class BBB {
//private:
//	AAA a;
//
//public:
//	BBB(const AAA &ref) : a(ref) { }
//};
//
///*
//	@class	CCC
//	@brief	�����ڿ��� �̴ϼȶ������� ������� ����
//*/
//class CCC {
//private:
//	AAA a;
//
//public:
//	CCC(const AAA &ref) {
//		a = ref;
//	}
//};
//
//int main() {
//	AAA a(12);
//	cout << "----- b ���� -----" << endl;
//	BBB b(a);
//	cout << "----- c ���� -----" << endl;
//	CCC c(a);
//	return 0;
//}