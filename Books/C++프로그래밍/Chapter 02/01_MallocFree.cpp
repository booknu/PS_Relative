///************
//<주소>		: p91
//**********
//<해결방안>	:
//
//void* malloc(int bytes): bytes만큼의 메모리를 할당하고, 그 첫 주소를 void*로 반환
//void* calloc(int len, int typesize): len * typesize 만큼의 메모리를 할당하고, 그 첫 주소를 void*로 반환
//									 할당된 공간의 값을 모두 0으로 바꾼다.
//void* realloc(void* memblock, int bytes): 이미 할당된 공간의 크기를 바꾼다.
//void free(void* ptr): 힙에 할당된 메모리를 해제한다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//
//using namespace std;
//
//char* makestradr(int len) {
//	char *str = (char*)malloc(sizeof(char) * len); // return 형이 void* 이기 때문에 형변환을 해서 사용해야 함
//	return str;
//}
//
//int* makeintarr(int len) {
//	int *arr = (int*)malloc(sizeof(int) * len);
//	return arr;
//}
//
//int main(void) {
//	///// char*을 동적 할당 /////
//	char *str = makestradr(20);
//	strcpy_s(str, 19, "i am so happy~");
//	cout << str << endl;
//	free(str); // 필수적으로 free를 해야함
//
//	///// int 배열을 동적 할당 /////
//	int *arr = makeintarr(3);
//	arr[0] = 100;
//	arr[1] = 200;
//	for (int i = 0; i < 3; i++) {
//		cout << arr[i] << ' ';
//	}
//	free(arr); // 필수적으로 free를 해야함
//	cout << endl;
//	return 0;
//}