/************
<�ּ�>		: p535 - ���� 1
**********
<�ذ���>	:

�����ͷ� Swap, �����ڷ� Swap �ϴ� ����� ���� ��

���� ������� ������ Swap�ص� �Ǵ���?
ex)
class Obj
	void memberSwap(Obj &other)
		swap(&(this->member), &(other.member));

�̷���?

**********
<�����Ʈ>	:

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Point {
private:
	int x, y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	Point(Point &copy) : x(copy.x), y(copy.y) { cout << "copy const" << endl; }
	Point& operator=(Point& copy) {
		cout << "operator= " << endl;
		x = copy.x;
		y = copy.y;
		return *this;
	}
	void print() const {
		cout << '(' << x << ", " << y << ')' << endl;
	}
};

class Main {
public:
	/**
	* �����ڸ� �̿��� swap (a�� b�� ����, b�� a�� �����ϴ� ���)
	* �� ��쿡�� ���� ������, ���� ������ ȣ��Ǽ� ��ȿ����!
	*
	* @param a, b: �ٲ� ��ü�� ��������
	*/
	template <class T>
	static void swap(T &a, T &b) {
		T temp = a; // ���� ������
		a = b;		// ���� ������
		b = temp;	// ���� ������
	}

	/**
	* �����͸� �̿��� swap (���� ����Ű�� ���� �ٲ�)
	* �� ��쿡�� ���� ������, ���� ������ ȣ�� �� ��!
	*
	* @param a, b: �ٲ� ��ü�� ��������
	*/
	template <class T>
	static void swap(T *a, T *b) {
		T *temp = a;
		a = b;
		b = temp;

		// ����
		//	T temp = *a;
		//	*a = *b;
		//	*b = temp;
	}

	static int main() {
		Point p1(10, 20);
		Point p2(-100, -200);
		swap(p1, p2);

		p1.print();
		p2.print();

		swap(&p1, &p2);

		p1.print();
		p2.print();

		return 0;
	}
};

