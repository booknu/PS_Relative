/************
<�ּ�>		: p515 - OOP ������Ʈ 9�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include "OOP_AccountArray.h"
#include <cstdlib>
#include <iostream>
using namespace std;

AccountArray::AccountArray(const AccountArray &copy) : length(0) { }
AccountArray& AccountArray::operator=(const AccountArray &copy) { return *this; }

AccountArray::AccountArray(int length) : length(length) {
	arr = new ACC_PTR[length];
}

// ����, ���� ����
ACC_PTR& AccountArray::operator[](int index) {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

// ���ٸ� ����
ACC_PTR AccountArray::operator[](int index) const {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

AccountArray::~AccountArray() {
	// Account �迭 �����
	delete[] arr;
}