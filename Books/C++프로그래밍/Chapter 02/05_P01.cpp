///************
//<�ּ�>		: p95
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//1. �Լ� ���ο��� ���������� ���� �����ڸ� ��ȯ�ϸ� ���������� ����� ������ �߻��Ѵٰ� �˰� �ִµ�,
//   �̰� ������ �������� POINT *ret�� ���� �����ڸ� ��ȯ�ϴ� ���� �Ǵ����� ���� �ǹ��� �������,
//   �� ���� Stack�� �ƴ� Heap�� �޸� �Ҵ��� �ǹǷ� �Լ��� ������ �޸𸮴� ��Ƴ��´ٴ� ���� ���ݰ� ��
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//typedef struct {
//	int y, x;
//} POINT;
//
//POINT& pntAdder(const POINT &p1, const POINT &p2) {
//	POINT *ret = new POINT; // ret�� heap�� �Ҵ�Ǿ����Ƿ� �Լ��� ����ǵ� ������� ����!
//							// ���� �̰��� �Լ� �ܺο��� �����ڷ� �̸��� �ٿ� ����ص� ����!
//							// but ����� �� �ϰ� �� �ڿ��� �ݵ�� delete�� ����� �޸𸮿��� �����!
//	ret->x = p1.x + p2.x;
//	ret->y = p1.y + p2.y;
//	return *ret;
//}
//
//int main(void) {
//	POINT *p1 = new POINT;
//	POINT *p2 = new POINT;
//	p1->x = 1;
//	p1->y = 2;
//
//	p2->x = 10;
//	p2->y = 20;
//
//	cout << "p1: (" << p1->x << ", " << p1->y << ")" << endl;
//	cout << "p2: (" << p2->x << ", " << p2->y << ")" << endl;
//	POINT &added = pntAdder(*p1, *p2);
//	cout << "added: (" << added.x << ", " << added.y << ")" << endl;
//	delete p1, p2, added;
//}