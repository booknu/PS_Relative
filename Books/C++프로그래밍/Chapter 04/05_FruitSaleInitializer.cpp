///************
//<�ּ�>		: p181
//**********
//<�ذ���>	:
//��� �̴ϼȶ�����(�ʱ�ȭ ����Ʈ)�� ����ؼ� ��ü�� �ʱ�ȭ
//��� �̴ϼȶ������� ����ϸ� ����� ���ÿ� �ʱ�ȭ�� ���� ����� �ϱ� ������ ���ɿ� ����.
//���� �̷� Ư���� ���� const ������ �ʱ�ȭ ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class FruitSeller {
//private:
//	const int PRICE;
//	int num, money;
//
//public:
//	FruitSeller(int p, int n, int m) 
//		:PRICE(p), num(n), money(m){
//		// ��� �̴ϼȶ������� �ʱ�ȭ
//		// const ������ �ʱ�ȭ ����! (�������ڸ��� �ʱ�ȭ�� ���� ����̹Ƿ�)
//	}
//
//	int sale(int money) {
//		int num = money / PRICE;
//		this->num -= num;
//		this->money += money;
//		return num;
//	}
//
//	void print() const {
//		cout << "���� ���: " << num << endl;
//		cout << "�Ǹ� ����: " << money << endl;
//	}
//};
//
//class FruitBuyer {
//private:
//	int money, num;
//
//public:
//	FruitBuyer(int money) 
//		:money(money), num(0){ // �� ��� ���� �̸��̾ �˾Ƽ� ������ ����
//		
//	}
//
//	void buy(FruitSeller &seller, int money) {
//		num += seller.sale(money);
//		this->money -= money;
//	}
//
//	void print() const {
//		cout << "���� �ܾ�: " << money << endl;
//		cout << "���� ���: " << num << endl;
//	}
//};
//
//int main(void) {
//	FruitSeller s(1000, 20, 0);
//	FruitBuyer b(5000);
//	b.buy(s, 2000);
//
//	cout << "<< �Ǹ��� >>" << endl;
//	s.print();
//	cout << "<< ������ >>" << endl;
//	b.print();
//
//	return 0;
//}