///************
//<주소>		: p160 - 문제
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
//		// 여기에 음수 돈 관련 확인 루틴 추가
//		if (money < 0) {
//			cout << "FruitSeller Error: 0보다 작은 돈을 받을 수 없습니다." << endl;
//			return 0;
//		}
//		int num = money / APPLE_PRICE;
//		numApples -= num;
//		FruitSeller::money += money;
//		return num;
//	}
//
//	void showSalesResult() const { // 여기에 const 키워드 추가! (const 함수)
//		cout << "----- 과일 판매자 -----" << endl;
//		cout << "남은 사과: " << numApples << endl;
//		cout << "판매 수익: " << money << endl << endl;
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
//		// 여기에 음수 돈 관련 확인 루틴 추가
//		if (money < 0) {
//			cout << "FruitBuyer Error: 0보다 작은 돈을 줄 수 없습니다." << endl; 
//			return;
//		}
//		numApples += seller.saleApple(money);
//		FruitBuyer::money -= money;
//	}
//
//	void showBuyResult() const { // 여기에 const 키워드 추가! (const 함수)
//		cout << "----- 과일 구매자 -----" << endl;
//		cout << "현재 잔액: " << money << endl;
//		cout << "사과 개수: " << numApples << endl << endl;
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
//	b.buyApple(s, -100000); // 여기서 Error 발생 (음수의 돈)
//
//	s.showSalesResult();
//	b.showBuyResult();
//}