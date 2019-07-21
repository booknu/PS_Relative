// xor은 같은 수가 짝수번 xor되면 그 수가 xor 되지 않은 것과 같다는 특징이 있다.
// 즉, a ^ b ^ b = a
// 이걸 이용해 a ^= b로 a에 a, b 정보를 넣어놓고,
// b ^= a로 b에 있는 b 정보를 지워줌과 동시에 a를 넣어주고,
// a ^= b로 a에 있는 a^b에서 a를 지워주고 b만 남게 됨.
#include <iostream>
using namespace std;
int main(void) {
	int a = 30, b = 50;
	a ^= b, b ^= a, a ^= b; // swap(a, b)
}