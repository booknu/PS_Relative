///************
//<�ּ�>		: p235
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Temp {
//private:
//	int num;
//
//public:
//	Temp(int n) : num(n) {
//		cout << "create obj: " << num << endl;
//	}
//
//	~Temp() {
//		cout << "destroy obj: " << num << endl;
//	}
//
//	void print() {
//		cout << "[print] num = " << num << endl;
//	}
//};
//
//int main(void) {
//	Temp(100); // �ӽ� ��ü�� ������ ������, �װ��� �����ϴ� ���� ����! (�������ڸ��� ����)
//	cout << "----- after make -----" << endl << endl;
//
//	Temp(200).print();
//	cout << "----- after make -----" << endl << endl;
//
//	const Temp &ref = Temp(300); // �ӽ� ��ü�� �����߰�, �װ��� �����ϴ� ref�� �ֱ� ������ ��Ƴ���! 
//	cout << "----- end of main -----" << endl << endl;
//
//	// Temp(100)�� �ӽ� ��ü�ε�, �̰��� �����ڰ� ��ȯ��.
//	// �ӽ� ��ü�� ������ �����ڰ� ������ ������
//
//	// �� ����� ���� Temp t = Temp(100);�� ���� ���� ����! (t�� Temp(100)�� �����ڰ� ��)
//	// Temp *t = &Temp(100); �� ���� Temp(100)�� ������ �� �ִ� �����ڰ� ���� ������ ���� �࿡ �ٷ� �Ҹ��
//	// Temp &t = Temp(100); �� ������ t�� �����Ǵ� �ӽð�ü�̱� ������ �Ҹ���� ����
//
//	return 0;
//}