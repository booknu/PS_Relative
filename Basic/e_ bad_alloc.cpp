/************
<주소>		: p615
**********
<해결방안>	:

new 연산을 할 때
메모리 공간 할당이 실패하면 "bad_alloc" 이라는 예외가 발생한다.
==> 자바의 Heap Space Exception과 비슷?

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		int n = 0;

		try {
			// 무작정 heap 공간에 메모리를 할당하고 있다.
			// heap이 부족해지면 new 연산이 bad_alloc을 발생시킬 것이다.
			while (1) {
				n++;
				cout << n << "번째 할당 시도" << endl;
				new int[10000][10000];
			}
		} catch (bad_alloc &e) {
			cout << e.what() << endl;
			cout << "더 이상 할당 불가!" << endl;
		}

		return 0;
	}
};