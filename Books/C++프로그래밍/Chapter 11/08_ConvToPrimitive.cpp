///************
//<�ּ�>		: p492
//**********
//<�ذ���>	:
//
//Number n(20);
//Number res = n + 20;
//
//�� ������ ����� �̷��������
//1. NumberŬ������ operator+�� �����ε� �ϰ� �ִ�.
//2. NumberŬ������ int �����ͷ� ����ȯ�� �Ǿ�� �Ѵ�. (�׸��� ���� int�� operator+�� ����)
//�� �� �� �ϳ��� �Ǿ�� �Ѵ�.
//
//������ NumberŬ������ int �����ͷ� ����ȯ �ϴ� ���� ����ߴ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Number {
//private:
//	int num;
//
//public:
//	Number(int n = 0) : num(n) {
//		cout << "Number ������: " << n << endl;
//	}
//
//	Number& operator=(const Number& copy) {
//		cout << "operator=" << endl;
//		num = copy.num;
//		return *this;
//	}
//
//	/**
//	 *	�� ��ȯ ������ �����ε�
//	 *	��ȯ���� ������ �ʿ䰡 ����.
//	 *	@return ��ȯ�� num
//	 */
//	operator int() {
//		return num;
//	}
//
//	void print() {
//		cout << num << endl;
//	}
//};
//
//int main() {
//	Number op;
//	op = 20;
//	Number res = op + 30; // Number op�� int �ڷ������� ��ȯ�ȴ�!
//	res.print();
//}