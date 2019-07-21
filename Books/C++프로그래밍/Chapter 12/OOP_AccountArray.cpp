/************
<주소>		: p515 - OOP 프로젝트 9단계
**********
<해결방안>	:

**********
<오답노트>	:

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

// 접근, 수정 가능
ACC_PTR& AccountArray::operator[](int index) {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

// 접근만 가능
ACC_PTR AccountArray::operator[](int index) const {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

AccountArray::~AccountArray() {
	// Account 배열 지우기
	delete[] arr;
}