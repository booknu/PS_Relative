///************
//<�ּ�>		: p92
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
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
//	///// char*�� ���� �Ҵ� /////
//	char *str = makeStrAdr(20);
//	strcpy_s(str, 19, "i am so happy~");
//	cout << str << endl;
//	delete []str; // �ʼ������� delete�� �ؾ���
//
//	///// int �迭�� ���� �Ҵ� /////
//	int *arr = makeIntArr(3);
//	arr[0] = 100;
//	arr[1] = 200;
//	for (int i = 0; i < 3; i++) {
//		cout << arr[i] << ' ';
//	}
//	delete []arr; // �ʼ������� delete�� �ؾ���
//	cout << endl;
//	return 0;
//}