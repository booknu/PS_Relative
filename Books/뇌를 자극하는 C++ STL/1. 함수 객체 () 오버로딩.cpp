/************
<�ּ�>		: p33
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class FuncObject {
public:
	void operator()(int arg) const {
		cout << "FuncObject: " << arg << endl;
	}
};

void func1(int arg) {
	cout << "func: " << arg << endl;
}

int main(void) {
	void(*func2)(int) = func1; // �Լ� ������
	FuncObject func3; // �Լ� ��ü

	func1(10);
	func2(20);
	func3(30);
}