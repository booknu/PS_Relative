///************
//<주소>		:
//**********
//<해결방안>	:
//
//3차원 "객체 배열" 생성, 활용법
//
//1. Obj ***arr; 형식으로 3차원 포인터 선언
//
//2. arr = new Obj**[z] 와 같이 가장 외부 배열 할당
//
//3. arr[0, z) = new Obj*[y] 와 같이 중간 배열 할당
//
//4. arr[0, z)[0, y) = new Obj[x] 와 같이 가장 안쪽 배열 할당 (이 때, 1차원 객체 배열을 할당하는 것과 같으므로 생성자 호출됨)
//
//5. arr[z][y][x].~~~~ 로 객체 접근
//
//6. delete[] arr[0, z)[0, y) 와 같이 가장 안쪽 배열 해제
//
//7. delete[] arr[0, z) 와 같이 중간 배열 해제
//
//8. delete[] arr 과 같이 가장 바깥 배열 해제
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
//	Obj() : num(-1) { } // 기본 생성자 (객체 배열 선언 시 자동 호출)
//	Obj(int num) : num(num) { }
//
//	int getNum() const {
//		return num;
//	}
//
//	void setNum(int n) {
//		num = n;
//	}
//
//	~Obj() {
//		cout << num << ' ';
//	}
//};
//
//int main(void) {
//	int x = 5, y = 10, z = 3;
//
//	// z 할당
//	Obj *** objArr = new Obj**[z];
//	// y 할당
//	for (int i = 0; i < z; i++) {
//		objArr[i] = new Obj*[y];
//	}
//	// x 할당
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			objArr[i][j] = new Obj[x]; // 기본 생성자가 호출됨!
//		}
//	}
//
//	// 3차원 객체 배열을 돌며 set
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			for (int k = 0; k < x; k++) {
//				objArr[i][j][k].setNum(i * y * x + j * x + k);
//			}
//		}
//	}
//
//	// 3차원 객체 배열을 돌며 print
//	for (int i = 0; i < z; i++) {
//		cout << "<< z = " << i << " >>" << endl;
//		for (int j = 0; j < y; j++) {
//			for (int k = 0; k < x; k++) {
//				cout << objArr[i][j][k].getNum() << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//	}
//
//	cout << "[ destructor called ]" << endl;
//	// delete x
//	for (int i = 0; i < z; i++) {
//		for (int j = 0; j < y; j++) {
//			delete[] objArr[i][j];
//		}
//	}
//	// delete y
//	for (int i = 0; i < z; i++) {
//		delete[] objArr[i];
//	}
//	// delete z
//	delete[] objArr;
//}