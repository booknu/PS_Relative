///************
//<�ּ�>		: p91
//**********
//<�ذ���>	:
//
//void* malloc(int bytes): bytes��ŭ�� �޸𸮸� �Ҵ��ϰ�, �� ù �ּҸ� void*�� ��ȯ
//void* calloc(int len, int typesize): len * typesize ��ŭ�� �޸𸮸� �Ҵ��ϰ�, �� ù �ּҸ� void*�� ��ȯ
//									 �Ҵ�� ������ ���� ��� 0���� �ٲ۴�.
//void* realloc(void* memblock, int bytes): �̹� �Ҵ�� ������ ũ�⸦ �ٲ۴�.
//void free(void* ptr): ���� �Ҵ�� �޸𸮸� �����Ѵ�.
//
//**********
//<�����Ʈ>	:
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
//	char *str = (char*)malloc(sizeof(char) * len); // return ���� void* �̱� ������ ����ȯ�� �ؼ� ����ؾ� ��
//	return str;
//}
//
//int* makeintarr(int len) {
//	int *arr = (int*)malloc(sizeof(int) * len);
//	return arr;
//}
//
//int main(void) {
//	///// char*�� ���� �Ҵ� /////
//	char *str = makestradr(20);
//	strcpy_s(str, 19, "i am so happy~");
//	cout << str << endl;
//	free(str); // �ʼ������� free�� �ؾ���
//
//	///// int �迭�� ���� �Ҵ� /////
//	int *arr = makeintarr(3);
//	arr[0] = 100;
//	arr[1] = 200;
//	for (int i = 0; i < 3; i++) {
//		cout << arr[i] << ' ';
//	}
//	free(arr); // �ʼ������� free�� �ؾ���
//	cout << endl;
//	return 0;
//}