/************
<�ּ�>		: p147
**********
<�ذ���>	:

stack �����̳ʴ� deque�� �⺻ �����̳�

empty, size, push_back, pop_back, back�� �����ϴ� ��� �����̳ʴ� stack���� ��ȯ ����

push(data);
pop();
top();
empty();
���� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack<int> stack; // stack�� default container�� deque

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}