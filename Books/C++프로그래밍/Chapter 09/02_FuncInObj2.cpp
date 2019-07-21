///************
//<주소>		: p377
//**********
//<해결방안>	:
//
//멤버 함수가 실제로 어디에 존재하는지 알기 위함.
//Struct와 Function Pointer을 통해 Class를 흉내냄
//
//실제로 객체는 이와 같이 멤버 함수는 메모리 내의 다른 공간에 있고,
//여러 객체가 이를 공유하는 구조이다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//typedef struct Data {
//	int data;
//
//	// 함수 포인터를 통해 멤버함수 흉내
//	void(*print)(Data *data); 
//	void(*add)(Data *data, int n);
//} Data;
//
//void print(Data *THIS) {
//	cout << "data: " << THIS->data << endl;
//}
//
//void add(Data *THIS, int n) {
//	THIS->data += n;
//}
//
//int main() {
//	Data o1 = { 15, print, add }; // 구조체를 선언할 때 함수 포인터도 같이 넘겨줘야 함
//	Data o2 = { 7, print, add };
//
//	o1.add(&o1, 17);
//	o2.add(&o2, 9);
//	o1.print(&o1);
//	o2.print(&o2);
//	return 0;
//}