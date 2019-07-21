///************
//<�ּ�>		: p443
//**********
//<�ذ���>	:
//
//���� �����ڿ� ���� �����ڴ� ����� �����ѵ�, �� ȣ�� �ñⰡ �ٸ���
//
//[ ���� ������ ]
//Obj src(...);
//Obj cpy;
//cpy = src;
//==> �̹� �ʱ�ȭ�� ��ü�� ������ �ϸ� ���� ������ ȣ��
//
//[ ���� ������ ]
//Obj src(...);
//Obj cpy = src;
//==> �ʱ�ȭ �ϸ� ������ �ϸ� ���� ������ ȣ��
//
//���� ��ü ���ο� �������� ������ �ִٸ� ���� ������, ���� �����ڸ� ��� ����� ���� �����
//���� ����, �ʱ�ȭ�� ������
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
///**
//	@class	First
//	@date	
//	@author	LimSY
//	@brief	���� ������(=)�� �����ε� ���� ���� Ŭ����
//*/
//class First {
//private:
//	int n1, n2;
//
//public:
//	First(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
//	friend ostream& operator<<(ostream &os, First &target);
//};
//
///*
//	@brief			cout << Second ��ü ������ �����ϰ� �������
//	@param os		ostream ��ü (ex: cout)
//	@param target	����� Second ��ü
// */
//ostream& operator<<(ostream &os, First &target) {
//	os << target.n1 << ", " << target.n2;
//	return os;
//}
//
///**
//	@class	Second
//	@date	
//	@author	LimSY
//	@brief	���� ������(=)�� �����ε��� Ŭ����
//*/
//class Second {
//private:
//	int n3, n4;
//
//public:
//	Second(int n3 = 0, int n4 = 0) : n3(n3), n4(n4) { }
//	Second& operator=(const Second &copy) {
//		n3 = copy.n3;
//		n4 = copy.n4;
//		return *this; // a = b = c �� ���� ���ӵ� = �� ��� �����ϰ� �������
//	}
//	friend ostream& operator<<(ostream &os, Second &target);
//};
//
///*
//	@brief			cout << Second ��ü ������ �����ϰ� �������
//	@param os		ostream ��ü (ex: cout)
//	@param target	����� Second ��ü
//*/
//ostream& operator<<(ostream &os, Second &target) {
//	os << target.n3 << ", " << target.n4;
//	return os;
//}
//
//int main() {
//	//////////////////////////////////////////////////////////////
//	First fsrc(111, 222);
//	First fcpy;
//	Second ssrc(333, 444);
//	Second scpy;
//
//	fcpy = fsrc; // default operator= �Լ��� ȣ��� (���� ����)
//	scpy = ssrc; // ������ ������ operator= �Լ��� ȣ��� (���� ����)
//
//	cout << "fcpy: " << fcpy << endl;
//	cout << "scpy: " << scpy << endl << endl;
//
//	///////////////////////////////////////////////////////////////
//	First fob1, fob2;
//	Second sob1, sob2;
//	
//	// �������� = �����ڰ� ���ӵǾ� ������ �����ʿ������� ����
//	fob1 = fob2 = fsrc; // default
//	sob1 = sob2 = ssrc; // �����ε�
//
//	cout << "fob1: " << fob1 << endl;
//	cout << "fob2: " << fob2 << endl;
//	cout << "sob1: " << sob1 << endl;
//	cout << "sob2: " << sob2 << endl;
//
//	return 0;
//}