/************
<�ּ�>		: p149
**********
<�ذ���>	:

stack�� deque�� �⺻ �����̳ʷ� �ϴµ�, vector�� �⺻ �����̳ʷ� ����
(stack�� ���ø� �Ű������� �ٸ� �����̳ʸ� �ִ� ������ ����)
(stack<typename T, typename Alloc = deque<T>>)

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	stack<int, vector<int>> stack; // vector �����̳ʸ� �̿��� stack �����̳� ����

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}