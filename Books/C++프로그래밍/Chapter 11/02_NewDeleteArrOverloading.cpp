///************
//<주소>		: p476
//**********
//<해결방안>	:
//
//new[], delete[] 연산자의 오버로딩
//new[]:		배열 할당 시 호출
//delete[]:	배열 소멸 시 호출
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	friend ostream& operator<<(ostream &os, Point &p);
//
//	/**
//	 * new 연산자의 오버로딩은 메모리 공간의 할당만을 오버로딩 할 수 있다.
//	 *
//	 * @param size: 할당할 unsigned int형 size (byte 단위)
//	 * @return: 할당된 메모리를 가리키는 void 포인터
//	 */
//	void* operator new(size_t size) {
//		cout << "operator new: " << size << endl;
//		void *adr = new char[size]; // size가 size byte 만큼 메모리를 할당하라는 뜻이니까, 1byte인 char의 배열을 이용해 메모리 할당
//		return adr;
//	}
//
//	/**
//	 * delete 연산자의 오버로딩은 메모리 공간의 해제만을 오버로딩 할 수 있다.
//	 * 
//	 * @param adr: 해제할 메모리 주소를 가리키는 void형 포인터
//	 */
//	void operator delete(void *adr) {
//		cout << "operator delete" << endl;
//		delete[] adr; // delete[] 를 사용한 것에 주의!
//	}
//
//	/**
//	 * new[] 연산자의 오버로딩 (배열 할당 시 호출)
//	 * 
//	 * @param size: 할당할 unsigned int형 size (byte 단위)
//	 * @return 할당된 메모리를 가리키는 void 포인터
//	 */
//	void* operator new[](size_t size) {
//		cout << "operator new[]: " << size << endl;
//		void *adr = new char[size];
//		return adr;
//	}
//
//	/**
//	 * delete[] 연산자의 오버로딩 (배열 소멸 시 호출)
//	 * 
//	 * @param adr: 소멸할 메모리 주소
//	 */
//	void operator delete[](void *adr) {
//		cout << "operator delete[]" << endl;
//		delete[] adr;
//	}
//};
//
//ostream& operator<<(ostream &os, Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
//int main() {
//	// heap에 할당할 때만 new delete 연산자 사용됨
//	Point *ptr = new Point(3, 4);
//	Point *arr = new Point[3];
//	delete ptr;
//	delete[] arr;
//
//	return 0;
//}