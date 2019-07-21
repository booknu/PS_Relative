/************
<주소>		: p39
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <class T>
class MyArray {
private:
	T *arr;
	int length;
	int capacity;
	// 쓰지 못 할 함수는 미리 막아두기
	MyArray(const MyArray& copy) { }
	MyArray<T>& operator=(MyArray& copy) { return *this; }

public:
	MyArray(int cap = 100) : arr(0), length(0), capacity(cap)  {
		arr = new int[capacity];
	}

	virtual ~MyArray() {
		delete[] arr;
	}

	void push_back(T data) {
		if (length >= capacity) {
			cout << "size limit exception! (size = " << length << ", " << "capacity = " << capacity << ')' << endl;
			exit(1);
		}
		arr[length++] = data;
	}

	int size() const {
		return length;
	}

	// Array 객체가 const일 경우 호출
	T operator[](int idx) const {
		if (idx >= length) {
			cout << "array index out of bound exception! (" << idx << ")" << endl;
			exit(1);
		}
		return arr[idx];
	}

	// Array 객체가 const가 아닐 경우 호출
	T& operator[](int idx) {
		if (idx >= length) {
			cout << "array index out of bound exception! (" << idx << ")" << endl;
			exit(1);
		}
		return arr[idx];
	}
};

int main(void) {
	MyArray<int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}