/************
<주소>		: p124 - 문제 1
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T>
void Copy(T* dest, T* src, int n) {
	for (int i = 0; i < n; i++) {
		//*(dest + i) = *(src + i);
		dest[i] = src[i];
	}
}

int main(void) {
	int src[] = { 10, 20, 30, 40, 50 };
	int dest[5];

	Copy(dest, src, 5);

	for (int i = 0; i < 5; i++) {
		cout << dest[i] << endl;
	}

	return 0;
}