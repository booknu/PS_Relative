///************
//<주소>		: p235
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Temp {
//private:
//	int num;
//
//public:
//	Temp(int n) : num(n) {
//		cout << "create obj: " << num << endl;
//	}
//
//	~Temp() {
//		cout << "destroy obj: " << num << endl;
//	}
//
//	void print() {
//		cout << "[print] num = " << num << endl;
//	}
//};
//
//int main(void) {
//	Temp(100); // 임시 객체를 생성은 했으나, 그것을 참조하는 것이 없음! (생성되자마자 삭제)
//	cout << "----- after make -----" << endl << endl;
//
//	Temp(200).print();
//	cout << "----- after make -----" << endl << endl;
//
//	const Temp &ref = Temp(300); // 임시 객체를 생성했고, 그것을 참조하는 ref가 있기 때문에 살아남음! 
//	cout << "----- end of main -----" << endl << endl;
//
//	// Temp(100)은 임시 객체인데, 이것은 참조자가 반환됨.
//	// 임시 객체를 참조할 참조자가 없으면 삭제됨
//
//	// 이 결과를 보면 Temp t = Temp(100);과 같이 선언 가능! (t가 Temp(100)의 참조자가 됨)
//	// Temp *t = &Temp(100); 의 경우는 Temp(100)을 참조할 수 있는 참조자가 없기 때문에 다음 행에 바로 소멸됨
//	// Temp &t = Temp(100); 은 참조자 t에 참조되는 임시객체이기 때문에 소멸되지 않음
//
//	return 0;
//}