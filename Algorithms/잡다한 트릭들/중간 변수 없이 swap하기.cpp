// xor�� ���� ���� ¦���� xor�Ǹ� �� ���� xor ���� ���� �Ͱ� ���ٴ� Ư¡�� �ִ�.
// ��, a ^ b ^ b = a
// �̰� �̿��� a ^= b�� a�� a, b ������ �־����,
// b ^= a�� b�� �ִ� b ������ �����ܰ� ���ÿ� a�� �־��ְ�,
// a ^= b�� a�� �ִ� a^b���� a�� �����ְ� b�� ���� ��.
#include <iostream>
using namespace std;
int main(void) {
	int a = 30, b = 50;
	a ^= b, b ^= a, a ^= b; // swap(a, b)
}