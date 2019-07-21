///************
//<주소>		: p331
//**********
//<해결방안>	:
//
//Static Type에 따라 호출되는 함수, 호출할 수 있는 함수가 달라짐!
//Overriding 된 함수일 시에도 Static Type에 따라 그 호출 함수가 정해짐.
//만약 base 클래스들의 함수를 호출하고 싶다면 BaseClass::func(); 같은 식으로 호출 가능
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
//		// PermanentWorker에서 print가 Overriding이 되어있지만, Static Type이 Employee이기 때문에 Employee의 print가 호출됨!
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->print();
//		}
//	}
//	void printTotalSalary() const {
//		int sum = 0;
//		// 현재로서는 불가능 (Employee가 PermanentEmployee인지 확실하지 않기 때문, Static Type)
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