/************
<�ּ�>		: p82
**********
<�ذ���>	:

STL�� ����� �Լ� ��ü
Less�� < �������� �Լ� ��ü
Greater�� > �������� �Լ� ��ü

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

bool Pred_less(int a, int b) {
	return a < b;
}

class Less {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

class Greater {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main(void) {
	//// less ////
	Less lt;
	
	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;
	cout << endl;

	cout << lt(10, 20) << endl;
	cout << lt(20, 10) << endl;
	cout << Less()(10, 20) << endl; // �̷��Ե� ����!
	cout << Less()(20, 10) << endl;
	cout << endl;

	cout << lt.operator()(10, 20) << endl;
	cout << Less().operator()(20, 10) << endl;

	//// greater ////
	Greater gt;

	cout << gt(10, 20) << endl;
	cout << gt(20, 10) << endl;

	return 0;
}