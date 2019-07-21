/************
<주소>		: p147
**********
<해결방안>	:

stack 컨테이너는 deque가 기본 컨테이너

empty, size, push_back, pop_back, back을 지원하는 모든 컨테이너는 stack으로 변환 가능

push(data);
pop();
top();
empty();
연산 제공

**********
<오답노트>	:

*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack<int> stack; // stack의 default container은 deque

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}