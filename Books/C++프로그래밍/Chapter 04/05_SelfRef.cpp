///************
//<�ּ�>		: p200
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
//class SelfRef {
//private:
//	int num;
//
//public:
//	SelfRef(int num) : num(num) {
//		cout << "��ü ���� (num = " << this->num << ')' << endl;
//	}
//
//	SelfRef& adder(int n) {
//		num += n;
//		return *this; // ��ü �ڽ��� ������ �� �ִ� ���� ���� ��ȯ
//	}
//
//	SelfRef& showTwoNum() {
//		cout << num << endl;
//		return *this;
//	}
//};
//
//int main(void) {
//	SelfRef obj(3);
//	SelfRef &ref = obj.adder(2);
//
//	obj.showTwoNum();
//	ref.showTwoNum();
//
//	ref.adder(1).showTwoNum().adder(2).showTwoNum(); // adder, showTwoNum�� ���� �ڱ� �ڽ��� ������ ��ȯ�ϹǷ� ���̾ .�� ���� ��ü ���� ����
//	return 0;
//}