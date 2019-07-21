/************
<주소>		: p106
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
private:
	T *arr;
	int size;
	int cap;
	
public:
	explicit Array(int cap = 100) : cap(cap), size(0) {
		arr = new T[cap];
	}

	~Array() {
		delete[] arr;
	}

	void Add(T data) {
		arr[size++] = data;
	}

	T& operator[](int idx) {
		if (idx >= size || idx < 0) {
			cout << "Array Index Out of Bound Exception" << endl;
		}
		return arr[idx];
	}

	T operator[](int idx) const {
		if (idx >= size || idx < 0) {
			cout << "Array Index Out of Bound Exception" << endl;
		}
		return arr[idx];
	}

	int Size() const {
		return size;
	}
};

int main(void) {
	Array<int> iarr;
	iarr.Add(10);
	iarr.Add(20);
	iarr.Add(30);

	for (int i = 0; i < iarr.Size(); i++) {
		cout << iarr[i] << " ";
	}
	cout << endl;

	Array<string> sarr;
	sarr.Add("ABC");
	sarr.Add("가나다");
	sarr.Add("FDS");

	for (int i = 0; i < sarr.Size(); i++) {
		cout << sarr[i] << " ";
	}
	cout << endl;

	return 0;
}