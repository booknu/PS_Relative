/************
<�ּ�>		: p490
**********
<�ذ���>	:

Number n;
n = 20;
�� �ϸ� ���� ���꿡�� �ڷ����� ��ġ���� �ʾ� �̷������ ���� �� ������, (���� ������ �ڷ����� �� ��ġ�ؾ� ��)
�ڵ� ����ȯ�� ���� ���� ������ �����ϴ�.
(���� ���� ���꿡���� �º��� Ÿ�Կ� ���� �캯�� �ڵ� ����ȯ �ȴ�.)

[ ���� ]
1. Number�� int�� ���°� ���� �ʴ´ٴ� ���� �˾Ƴ´�.
2. int�� ������ const Number ��ü�� ����ȯ�Ѵ�. (�ӽð�ü ����)
3. �ӽð�ü�� ������� �ϴ� ���� �����ڸ� ȣ���Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Number {
private:
	int num;

public:
	Number(int n = 0) : num(n) {
		cout << "Number ������: " << n << endl;
	}

	/**
	 *	���� ������
	 *	@param copy: const ���·� �����ؾ� n = 20; ���� 20�� �ڵ� ����ȯ �Ǿ� ���ڷ� �Ѱ��� �� ����!
	 *	@return: ������ ��ü�� ����
	 */
	Number& operator=(const Number &copy) {
		cout << "operator=" << endl;
		num = copy.num;
		return *this;
	}

	void print() {
		cout << num << endl;
	}
};

class Main {
public:
	static int main() {
		Number n;
		n = 30; // 30�� const Number ��ü�� ����ȯ �ȴ�! (�� �������� Number ������ ȣ��)
		n.print();

		return 0;
	}
};
