///************
//<주소>		: p273
//**********
//<해결방안>	:
//
//정규직 class 하나만 있을 경우
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
//// 데이터적 성격이 강한 클래스
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
//// 핸들러 클래스 (기능의 처리를 실제로 담당하는 클래스)
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
//	// new를 통해 heap에 동적 할당하면 그것을 가리키는 포인터가 반환됨
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//	handler.addEmployee(new PermanentWorker("Jun", 2000));
//
//	// 만약 인자가 PermanentWorker &emp 이면
//	// handler.addEmployee(*new PermanentWorker("Kim", 1000)); 로 인자 전달
//	// new ~~~로 생성된 포인터의 값의 참조를 인자로 보내는 것임
//
//	handler.printAll();
//
//	handler.printTotal();
//
//	return 0;
//}