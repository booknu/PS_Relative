/************
<�ּ�>		: p80
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <algorithm>
using namespace std;

//// Ŭ���̾�Ʈ ////
class Functor1 {
public:
	void operator()(int n) {
		cout << n << " ";
	}
};

class Functor2 {
public:
	void operator()(int n) {
		cout << n * n << " ";
	}
};

class Functor3 {
public:
	void operator()(int n) {
		cout << "����: " << n << endl;
	}
};

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	
	// �ӽ� �Լ� ��ü�� ����� ����
	for_each(arr, arr + 5, Functor1());
	cout << endl << endl;
	for_each(arr, arr + 5, Functor2());
	cout << endl << endl;
	for_each(arr, arr + 5, Functor3());

	return 0;
}