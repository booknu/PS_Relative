///************
//<�ּ�>		: p449
//**********
//<�ذ���>	:
//
//02�� ������ = ������ �����ε����� �ذ�
//operator= �� ��ȯ���� Obj& �ӿ� ����!!!
//
//[ �� �� ]
//1. ���� �޸� ���� (!!! �߿� !!!)
//2. ���� ���� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Person {
//private:
//	char *name;
//	int age;
//
//public:
//	Person(char *name, int age) : age(age) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy_s(this->name, len, name);
//	}
//
//	Person& operator=(Person &copy) {
//		// �켱 ���� name �޸𸮸� �����ؾ��� (!!! �߿� !!!)
//		delete name; // Person::~Person(); ����ص� ��
//
//		// ���� ����
//		int len = strlen(copy.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, copy.name);
//		age = copy.age;
//		
//		// = ������ ���� ������ ���� ���� ��ü ���� ��ȯ (�� ���� ���� ������ ����)
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream &os, Person &p);
//
//	~Person() {
//		cout << "called destructor" << endl;
//		delete name;
//	}
//};
//
//ostream& operator<<(ostream &os, Person &p) {
//	os << "[ " << p.name << ", " << p.age << " ]";
//	return os;
//}
//
//int main() {
//	Person p1("Lee Dong Woo", 29);
//	Person p2("Yoon Ji Yul", 22);
//	p1 = p2; // default ���� ������ ȣ�� (���� ����)
//	cout << "p1: " << p1 << endl;
//	cout << "p2: " << p2 << endl;
//
//	// p1, p2�� destructor�� ȣ��Ǹ鼭 ������ *name�� ������� ���ٵ�,
//	// p1�� *name�� p2�� *name�� ���� ���縦 �߱� ������ ���� heap �ּҸ� ����Ŵ.
//	// ���� ���� �ּҸ� 2�� �ݺ��ؼ� ����� ������ error �߻�
//	return 0;
//}