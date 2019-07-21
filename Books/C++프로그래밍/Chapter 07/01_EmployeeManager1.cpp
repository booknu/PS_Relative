///************
//<�ּ�>		: p273
//**********
//<�ذ���>	:
//
//������ class �ϳ��� ���� ���
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//// �������� ������ ���� Ŭ����
//class PermanentWorker {
//private:
//	char name[100];
//	int salary;
//
//public:
//	PermanentWorker(char *name, int money)
//		: salary(money) {
//		strcpy_s(this->name, 20, name);
//	}
//	int getPay() const {
//		return salary;
//	}
//	void print() const {
//		cout << "name: " << name << endl;
//		cout << "salary: " << getPay() << endl;
//	}
//};
//
//// �ڵ鷯 Ŭ���� (����� ó���� ������ ����ϴ� Ŭ����)
//class EmployHandler {
//private:
//	PermanentWorker *empList[50];
//	int empNum;
//
//public:
//	EmployHandler() : empNum(0) { }
//	void addEmployee(PermanentWorker *emp) {
//		empList[empNum++] = emp;
//	}
//	void printAll() const {
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->print();
//		}
//	}
//	void printTotal() const {
//		int sum = 0;
//		for (int i = 0; i < empNum; i++) {
//			sum += empList[i]->getPay();
//		}
//		cout << "salary sum: " << sum << endl;
//	}
//	~EmployHandler() {
//		for (int i = 0; i < empNum; i++) {
//			delete empList[i];
//		}
//	}
//};
//
//int main() {
//	EmployHandler handler = EmployHandler();
//
//	// new�� ���� heap�� ���� �Ҵ��ϸ� �װ��� ����Ű�� �����Ͱ� ��ȯ��
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//	handler.addEmployee(new PermanentWorker("Jun", 2000));
//
//	// ���� ���ڰ� PermanentWorker &emp �̸�
//	// handler.addEmployee(*new PermanentWorker("Kim", 1000)); �� ���� ����
//	// new ~~~�� ������ �������� ���� ������ ���ڷ� ������ ����
//
//	handler.printAll();
//
//	handler.printTotal();
//
//	return 0;
//}