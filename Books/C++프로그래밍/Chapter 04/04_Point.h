/************
<�ּ�>		: p177
**********
<�ذ���>	:
��� �̴ϼȶ�����(�ʱ�ȭ ����Ʈ) �׽�Ʈ��
Point �������

**********
<�����Ʈ>	:

*/

#ifndef __POINT_H_
#define __POINT_H_

class Point {
private:
	int x, y;

public:
	Point(const int &x, const int &y); // �����ϴ� ���ڰ� ������ ������ ǥ��
	int getX() const;
	int getY() const;
	bool setX(const int &x);
	bool setY(const int &y);
};

#endif