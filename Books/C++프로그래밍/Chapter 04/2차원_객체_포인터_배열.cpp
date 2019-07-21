///************
//<주소>		:
//**********
//<해결방안>	:
//
//2차원 "객체 포인터 배열" 생성, 활용법
//
//1. Obj ***arr; 형식으로 3차원 포인터 선언
//
//2. arr = new **[y] 와 같이 행 할당
//
//3. arr[0, y) = new *[x] 와 같이 열 할당
//
//4. arr[y][x] = new Obj(생성자); 로 포인터가 가리키는 객체를 동적 할당 (객체의 "포인터" 이므로 실제 객체가 필요) 
//
//5. arr[y][x]->~~~~ 로 객체 접근
//
//6. delete[] arr[0, y) 로 열 해제
//
//7. delete[] arr 로 행 해제
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Obj {
//private:
//	int num;
//
//public:
//	Obj(int num): num(num) { }
//	
//	int getNum() {
//		return num;
//	}
//};
//
//int main(void) {
//	int x = 5, y = 10; // y = 행, x = 열
//
//	// 행 할당
//	Obj *** objArr = new Obj**[y];
//	// 열 할당
//	for (int i = 0; i < y; i++) {
//		objArr[i] = new Obj*[x];
//	}
//
//	// 2차원 배열 포인터당 각각 객체를 동적 생성
//	for (int i = 0; i < y; i++) {
//		for (int j = 0; j < x; j++) {
//			objArr[i][j] = new Obj(i * x + j);
//		}
//	}
//
//	// 2차원 객체 포인터의 배열을 돌며 print
//	for (int i = 0; i < y; i++) {
//		for (int j = 0; j < x; j++) {
//			cout << objArr[i][j]->getNum() << ' ';
//		}
//		cout << endl;
//	}
//
//	// delete
//	for (int i = 0; i < y; i++) {
//		delete[] objArr[i];
//	}
//	delete[] objArr;
//}