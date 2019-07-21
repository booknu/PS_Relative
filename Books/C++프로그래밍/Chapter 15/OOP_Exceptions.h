/************
<�ּ�>		: p618 - OOP ������Ʈ 11�ܰ�
**********
<�ذ���>	:

�������� Exception Class���� ����

**********
<�����Ʈ>	:

*/

#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <string>
using namespace std;

/**
 *	�⺻ ���� Ŭ����
 */
class Exception {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	���� ���� ����ϴ� ���� �ƴ� ��
 */
class IllegalArgumentException : public Exception {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	���� ���� ������ ��
 */
class NegativeArgumentException : public IllegalArgumentException {
public:
	virtual void printStackTrace(char *msg);
};

/**
 *	���ѵ� ���� �Ѿ��� ��
 */
class LimitExceedException : public IllegalArgumentException {
public:
	virtual void printStackTrace(char *msg);
};

#endif