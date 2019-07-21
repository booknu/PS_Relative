/************
<주소>		:
**********
<해결방안>	:

2차원 "객체 포인터 배열" 생성, 활용법
Obj*를 저장하는 배열 ==> Obj*를 typedef를 통해 OBJ_PTR로 선언하는 것도 좋은 방법

1. Obj ***arr; 형식으로 3차원 포인터 선언 (OBJ_PTR **arr;)

2. arr = new Obj**[y] 와 같이 행 할당 (new OBJ_PTR*[y])

3. arr[0, y) = new Obj*[x] 와 같이 열 할당 (new OBJ_PTR[x])

4. arr[y][x] = new Obj(생성자); 로 포인터가 가리키는 객체를 동적 할당 (객체의 "포인터" 이므로 실제 객체가 필요) 

5. arr[y][x]->~~~~ 로 객체 접근

6. delete[] arr[0, y) 로 열 해제

7. delete[] arr 로 행 해제

**********
<오답노트>	:

*/

#include <iostream>
#include <crtdbg.h>
using namespace std;

class Obj {
private:
	int num;

public:
	Obj(int num): num(num) { }
	
	int getNum() {
		return num;
	}
};

class Main {
public:
	// typedef를 사용하면 가독성 높아짐!
	typedef Obj* OBJ_PTR;

	static int main(void) {
		int x = 5, y = 10; // y = 행, x = 열

						   // 행 할당
		Obj ***objArr = new Obj**[y]; // OBJ_PTR **objArr = new OBJ_PTR*[y];
									  // 열 할당
		for (int i = 0; i < y; i++) {
			objArr[i] = new Obj*[x]; // objARr[i] = new OBJ_PTR[x];
		}

		// 2차원 배열 포인터당 각각 객체를 동적 생성
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				objArr[i][j] = new Obj(i * x + j);
			}
		}

		// 2차원 객체 포인터의 배열을 돌며 print
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << objArr[i][j]->getNum() << ' ';
			}
			cout << endl;
		}

		// 2차원 배열 포인터당 각각 객체를 메모리 해제
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				delete objArr[i][j];
			}
		}

		// delete
		for (int i = 0; i < y; i++) {
			delete[] objArr[i];
		}
		delete[] objArr;

		// 메모리 누수 확인
		_CrtDumpMemoryLeaks();

		return 0;
	}
};
