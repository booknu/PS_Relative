///************
//<주소>		: p181
//**********
//<해결방안>	:
//멤버 이니셜라이저(초기화 리스트)를 사용해서 객체를 초기화
//멤버 이니셜라이저를 사용하면 선언과 동시에 초기화와 같은 기능을 하기 때문에 성능에 이점.
//또한 이런 특성에 따라 const 변수도 초기화 가능
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
//	const int PRICE;
//	int num, money;
//
//public:
//	FruitSeller(int p, int n, int m) 
//		:PRICE(p), num(n), money(m){
//		// 멤버 이니셜라이저로 초기화
//		// const 변수도 초기화 가능! (선언하자마자 초기화와 같은 기능이므로)
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
//	FruitBuyer(int money) 
//		:money(money), num(0){ // 이 경우 같은 이름이어도 알아서 컴파일 해줌
//		
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