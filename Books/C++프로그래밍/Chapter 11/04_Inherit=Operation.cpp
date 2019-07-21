///************
//<�ּ�>		: p449
//**********
//<�ذ���>	:
//
//[ Derived���� ���Կ����� ���� X ]
//Base���� operator= �� �����ε� �Ǿ���
//Derived���� operator= �� �����ε� ���� �ʾ�����
//
//Derived�� default operator= �� ����ǰ�, �ű⼭
//Base�� operator= �� ����ȴ�.
//
//[ Derived���� ���Կ����� ���� O ]
//Base���� operator= �� �����ε� �Ǿ���,
//Derived���� operator= �� �����ε� �Ǿ�����,
//
//Derived�� operator= �� ����ȴ�.
//==> but, �ڵ����� Base�� operator= �� ��������� �ʴ´�. (!!! �߿� !!!)
//
//
//[ �� �� ]
//Derived�� operator= ���ǿ���, ��������� Base�� operator=�� ȣ����� ������,
//�ڵ����� ȣ����� ������, ��������� Base�� operator=�� ȣ������
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class First {
//private:
//	int n1, n2;
//
//public:
//	First(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
//	
//	friend ostream& operator<<(ostream &os, First &f);
//
//	/*
//		operator<< �����ε���
//		dynamic type�� ���� ����ϱ� ����
//	*/
//	virtual void out(ostream &os) {
//		os << n1 << ", " << n2;
//	}
//
//	// operator= �����ε�
//	First& operator=(const First& ref) {
//		cout << "First& operator=()" << endl;
//		n1 = ref.n1;
//		n2 = ref.n2;
//		return *this;
//	}
//};
//
//ostream& operator<<(ostream &os, First &f) {
//	f.out(os);
//	return os;
//}
//
//class Second : public First {
//private:
//	int n3, n4;
//
//public:
//	Second(int n1, int n2, int n3, int n4) : First(n1, n2), n3(n3), n4(n4) { }
//
//	/*
//		operator<< �����ε���
//		dynamic type�� ���� ����ϱ� ����
//	*/
//	virtual void out(ostream &os) {
//		First::out(os);
//		os << ", " << n3 << ", " << n4;
//	}
//
//	// operator= �����ε�
//	Second& operator=(const Second &ref) {
//		First::operator=(ref); // �̰� �� �����ؾ� Base�� operator= �� �����!!
//		cout << "Second& operator=()" << endl;
//		n3 = ref.n3;
//		n4 = ref.n4;
//		return *this;
//	}
//};
//
//int main(void) {
//	Second ssrc(1, 2, 3, 4);
//	Second scpy(0, 0, 0, 0);
//	scpy = ssrc;
//	cout << scpy << endl;
//
//	// Second���� opera
//
//	return 0;
//}