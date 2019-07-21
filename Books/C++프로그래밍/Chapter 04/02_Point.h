/************
<주소>		: p153 - 사각형 표현 중 Point의 헤더파일
**********
<해결방안>	:

**********
<오답노트>	:

*/

#ifndef __POINT_H_
#define __POINT_H_

class Point {
private:
	int x, y;

public:
	bool init(int x, int y);
	// getX(), getY() 는 const 함수
	// const 함수는 함수에서 상태변수의 값이 바뀌지 않음 (만약 바뀌면 컴파일 에러 발생)
	// 만약 객체가 const로 선언됐을시 const 함수만 사용 가능
	// const 객체를 사용하는 이유는 참조자(&)를 사용할 때 원본 값이 바뀌는지 여부를 구분하기 위함
	int getX() const;
	int getY() const;
	bool setX(int x);
	bool setY(int y);
	bool set(int x, int y);
};

#endif