/************
<주소>		: p581
**********
<해결방안>	:

컴파일러는 "클래스 템플릿" -> (여러개)"템플릿 클래스" 를 만들기 때문에,
서로 다른 "템플릿 클래스"라면, static 변수를 공유하지 않고, 또한 서로 접근할 수 없다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <class T>
class Class {
public:
	static T mem;

public:
	void addMem(int n) { mem += n; }
	void print() { cout << mem << endl; }
};

template <class T>
T Class<T>::mem = 0; // static 멤버 초기화

class Main {
public:
	static int main() {
		// int 템플릿 클래스
		Class<int> i1;
		Class<int> i2;
		i1.addMem(2);
		i2.addMem(3);
		i1.print();

		// long 템플릿 클래스
		Class<long> l1;
		Class<long> l2;
		l1.addMem(100);
		l2.addMem(200);
		l2.print();

		// 컴파일러가 만든 "템플릿 클래스"가 다르므로 static 멤버 변수를 공유하지 않는다!

		return 0;
	}
};