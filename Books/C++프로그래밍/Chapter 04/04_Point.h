/************
<주소>		: p177
**********
<해결방안>	:
멤버 이니셜라이저(초기화 리스트) 테스트용
Point 헤더파일

**********
<오답노트>	:

*/

#ifndef __POINT_H_
#define __POINT_H_

class Point {
private:
	int x, y;

public:
	Point(const int &x, const int &y); // 전달하는 인자가 변하지 않음을 표시
	int getX() const;
	int getY() const;
	bool setX(const int &x);
	bool setY(const int &y);
};

#endif