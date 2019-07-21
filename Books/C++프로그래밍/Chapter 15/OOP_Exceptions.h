/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

던져지는 Exception Class들을 관리

**********
<오답노트>	:

*/

#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <string>
using namespace std;

/**
 *	기본 예외 클래스
 */
class Exception {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	인자 값이 기대하던 값이 아닐 때
 */
class IllegalArgumentException : public Exception {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	인자 값이 음수일 때
 */
class NegativeArgumentException : public IllegalArgumentException {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	제한된 값을 넘었을 때
 */
class LimitExceedException : public IllegalArgumentException {
public:
	virtual void printStackTrace(char *msg);
};

#endif