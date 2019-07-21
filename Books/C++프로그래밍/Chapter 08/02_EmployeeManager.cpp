///************
//<�ּ�>		: p331
//**********
//<�ذ���>	:
//
//Static Type�� ���� ȣ��Ǵ� �Լ�, ȣ���� �� �ִ� �Լ��� �޶���!
//Overriding �� �Լ��� �ÿ��� Static Type�� ���� �� ȣ�� �Լ��� ������.
//���� base Ŭ�������� �Լ��� ȣ���ϰ� �ʹٸ� BaseClass::func(); ���� ������ ȣ�� ����
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
//class Employee {
//private:
//	char *name;
//
//public:
//	Employee(char *name) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//	}
//	void print() const {
//		cout << "name: " << name << endl;
//	}
//	~Employee() {
//		delete[] name;
//	}
//};
//
//class PermanentWorker : public Employee {
//private:
//	int salary;
//
//public:
//	PermanentWorker(char *name, int salary)
//		: Employee(name), salary(salary) { }
//	int getPay() const { return salary; }
//	void print() const {
//		Employee::print();
//		cout << "salary: " << salary << endl;
//	}
//};
//
//class EmployeeHandler {
//private:
//	Employee *empList[50];
//	int empNum;
//
//public:
//	EmployeeHandler() : empNum(0) { }
//	void addEmployee(Employee *newEmp) {
//		empList[empNum++] = newEmp;
//	}
//	void printAll() const {
//		// PermanentWorker���� print�� Overriding�� �Ǿ�������, Static Type�� Employee�̱� ������ Employee�� print�� ȣ���!
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->print();
//		}
//	}
//	void printTotalSalary() const {
//		int sum = 0;
//		// ����μ��� �Ұ��� (Employee�� PermanentEmployee���� Ȯ������ �ʱ� ����, Static Type)
//		/*for (int i = 0; i < empNum; i++) {
//			sum += empList[i]->getPay();
//		}*/
//		cout << "salary sum: " << sum << endl;
//	}
//	virtual ~EmployeeHandler() {
//		for (int i = 0; i < empNum; i++) {
//			delete empList[i];
//		}
//	}
//};
//
//int main() {
//	EmployeeHandler handler;
//
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//	handler.addEmployee(new PermanentWorker("Lim", 2000));
//
//	handler.printAll();
//	handler.printTotalSalary();
//}