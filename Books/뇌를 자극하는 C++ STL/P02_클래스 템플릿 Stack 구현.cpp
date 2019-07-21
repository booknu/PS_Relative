/************
<주소>		: p124 - 문제 2
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T, int capT = 100>
class Stack {
private:
	T* arr;
	int size;
	int cap;

public:
	explicit Stack(int _cap = capT) : cap(_cap), size(0) {
		arr = new T[cap];
	}

	~Stack() {
		delete[] arr;
	}

	T Pop() {
		if (size == 0) {
			cout << "Empty Stack Exception" << endl;
			exit(1);
		}
		return arr[--size];
	}

	void Push(const T& data) {
		if (size == cap) {
			cout << "Stack Overflow Exception" << endl;
			exit(1);
		}
		arr[size++] = data;
	}

	bool Empty() {
		return size == 0;
	}
};

int main(void) {
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	while (!stack.Empty()) {
		cout << stack.Pop() << endl;;
	}

	return 0;
}