///************
//<주소>		: p173
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class FruitSeller {
//private:
//	int PRICE, num, money;
//	
//public:
//	FruitSeller(int p, int n, int m) {
//		PRICE = p;
//		num = n;
//		money = m;
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
//		cout << "남은 사과: " << num << endl;
//		cout << "판매 수익: " << money << endl;
//	}
//};
//
//class FruitBuyer {
//private:
//	int money, num;
//
//public:
//	FruitBuyer(int money) {
//		this->money = money;
//		num = 0;
//	}
//
//	void buy(FruitSeller &seller, int money) {
//		num += seller.sale(money);
//		this->money -= money;
//	}
//
//	void print() const {
//		cout << "현재 잔액: " << money << endl;
//		cout << "가진 사과: " << num << endl;
//	}
//};
//
//int main(void) {
//	FruitSeller s(1000, 20, 0);
//	FruitBuyer b(5000);
//	b.buy(s, 2000);
//
//	cout << "<< 판매자 >>" << endl;
//	s.print();
//	cout << "<< 구매자 >>" << endl;
//	b.print();
//
//	return 0;
//}