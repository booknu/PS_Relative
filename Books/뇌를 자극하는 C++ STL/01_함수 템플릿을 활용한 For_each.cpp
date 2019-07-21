/************
<�ּ�>		: p117
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <string>
using namespace std;

// �ݺ��ڿ� �Լ� �����͸� ���ø����� �����Ͽ� ���뼺�� ����
template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) {
	while (begin != end) {
		pf(*begin++);
	}
}

template <typename T>
void Print(T data) {
	cout << data << " ";
}

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	For_each(arr, arr + 5, Print<int>);
	cout << endl;

	string sarr[] = { "a", "abc", "�ѱ�" };
	For_each(sarr, sarr + 3, Print<string>); // ���ø� �Լ��� �����ͷ� �ѱ� ���� �� �Ű����� ���� ���!
	cout << endl;

	return 0;
}