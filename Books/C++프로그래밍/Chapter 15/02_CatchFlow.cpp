/************
<주소>		: p612
**********
<해결방안>	:

try-다중catch 문에서
try에서 Exception이 발생한 경우

해당 Exception과 호환되는 catch문을 찾을 때까지 밑으로 내려간다.
만약 찾으면, 해당 catch문에서 처리가 되고 예외처리가 끝난다.
만약 못 찾으면, Stack Unwinding까지 하면서 찾는다.

[ 상속 관계에 있는 예외를 catch 하려면? ]
catch Base
catch Derived
와 같이 해버리면, Derived 예외가 던져져도 Base에서 catch가 된다.

따라서
catch Derived
catch Base
와 같이 Base Exception은 catch문들 중 가장 아래에 있는게 좋다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class AAA {
public:
	void printStackTrace() {
		cout << "AAA Excpetion!" << endl;
	}
};

class BBB : public AAA {
public:
	void printStackTrace() {
		cout << "BBB Excpetion!" << endl;
	}
};

class CCC : public BBB {
public:
	void printStackTrace() {
		cout << "CCC Excpetion!" << endl;
	}
};

class Main {
public:
	static void exceptionGenerator(int e) {
		switch (e) {
		case 1:
			throw AAA();
		case 2:
			throw BBB();
		case 3:
			throw CCC();
		}
	}

	static int main() {
		try {
			exceptionGenerator(3);
			exceptionGenerator(2);
			exceptionGenerator(1);
		} catch (AAA e) {
			// CCC 예외가 던져졌지만, CCC가 AAA 클래스를 상속하고 있기 때문에 여기서 걸림
			// 따라서 Base Exception은 catch문들 중 가장 아래 두는게 좋음!
			cout << "catch (AAA e)" << endl;
			e.printStackTrace();
		} catch (BBB e) {
			cout << "catch (BBB e)" << endl;
			e.printStackTrace();
		} catch (CCC e) {
			cout << "catch (CCC e)" << endl;
			e.printStackTrace();
		}
		

		return 0;
	}
};