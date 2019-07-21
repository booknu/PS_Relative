///************
//<주소>		: p376
//**********
//<해결방안>	:
//
//멤버 함수가 실제로 어디에 존재하는지 알기 위함
//최대한 간단한 클래스
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Data {
//private:
//	int data;
//
//public:
//	Data(int d) : data(d) { }
//	void print() const { cout << "Data: " << data << endl; }
//	void add(int n) { data += n; }
//};
//
//int main() {
//	Data obj(100);
//	obj.add(30);
//	obj.print();
//
//	return 0;
//}