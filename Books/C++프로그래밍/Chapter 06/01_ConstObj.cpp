///************
//<�ּ�>		: p244
//**********
//<�ذ���>	:
//const ��ü������ const �Լ��� ȣ�� ����!
//���� ���� ������ �������� �ʴ� �Լ��� ������ const�� �����ϴ°� ����!
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class& add(int operand) {
//		num += operand;
//		return *this;
//	}
//	void print() const{
//		cout << "num = " << num << endl;
//	}
//};
//
//int main(void) {
//	const Class obj(100); // const ��ü
//	// obj.add(10); �� �Ұ�! (const �Լ��� ��� ����)
//	obj.print();
//
//	return 0;
//}