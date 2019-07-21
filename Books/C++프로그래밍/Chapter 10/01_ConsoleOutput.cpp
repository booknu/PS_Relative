///************
//<�ּ�>		: p429
//**********
//<�ذ���>	:
//
//cout, endl�� �۵� ���
//
//cout�� ostream ��ü�̰�,
//endl�� ostream ��ü�� ���ڷ� �޴� �Լ��̴�.
//
//ostream ��ü�� << ������ �����ε��� ����
//'ostream << ���� �ڷ���' ������ �����ϰ� �����.
//
//�� �߿��� 
//'ostream << (ostream&�� ��ȯ�ϰ�, ostream &ostm�� ���ڷ� �޴� �Լ��� ������)' ���굵 �����ѵ�,
//������ ���ڷ� �޴� �Լ� �����ʹ� endl�� �� �� �ְ�,
//�� cout << endl; ������ �����ϴٴ� �Ҹ��̴�.
//
//�̰��� ȣ��Ǹ�
//endl(cout); �� ȣ��Ǵµ�,
//�� �Լ������� �� ���� ���� ������ �Ѵ�.
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//namespace mystd {
//	using namespace std;
//	
//	class ostream {
//	public:
//		// 'ostream << ���� �ڷ���' �� ������ �����ϰ� �ϵ��� ������ �����ε��� �ϰ� �ִ�.
//		void operator<< (char *str) {
//			printf("%s", str);
//		}
//		void operator<< (char str) {
//			printf("%c", str);
//		}
//		void operator<< (int num) {
//			printf("%d", num);
//		}
//		void operator<< (double e) {
//			printf("%g", e);
//		}
//		// 'ostream << (ostream&�� ��ȯ�ϰ�, ostream &ostm�� ���ڷ� �޴� �Լ��� ������)' �� ������ �����ε��� �ϰ� �ִ�. 
//		// ��, cout << endl ������ �����ϴٴ� �Ҹ��̴�.
//		void operator<< (ostream& (*fp)(ostream &ostm)) {
//			// ���ڷ� ���� �Լ��� ȣ���ϸ� ���� ��ü�� ���ڷ� �ѱ��.
//			// ��, cout << endl�� ȣ���ߴٸ�,
//			// cout.operator<<(endl); �� ȣ��ǰ�,
//			// �� ���ο����� �Լ� endl�� cout�� ���ڷ� �Ѱ� ȣ���ϴ� �۾��� �� ���̴�.
//			// endl(cout);
//			fp(*this);
//		}
//	};
//
//	// ostream&�� ��ȯ�ϰ�, ostream &ostm�� ���ڷ� �޴� �Լ�
//	// ��, cout�� ostream ��ü�̹Ƿ�, endl(cout);�� ȣ��Ǹ�
//	// �� �Լ��� ����� ���̴�.
//	ostream& endl(ostream &ostm) {
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//
//	// ostream�� ��� ����
//	// ostream ��ü�̱⵵ ��.
//	// ���� cout�� �ٸ� �ڷ����� << �����ڸ� ���� ������ �� ���� (endl �Լ��� ����)
//	ostream cout;
//}
//
//int main() {
//	using mystd::cout;
//	using mystd::endl;
//	// cout.operator<<("Simple String");
//	cout << "Simple String";
//	// cout.operator<<(endl);  endl �Լ������Ͱ� ���ڷ� ���޵�
//	cout << endl;
//	// ...
//	cout << 3.14;
//	cout << endl;
//	cout << 123;
//	endl(cout);
//
//	// ������ �̷��� ����� �ʿ䵵 ������,
//	// ostream Ŭ���� ���� cout�� �ϳ��� ��ü���� ���̱� ���ؼ� ������.
//	// �ᱹ 'ostream ��ü << �ٸ� �ڷ���' �� ������ �����ε� �� ����
//	mystd::ostream anotherCout;
//	anotherCout << "�̰͵� �ȴ�!";
//	anotherCout << endl;
//
//	// �ᱹ ���� std�� cout�� ostream ��ü�̸�,
//	// << ���� ���� �����ε� �� ���̰�,
//	// endl�� �Լ� �������̴�.
//	std::cout.operator<<(std::endl);
//}
