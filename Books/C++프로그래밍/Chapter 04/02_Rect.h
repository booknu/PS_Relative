/************
<주소>		: p156 - 사각형 표현 중 Rect의 헤더파일
**********
<해결방안>	:

**********
<오답노트>	:

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