///************
//<주소>		: p336
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
///**
//	@class	Employee
//	@date	
//	@author	LimSY
//	@brief	Employee 데이터를 저장하기 위한 Entity 클래스
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
//	void print() const {
//		cout << "name: " << name << endl;
//	}
//	~Employee() {
//		delete[] name;
//	}
//};
//
///**
//	@class	PermanentWorker
//	@date
//	@author	LimSY
//	@brief	PermanentWorker 데이터를 저장하기 위한 Entity 클래스 \n
//			Pay 방식이 salary
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
//		Employee::print();
//		cout << "salary: " << salary << endl << endl;
//	}
//};
//
///**
//	@class	TemporaryWorker
//	@date
//	@author	LimSY
//	@brief	TemporaryWorker 데이터를 저장하기 위한 Entity 클래스 \n
//			Pay 방식이 workTime * payPerHour
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
//		Employee::print();
//		cout << "salary: " << getPay() << endl << endl;
//	}
//};
//
///**
//	@class	SalesWorker
//	@date	
//	@author	LimSY
//	@brief	SalesWorker 데이터를 저장하기 위한 Entity 클래스 \n
//			Pay 방식이 salary + salesResult * bonusRatio
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
//	/*
//		PermanentWorker()의 print를 재정의
//		pay를 받는 getPay()가 다르므로 재정의를 해줬어야 함
//	*/
//	void print() const {
//		Employee::print();
//		cout << "salary: " << getPay() << endl << endl;
//	}
//};
//
///**
//	@class	EmployeeHandler
//	@date
//	@author
//	@brief	Employee 데이터들을 관리하기 위한 Handler 클래스 \n
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
//		// 현재로서는 불가능 (Employee가 PermanentEmployee인지 확실하지 않기 때문, Static Type)
//		/*for (int i = 0; i < empNum; i++) {
//		sum += empList[i]->getPay();
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
//	// PermanetWorker
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//
//	// TemporaryWorker
//	TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
//	alba->addWorkTime(5); // 5시간 일함
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