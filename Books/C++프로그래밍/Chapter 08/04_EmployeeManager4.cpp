///************
//<주소>		: p349
//**********
//<해결방안>	:
//
//virtual 키워드를 통해 print, getPay를 가상함수로 만들어,
//그것을 overriding 하는 함수들도 virtual 함수로 만듬.
//
//따라서 Dynamic Type에 따라 print, getPay를 호출할 수 있게 됨
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
//	virtual void print() const {
//		cout << "name: " << name << endl;
//	}
//	virtual int getPay() const { return 0; }
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
//		Employee::print();
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
//		Employee::print();
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
//		Employee::print();
//		cout << "salary: " << getPay() << endl << endl;
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
//		// 이제는 각 Dynamic Type마다 재정의된 print()가 호출됨!
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->print();
//		}
//	}
//	void printTotalSalary() const {
//		int sum = 0;
//		// 이제는 가능! getPay()는 가상함수이므로 Dynamic Type에 따라 함수가 호출됨!
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