/************
<�ּ�>		: p178
**********
<�ذ���>	:
��� �̴ϼȶ�����(�ʱ�ȭ ����Ʈ) �׽�Ʈ��
Rect �������

**********
<�����Ʈ>	:

*/

#ifndef __RECT_H_
#define __RECT_H_

#include "06_Point.h"

class Rect {
private:
	Point upLeft;
	Point downRight;

public:
	Rect(const int &ulX, const int &ulY, const int &drX, const int &drY);
	void print() const;
};

#endif