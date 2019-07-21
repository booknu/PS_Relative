/************
<�ּ�>		: p142
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE; // ���������, ���� ����� �����ϴ� ���� ��
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
		cout << "----- ���� �Ǹ��� -----" << endl;
		cout << "���� ���: " << numApples << endl;
		cout << "�Ǹ� ����: " << money << endl << endl;
	}
};

class FruitBuyer {
	// private�� �������� �ʾƵ� class�� �⺻������ private
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
		cout << "----- ���� ������ -----" << endl;
		cout << "���� �ܾ�: " << money << endl;
		cout << "��� ����: " << numApples << endl << endl;
	}
};

int main(void) {
	FruitSeller s; // �Ϲ� ���� ���� ��� (FruitSeller *s = new FruitSeller; �� ���� �Ҵ�)
	s.init(1000, 20, 0);
	FruitBuyer b;
	b.init(5000);

	b.buyApple(s, 2000);

	s.showSalesResult();
	b.showBuyResult();
}