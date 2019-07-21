/************
<�ּ�>		: p121
**********
<�ذ���>	:

Ŭ���̾�Ʈ���� ������ �Լ� ��ü�� �ѱ� ��,
returnŸ��, argsŸ���� Ŭ���̾�Ʈ ������ �����ϴ� �Լ� ��ü�� ���� �� �ִ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <string>
using namespace std;

// return Ÿ��, args Ÿ���� ���ø����� ���
template <typename RetType, typename ArgType>
class Functor {
public:
	RetType operator()(ArgType data) {
		cout << data << endl;
		return RetType();
	}
};

int main(void) {
	Functor<void, int> functor1;
	functor1(10);

	Functor<bool, string> functor2;
	functor2("STRING");

	return 0;
}