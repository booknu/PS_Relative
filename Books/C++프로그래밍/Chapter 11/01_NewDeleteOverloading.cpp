///************
//<주소>		: p473
//**********
//<해결방안>	:
//
//new, delete 연산자의 오버로딩
//new:	메모리 공간의 할당만을 오버로딩 가능 ( void* operator new(size_t size) {} )
//delete: 메모리 공간의 해제만을 오버로딩 가능 ( void operator delete(void* adr) {} )
//==> size_t 는 typedef unsigned int size_t
//
//이 둘은 객체의 멤버 함수이지만, static 함수이기 때문에 객체 생성 전 호출이 가능하다.
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
//	/*
//		new 연산자의 오버로딩은 메모리 공간의 할당만을 오버로딩 할 수 있다.
//		(그 뒤에 일어나는 생성자 호출, 반환된 주소의 형변환은 컴파일러 수준에서 한다.)
//		이 함수는 멤버함수지만, static 함수이다.
//
//		@param size: 할당할 unsigned int형 size (byte 단위)
//		@return: 할당된 메모리를 가리키는 void 포인터
//	*/
//	void* operator new(size_t size) {
//		cout << "operator new: " << size << endl;
//		void *adr = new char[size]; // size가 size byte 만큼 메모리를 할당하라는 뜻이니까, 1byte인 char의 배열을 이용해 메모리 할당
//		return adr;
//	}
//
//	/*
//		delete 연산자의 오버로딩은 메모리 공간의 해제만을 오버로딩 할 수 있다.
//		(그 전에 일어나는 소멸자 호출은 컴파일러 수준에서 한다.)
//		이 함수는 멤버함수지만, static 함수이다.
//
//		@param adr: 해제할 메모리 주소를 가리키는 void형 포인터
//	*/
//	void operator delete(void *adr) {
//		cout << "operator delete" << endl;
//		delete[] adr; // delete[] 를 사용한 것에 주의!
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
//	cout << *ptr << endl;
//	delete ptr;
//
//	// stack에 할당할 때는 사용 안 됨
//	Point p(3, 4);
//	return 0;
//}