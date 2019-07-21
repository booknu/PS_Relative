///************
//<�ּ�>		: p353
//**********
//<�ذ���>	:
//
//Employee Class �� ��ü ������ �������� ���� �ʰ�, �� Ʋ�� �����ϴ� �Ϳ��� ������ �ִ�.
//���� �̷� Ŭ������ Abstract Ŭ������ �����ϴ� ���� ����.
//
//Abstract Class �� �ϳ� �̻��� ���� virtual �Լ��� ������ �ִ� class�� ���Ѵ�.
//���� virtual �Լ���, �Լ��� ��ü�� ���ǵ��� ���� �Լ��̴�.
//ex) virtual int getPay() const = 0;
//
//���� Abstract Class�� Dynamic Type���� �����ϸ�, ������ ������ �߻��Ѵ�.
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
///**
//@class	Employee
//@date
//@author	LimSY
//@brief	Employee �����͸� �����ϱ� ���� Entity Ŭ����
//*/
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
//	void printName() const {
//		cout << "�̸�: " << name << endl;
//	}
//	// ���� virtual �Լ�
//	// �̰��� �ֱ� ������ Employee�� Abstract Class�̴�.
//	virtual void print() const = 0;
//	virtual int getPay() const = 0;
//	~Employee() {
//		delete[] name;
//	}
//};
//
///**
//@class	PermanentWorker
//@date
//@author	LimSY
//@brief	PermanentWorker �����͸� �����ϱ� ���� Entity Ŭ���� \n
//		Pay ����� salary
//*/
//class PermanentWorker : public Employee {
//private:
//	int salary;
//
//public:
//	PermanentWorker(char *name, int salary)
//		: Employee(name), salary(salary) { }
//	int getPay() const { return salary; }
//	void print() const {
//		printName();
//		cout << "salary: " << salary << endl << endl;
//	}
//};
//
///**
//@class	TemporaryWorker
//@date
//@author	LimSY
//@brief	TemporaryWorker �����͸� �����ϱ� ���� Entity Ŭ���� \n
//		Pay ����� workTime * payPerHour
//*/
//class TemporaryWorker : public Employee {
//private:
//	int workTime;
//	int payPerHour;
//
//public:
//	TemporaryWorker(char *name, int pph)
//		: Employee(name), workTime(0), payPerHour(pph) { }
//	void addWorkTime(int time) {
//		workTime += time;
//	}
//	int getPay() const {
//		return workTime * payPerHour;
//	}
//	void print() const {
//		printName();
//		cout << "salary: " << getPay() << endl << endl;
//	}
//};
//
///**
//@class	SalesWorker
//@date
//@author	LimSY
//@brief	SalesWorker �����͸� �����ϱ� ���� Entity Ŭ���� \n
//		Pay ����� salary + salesResult * bonusRatio
//*/
//class SalesWorker : public PermanentWorker {
//private:
//	int salesResult;
//	double bonusRatio;
//
//public:
//	SalesWorker(char *name, int salary, double bonusRatio)
//		: PermanentWorker(name, salary), salesResult(0), bonusRatio(bonusRatio) { }
//	void addSalesResult(int value) {
//		salesResult += value;
//	}
//	int getPay() const {
//		return PermanentWorker::getPay() + (int)(salesResult * bonusRatio);
//	}
//	void print() const {
//		printName();
//		cout << "salary: " << getPay() << endl << endl;
//	}
//};
//
///**
//@class	EmployeeHandler
//@date
//@author
//@brief	Employee �����͵��� �����ϱ� ���� Handler Ŭ���� \n
//*/
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
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->print();
//		}
//	}
//	void printTotalSalary() const {
//		int sum = 0;
//		for (int i = 0; i < empNum; i++) {
//			sum += empList[i]->getPay();
//		}
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
//	// Employee
//	// handler.addEmployee(new Employee("Lim")); Abstract Class�� Dynamic Type���� ��ü ���� �Ұ�!
//
//	// PermanetWorker
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//
//	// TemporaryWorker
//	TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
//	alba->addWorkTime(5); // 5�ð� ����
//	handler.addEmployee(alba);
//
//	// SalesWorker
//	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
//	seller->addSalesResult(7000);
//	handler.addEmployee(seller);
//
//	handler.printAll();
//
//	handler.printTotalSalary();
//	return 0;
//}