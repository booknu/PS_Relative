/************
<주소>		: p125
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T, int capT = 100>
class Queue {
private:
	T* arr;
	int first, last;
	int cap;

public:
	explicit Queue(int cap = capT) : cap(cap), first(0), last(0) {
		arr = new T[cap];
	}

	~Queue() {
		delete[] arr;
	}

	void Push(const T& data) {
		arr[last] = data;
		last = (last + 1) % cap;
	}

	T Pop() {
		if (Empty()) {
			cout << "Empty Queue Exception" << endl;
			exit(0);
		}
		T& ret = arr[first];
		first = (first + 1) % cap;
		return ret;
	}

	bool Empty() {
		return first == last;
	}
};

int main(void) {
	Queue<int> q;

	q.Push(10);
	q.Push(20);
	q.Push(30);

	while (!q.Empty()) {
		cout << q.Pop() << endl;
	}

	return 0;
}