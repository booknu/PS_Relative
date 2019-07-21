/************
<�ּ�>		: p581
**********
<�ذ���>	:

�����Ϸ��� "Ŭ���� ���ø�" -> (������)"���ø� Ŭ����" �� ����� ������,
���� �ٸ� "���ø� Ŭ����"���, static ������ �������� �ʰ�, ���� ���� ������ �� ����.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

template <class T>
class Class {
public:
	static T mem;

public:
	void addMem(int n) { mem += n; }
	void print() { cout << mem << endl; }
};

template <class T>
T Class<T>::mem = 0; // static ��� �ʱ�ȭ

class Main {
public:
	static int main() {
		// int ���ø� Ŭ����
		Class<int> i1;
		Class<int> i2;
		i1.addMem(2);
		i2.addMem(3);
		i1.print();

		// long ���ø� Ŭ����
		Class<long> l1;
		Class<long> l2;
		l1.addMem(100);
		l2.addMem(200);
		l2.print();

		// �����Ϸ��� ���� "���ø� Ŭ����"�� �ٸ��Ƿ� static ��� ������ �������� �ʴ´�!

		return 0;
	}
};