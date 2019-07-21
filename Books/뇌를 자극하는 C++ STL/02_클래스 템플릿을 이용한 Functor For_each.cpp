/************
<�ּ�>		: p119
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

// �Լ� ������ ��� Functor�� �ѱ�� �� ����
// functor�� ����� ���� �� �ְ�, �� ������, inlineȭ�� �����ϱ� ����
template <typename T>
class PrintFunctor {
private:
	string sep; // ��� ������
	
public:
	explicit PrintFunctor(const string& _sep = ", ") : sep(_sep) { }

	void operator()(T data) const {
		cout << data << sep;
	}
};

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	For_each(arr, arr + 5, PrintFunctor<int>());
	cout << endl;

	string sarr[] = { "a", "abc", "�ѱ�" };
	For_each(sarr, sarr + 3, PrintFunctor<string>("\n"));
	cout << endl;

	return 0;
}