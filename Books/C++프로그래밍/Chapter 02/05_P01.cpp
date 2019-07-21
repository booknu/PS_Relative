///************
//<주소>		: p95
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//1. 함수 내부에서 지역변수에 대한 참조자를 반환하면 지역변수는 사라져 오류가 발생한다고 알고 있는데,
//   이것 때문에 지역변수 POINT *ret에 대한 참조자를 반환하는 것이 되는지에 대해 의문이 들었지만,
//   이 경우는 Stack이 아닌 Heap에 메모리 할당이 되므로 함수가 끝나도 메모리는 살아남는다는 것을 깨닫게 됨
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//typedef struct {
//	int y, x;
//} POINT;
//
//POINT& pntAdder(const POINT &p1, const POINT &p2) {
//	POINT *ret = new POINT; // ret은 heap에 할당되었으므로 함수가 종료되도 사라지지 않음!
//							// 따라서 이것을 함수 외부에서 참조자로 이름을 붙여 사용해도 무방!
//							// but 사용을 다 하고 난 뒤에는 반드시 delete를 해줘야 메모리에서 사라짐!
//	ret->x = p1.x + p2.x;
//	ret->y = p1.y + p2.y;
//	return *ret;
//}
//
//int main(void) {
//	POINT *p1 = new POINT;
//	POINT *p2 = new POINT;
//	p1->x = 1;
//	p1->y = 2;
//
//	p2->x = 10;
//	p2->y = 20;
//
//	cout << "p1: (" << p1->x << ", " << p1->y << ")" << endl;
//	cout << "p2: (" << p2->x << ", " << p2->y << ")" << endl;
//	POINT &added = pntAdder(*p1, *p2);
//	cout << "added: (" << added.x << ", " << added.y << ")" << endl;
//	delete p1, p2, added;
//}