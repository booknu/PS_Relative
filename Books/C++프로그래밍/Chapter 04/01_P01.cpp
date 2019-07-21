///************
//<�ּ�>		: p160 - ����
//**********
//<�ذ���>	:
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
//	int APPLE_PRICE;
//	int numApples;
//	int money;
//
//public:
//	void init(int price, int num, int money) {
//		APPLE_PRICE = price;
//		numApples = num;
//		FruitSeller::money = money;
//	}
//
//	int saleApple(int money) {
//		// ���⿡ ���� �� ���� Ȯ�� ��ƾ �߰�
//		if (money < 0) {
//			cout << "FruitSeller Error: 0���� ���� ���� ���� �� �����ϴ�." << endl;
//			return 0;
//		}
//		int num = money / APPLE_PRICE;
//		numApples -= num;
//		FruitSeller::money += money;
//		return num;
//	}
//
//	void showSalesResult() const { // ���⿡ const Ű���� �߰�! (const �Լ�)
//		cout << "----- ���� �Ǹ��� -----" << endl;
//		cout << "���� ���: " << numApples << endl;
//		cout << "�Ǹ� ����: " << money << endl << endl;
//	}
//};
//
//class FruitBuyer {
//	int money;
//	int numApples;
//
//public:
//	void init(int money) {
//		FruitBuyer::money = money;
//		numApples = 0;
//	}
//
//	void buyApple(FruitSeller &seller, int money) {
//		// ���⿡ ���� �� ���� Ȯ�� ��ƾ �߰�
//		if (money < 0) {
//			cout << "FruitBuyer Error: 0���� ���� ���� �� �� �����ϴ�." << endl; 
//			return;
//		}
//		numApples += seller.saleApple(money);
//		FruitBuyer::money -= money;
//	}
//
//	void showBuyResult() const { // ���⿡ const Ű���� �߰�! (const �Լ�)
//		cout << "----- ���� ������ -----" << endl;
//		cout << "���� �ܾ�: " << money << endl;
//		cout << "��� ����: " << numApples << endl << endl;
//	}
//};
//
//int main(void) {
//	FruitSeller s;
//	s.init(1000, 20, 0);
//	FruitBuyer b;
//	b.init(5000);
//
//	b.buyApple(s, 2000);
//	b.buyApple(s, -100000); // ���⼭ Error �߻� (������ ��)
//
//	s.showSalesResult();
//	b.showBuyResult();
//}