/************
<�ּ�>		: p574, 576
**********
<�ذ���>	:

���ø��� �Ķ���Ϳ� ������ �� �� �ִ�.

�̰��� �����ڸ� �����ϰ� ������� ���� �ְ�,
Ư�� ���ǿ� ���� �Լ��� ���ڸ� �޾Ƶ��� ���� �ִ�.
(������ ����, ���� ���� �ٸ��� �ٸ� type�̴�.)

���� �� �Ķ���ʹ� default ���� ������ �� �ִ�!

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

// ���ø� �Ķ���Ϳ� ���� �� �� ����!
// ���� default�� ���� ����!
template <class T = int, int len = 7>
class Array {
private:
	T arr[len]; // �����ڰ� �ʿ� ��������, ���� stack���� �Ҵ� �����ϴ�.

public:
	T& operator[](int index) {
		return arr[index];
	}

	T operator[](int index) const {
		return arr[index];
	}

	/**
	 *	len ���̰� ���� �迭�� ������ �� �ְ� �� �� �ִ�! (len ���̰� �ٸ��� �ٸ� type�̴�.)
	 *	�� ���� ���� ������ ������ ó�� �� �� �ִ�.
	 */
	Array<T, len>& operator=(const Array<T, len> &copy) {
		for (int i = 0; i < len; i++) {
			arr[i] = copy[i];
		}
		return *this;
	}

};

class Main {
public:
	static int main() {
		Array<int, 5> i5Arr1;
		for (int i = 0; i < 5; i++) {
			i5Arr1[i] = i;
		}

		Array<int, 5> i5Arr2;
		i5Arr2 = i5Arr1;
		for (int i = 0; i < 5; i++) {
			cout << i5Arr2[i] << ' ';
		}
		cout << endl;

		Array<int, 7> i7Arr1;
		for (int i = 0; i < 7; i++) {
			i7Arr1[i] = i * 10;
		}

		Array<int, 7> i7Arr2;
		i7Arr2 = i7Arr1;
		for (int i = 0; i < 7; i++) {
			cout << i7Arr2[i] << ' ';
		}
		cout << endl;

//		i5Arr1 = i7Arr1; �� �����Ϸ� �������� ������ �߻������ش�!

		return 0;
	}
};