///************
//<�ּ�>		: p476
//**********
//<�ذ���>	:
//
//new[], delete[] �������� �����ε�
//new[]:		�迭 �Ҵ� �� ȣ��
//delete[]:	�迭 �Ҹ� �� ȣ��
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
//	/**
//	 * new �������� �����ε��� �޸� ������ �Ҵ縸�� �����ε� �� �� �ִ�.
//	 *
//	 * @param size: �Ҵ��� unsigned int�� size (byte ����)
//	 * @return: �Ҵ�� �޸𸮸� ����Ű�� void ������
//	 */
//	void* operator new(size_t size) {
//		cout << "operator new: " << size << endl;
//		void *adr = new char[size]; // size�� size byte ��ŭ �޸𸮸� �Ҵ��϶�� ���̴ϱ�, 1byte�� char�� �迭�� �̿��� �޸� �Ҵ�
//		return adr;
//	}
//
//	/**
//	 * delete �������� �����ε��� �޸� ������ �������� �����ε� �� �� �ִ�.
//	 * 
//	 * @param adr: ������ �޸� �ּҸ� ����Ű�� void�� ������
//	 */
//	void operator delete(void *adr) {
//		cout << "operator delete" << endl;
//		delete[] adr; // delete[] �� ����� �Ϳ� ����!
//	}
//
//	/**
//	 * new[] �������� �����ε� (�迭 �Ҵ� �� ȣ��)
//	 * 
//	 * @param size: �Ҵ��� unsigned int�� size (byte ����)
//	 * @return �Ҵ�� �޸𸮸� ����Ű�� void ������
//	 */
//	void* operator new[](size_t size) {
//		cout << "operator new[]: " << size << endl;
//		void *adr = new char[size];
//		return adr;
//	}
//
//	/**
//	 * delete[] �������� �����ε� (�迭 �Ҹ� �� ȣ��)
//	 * 
//	 * @param adr: �Ҹ��� �޸� �ּ�
//	 */
//	void operator delete[](void *adr) {
//		cout << "operator delete[]" << endl;
//		delete[] adr;
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
//	Point *arr = new Point[3];
//	delete ptr;
//	delete[] arr;
//
//	return 0;
//}