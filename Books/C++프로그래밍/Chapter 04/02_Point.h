/************
<�ּ�>		: p153 - �簢�� ǥ�� �� Point�� �������
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#ifndef __POINT_H_
#define __POINT_H_

class Point {
private:
	int x, y;

public:
	bool init(int x, int y);
	// getX(), getY() �� const �Լ�
	// const �Լ��� �Լ����� ���º����� ���� �ٲ��� ���� (���� �ٲ�� ������ ���� �߻�)
	// ���� ��ü�� const�� ��������� const �Լ��� ��� ����
	// const ��ü�� ����ϴ� ������ ������(&)�� ����� �� ���� ���� �ٲ���� ���θ� �����ϱ� ����
	int getX() const;
	int getY() const;
	bool setX(int x);
	bool setY(int y);
	bool set(int x, int y);
};

#endif