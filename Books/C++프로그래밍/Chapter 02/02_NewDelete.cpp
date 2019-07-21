///************
//<주소>		: p92
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//char* makeStrAdr(int len) {
//	char *str = new char[len];
//	return str;
//}
//
//int* makeIntArr(int len) {
//	int *arr = new int[len];
//	return arr;
//}
//
//int main(void) {
//	///// char*을 동적 할당 /////
//	char *str = makeStrAdr(20);
//	strcpy_s(str, 19, "i am so happy~");
//	cout << str << endl;
//	delete []str; // 필수적으로 delete를 해야함
//
//	///// int 배열을 동적 할당 /////
//	int *arr = makeIntArr(3);
//	arr[0] = 100;
//	arr[1] = 200;
//	for (int i = 0; i < 3; i++) {
//		cout << arr[i] << ' ';
//	}
//	delete []arr; // 필수적으로 delete를 해야함
//	cout << endl;
//	return 0;
//}