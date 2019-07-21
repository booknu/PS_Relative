/************
<주소>		: p616
**********
<해결방안>	:

catch(...) {} 은 모든 예외를 잡아준다.
하지만, 예외에 대한 정보, 타입을 알 수 없다.

따라서 catch문 맨 마지막에 오는게 일반적이다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class MyException {
public:
	void printStackTrace() {
		cout << "My Exception!" << endl;
	}
};

class Main {
public:
	static void exception(int e) throw(MyException, int, double) {
		if (e == 0) {
			throw MyException();
		} else if(e == 1) {
			throw (int)2100000000;
		} else if (e == 2) {
			throw (double)0.00001;
		}
	}

	static int main() {
		try {
			exception(0);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "예외: " << e << endl;
		} catch (...) {
			// 어떤 예외든 다 잡아줌!
			// but, 정보를 받을 수 없으며, 전달된 예외 종류도 구분 불가!
			cout << "알 수 없는 예외 발생!" << endl;
		}

		try {
			exception(1);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "예외: " << e << endl;
		} catch (...) {
			// 어떤 예외든 다 잡아줌!
			// but, 정보를 받을 수 없으며, 전달된 예외 종류도 구분 불가!
			cout << "알 수 없는 예외 발생!" << endl;
		}

		try {
			exception(2);
		} catch (MyException e) {
			e.printStackTrace();
		} catch (double e) {
			cout << "예외: " << e << endl;
		} catch (...) {
			// 어떤 예외든 다 잡아줌!
			// but, 정보를 받을 수 없으며, 전달된 예외 종류도 구분 불가!
			cout << "알 수 없는 예외 발생!" << endl;
		}
		return 0;
	}
};