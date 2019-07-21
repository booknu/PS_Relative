///************
//<주소>		: p354 - 문제
//**********
//<해결방안>	:
//
//<오답노트>	:
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
//@brief	Employee 데이터를 저장하기 위한 Entity 클래스
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
//		cout << "이름: " << name << endl;
//	}
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
//@brief	PermanentWorker 데이터를 저장하기 위한 Entity 클래스 \n
//Pay 방식이 salary
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
//@brief	TemporaryWorker 데이터를 저장하기 위한 Entity 클래스 \n
//Pay 방식이 workTime * payPerHour
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
//@brief	SalesWorker 데이터를 저장하기 위한 Entity 클래스 \n
//Pay 방식이 salary + salesResult * bonusRatio
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
//namespace RISK_LV {
//	enum { A = 30, B = 20, C = 10 };
//}
//
//class ForeignSalesWorker : public SalesWorker {
//private:
//	const int dangerRatio;
//
//public:
//	ForeignSalesWorker(char *name, int salary, double bonusRatio, int dangerRatio) 
//		: SalesWorker(name, salary, bonusRatio), dangerRatio(dangerRatio) { }
//	int getRiskPay() const {
//		return (int)(SalesWorker::getPay() * dangerRatio / 100.0);
//	}
//	int getPay() const {
//		return SalesWorker::getPay() + getRiskPay();
//	}
//	void print() const {
//		printName();
//		cout << "salary: " << SalesWorker::getPay() << endl;
//		cout << "risk pay: " << getRiskPay() << endl;
//		cout << "sum: " << getPay() << endl << endl;
//	}
//};
//
///**
//@class	EmployeeHandler
//@date
//@author
//@brief	Employee 데이터들을 관리하기 위한 Handler 클래스 \n
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
//	ForeignSalesWorker *f1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LV::A);
//	f1->addSalesResult(7000);
//	handler.addEmployee(f1);
//
//	ForeignSalesWorker *f2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LV::B);
//	f2->addSalesResult(7000);
//	handler.addEmployee(f2);
//
//	ForeignSalesWorker *f3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LV::C);
//	f3->addSalesResult(7000);
//	handler.addEmployee(f3);
//
//	handler.printAll();
//
//	handler.printTotalSalary();
//	return 0;
//}