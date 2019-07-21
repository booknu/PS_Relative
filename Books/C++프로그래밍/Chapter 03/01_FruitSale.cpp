/************
<주소>		: p142
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE; // 상수이지만, 아직 상수를 정의하는 법은 모름
	int numApples;
	int money;

public:
	void init(int price, int num, int money) {
		APPLE_PRICE = price;
		numApples = num;
		FruitSeller::money = money;
	}

	int saleApple(int money) {
		int num = money / APPLE_PRICE;
		numApples -= num;
		FruitSeller::money += money;
		return num;
	}

	void showSalesResult() {
		cout << "----- 과일 판매자 -----" << endl;
		cout << "남은 사과: " << numApples << endl;
		cout << "판매 수익: " << money << endl << endl;
	}
};

class FruitBuyer {
	// private을 선언하지 않아도 class는 기본적으로 private
	int money;
	int numApples;

public:
	void init(int money) {
		FruitBuyer::money = money;
		numApples = 0;
	}

	void buyApple(FruitSeller &seller, int money) {
		numApples += seller.saleApple(money);
		FruitBuyer::money -= money;
	}

	void showBuyResult() {
		cout << "----- 과일 구매자 -----" << endl;
		cout << "현재 잔액: " << money << endl;
		cout << "사과 개수: " << numApples << endl << endl;
	}
};

int main(void) {
	FruitSeller s; // 일반 변수 선언 방식 (FruitSeller *s = new FruitSeller; 은 동적 할당)
	s.init(1000, 20, 0);
	FruitBuyer b;
	b.init(5000);

	b.buyApple(s, 2000);

	s.showSalesResult();
	b.showBuyResult();
}