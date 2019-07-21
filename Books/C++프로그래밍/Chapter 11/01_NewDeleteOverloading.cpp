///************
//<�ּ�>		: p473
//**********
//<�ذ���>	:
//
//new, delete �������� �����ε�
//new:	�޸� ������ �Ҵ縸�� �����ε� ���� ( void* operator new(size_t size) {} )
//delete: �޸� ������ �������� �����ε� ���� ( void operator delete(void* adr) {} )
//==> size_t �� typedef unsigned int size_t
//
//�� ���� ��ü�� ��� �Լ�������, static �Լ��̱� ������ ��ü ���� �� ȣ���� �����ϴ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	friend ostream& operator<<(ostream &os, Point &p);
//
//	/*
//		new �������� �����ε��� �޸� ������ �Ҵ縸�� �����ε� �� �� �ִ�.
//		(�� �ڿ� �Ͼ�� ������ ȣ��, ��ȯ�� �ּ��� ����ȯ�� �����Ϸ� ���ؿ��� �Ѵ�.)
//		�� �Լ��� ����Լ�����, static �Լ��̴�.
//
//		@param size: �Ҵ��� unsigned int�� size (byte ����)
//		@return: �Ҵ�� �޸𸮸� ����Ű�� void ������
//	*/
//	void* operator new(size_t size) {
//		cout << "operator new: " << size << endl;
//		void *adr = new char[size]; // size�� size byte ��ŭ �޸𸮸� �Ҵ��϶�� ���̴ϱ�, 1byte�� char�� �迭�� �̿��� �޸� �Ҵ�
//		return adr;
//	}
//
//	/*
//		delete �������� �����ε��� �޸� ������ �������� �����ε� �� �� �ִ�.
//		(�� ���� �Ͼ�� �Ҹ��� ȣ���� �����Ϸ� ���ؿ��� �Ѵ�.)
//		�� �Լ��� ����Լ�����, static �Լ��̴�.
//
//		@param adr: ������ �޸� �ּҸ� ����Ű�� void�� ������
//	*/
//	void operator delete(void *adr) {
//		cout << "operator delete" << endl;
//		delete[] adr; // delete[] �� ����� �Ϳ� ����!
//	}
//};
//
//ostream& operator<<(ostream &os, Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
//int main() {
//	// heap�� �Ҵ��� ���� new delete ������ ����
//	Point *ptr = new Point(3, 4);
//	cout << *ptr << endl;
//	delete ptr;
//
//	// stack�� �Ҵ��� ���� ��� �� ��
//	Point p(3, 4);
//	return 0;
//}