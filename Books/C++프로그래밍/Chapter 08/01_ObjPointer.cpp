///************
//<�ּ�>		: p327
//**********
//<�ذ���>	:
//
//base�� ����ϴ� derived Ŭ������
//StaticType var = DynamicType(������); �� ���� ������ �� �ִ�.
//��, ����� �� �ִ� ��� �Լ��� StaticType�� ���� �����ȴ�. (������ Ÿ�ӿ� �����Ǿ� �ϹǷ�)
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
//public:
//	void sleep() {
//		cout << "Sleep" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	void study() {
//		cout << "Study" << endl;
//	}
//};
//
//class PartTimeStudent : public Student {
//public:
//	void work() {
//		cout << "Work" << endl;
//	}
//};
//
//int main(void) {
//	// StaticType var = DynamicType(������); �� �����ϴ�!
//	Person *a = new Student(); // ���� �Ҵ�
//	Person b = PartTimeStudent(); // �Ϲ� �Ҵ�
//	Student *c = new PartTimeStudent();
//
//	// ȣ���� �� �ִ� �Լ��� Static Type�� ���� ������! (������ Ÿ�ӿ� �����Ǿ� �ϹǷ�)
//	a->sleep();
//	b.sleep();
//	c->study();
//
//	delete a;
//	delete c;
//}