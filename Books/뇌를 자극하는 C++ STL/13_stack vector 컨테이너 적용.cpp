/************
<주소>		: p149
**********
<해결방안>	:

stack은 deque를 기본 컨테이너로 하는데, vector을 기본 컨테이너로 적용
(stack의 템플릿 매개변수에 다른 컨테이너를 주는 것으로 가능)
(stack<typename T, typename Alloc = deque<T>>)

**********
<오답노트>	:

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	stack<int, vector<int>> stack; // vector 컨테이너를 이용한 stack 컨테이너 생성

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}