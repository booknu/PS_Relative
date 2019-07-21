/************
<주소>		: p574, 576
**********
<해결방안>	:

템플릿의 파라미터에 변수가 올 수 있다.

이것은 생성자를 간결하게 만들어줄 수도 있고,
특정 조건에 맞춰 함수의 인자를 받아들일 수도 있다.
(변수에 따라, 변수 값이 다르면 다른 type이다.)

또한 이 파라미터는 default 값을 지정할 수 있다!

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

// 템플릿 파라미터에 변수 올 수 있음!
// 또한 default값 지정 가능!
template <class T = int, int len = 7>
class Array {
private:
	T arr[len]; // 생성자가 필요 없어졌다, 또한 stack에도 할당 가능하다.

public:
	T& operator[](int index) {
		return arr[index];
	}

	T operator[](int index) const {
		return arr[index];
	}

	/**
	 *	len 길이가 같은 배열만 복사할 수 있게 할 수 있다! (len 길이가 다르면 다른 type이다.)
	 *	그 외의 경우는 컴파일 에러로 처리 할 수 있다.
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

//		i5Arr1 = i7Arr1; 는 컴파일러 차원에서 에러를 발생시켜준다!

		return 0;
	}
};