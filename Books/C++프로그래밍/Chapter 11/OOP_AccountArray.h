/************
<주소>		: p494 - OOP 프로젝트 8단계
**********
<해결방안>	:

Account 객체들을 저장하기 위한 Array 클래스

**********
<오답노트>	:

1. [] 연산자를 오버로딩 할 때 반환형을 어떻게 할 지 헤멨음
   처음에는 Account&를 반환하게 만들었는데, 배열에 넣을 때 new 를 통해 넣는다는 것을 깨닫고
   Account*을 반환하게 만들었지만,
   이 경우는 반환된 포인터로 값을 수정하지 못하는 문제가 있었음.
   ==> 값을 수정하게 하려고 ACC_PTR&를 반환하게 만듬

*/

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "OOP_Account.h"
typedef Account* ACC_PTR;

class AccountArray {
private:
	ACC_PTR *arr;
	// 사용해서는 안 될 복사 생성자, 대입 연산자
	AccountArray(const AccountArray &copy);
	AccountArray& operator=(const AccountArray &copy);

public:
	const int length;

public:
	AccountArray(int length);

	// [] 연산자 오버로딩
	// 수정 가능하게 하려면 ACC_PTR& 를 반환시켜야 함!!!!
	ACC_PTR& operator[](int index);
	ACC_PTR operator[](int index) const;

	~AccountArray();
};

#endif