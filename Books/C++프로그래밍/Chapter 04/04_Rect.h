/************
<주소>		: p178
**********
<해결방안>	:
멤버 이니셜라이저(초기화 리스트) 테스트용
Rect 헤더파일

**********
<오답노트>	:

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