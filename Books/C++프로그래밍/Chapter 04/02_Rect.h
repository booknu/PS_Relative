/************
<�ּ�>		: p156 - �簢�� ǥ�� �� Rect�� �������
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#ifndef __RECT_H_
#define __RECT_H_

#include "02_Point.h"

class Rect {
private:
	Point upLeft, downRight;

public:
	bool init(const Point &ul, const Point &dr);
	void showInfo() const;
};

#endif