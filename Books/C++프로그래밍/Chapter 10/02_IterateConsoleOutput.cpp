///************
//<�ּ�>		: p429
//**********
//<�ذ���>	:
//
//���� ����ó�� operator<< �Լ��� ��ȯ���� void�� �Ѵٸ�
//
//'ostream ��ü << �ٸ� �ڷ��� << �ٸ� �ڷ���'
//'(ostream ��ü << �ٸ� �ڷ���) << �ٸ� �ڷ���'
//'void << �ٸ� �ڷ���'
//
//�� ���� �Ǿ� void���� ������ �Ǿ���� �������� << ������ �� �� �����µ�,
//
//��ȯ���� &ostream���� �ٲ����μ� �� ������ �ذ�ƴ�. (�ᱹ ��ȯ�Ǵ� ���� cout = ȣ����� ostream ��ü)
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
//		// ostream&�� ��ȯ�ϰ� �����μ�, <<������ �ϰ� �� �ڿ� �̾ <<������ �� �� �ְ� �������
//		// ������ ��ȯ�� void���� 'ostream ��ü << �ٸ� �ڷ��� << �ٸ� �ڷ���' ������ �ϸ�
//		// '(ostream ��ü << �ٸ� �ڷ���) << �ٸ� �ڷ���' �� �Ǿ�
//		// 'void << �ٸ� �ڷ���' �� ���� �Ǿ� ������ ������ ���µ�,
//		// ��ȯ���� ostream&�� �ٲٸ� �� ������ �ذ��
//		ostream& operator<< (char *str) {
//			printf("%s", str);
//			return *this;
//		}
//		ostream& operator<< (char str) {
//			printf("%c", str);
//			return *this;
//		}
//		ostream& operator<< (int num) {
//			printf("%d", num);
//			return *this;
//		}
//		ostream& operator<< (double e) {
//			printf("%g", e);
//			return *this;
//		}
//		ostream& operator<< (ostream& (*fp)(ostream &ostm)) {
//			return fp(*this);
//		}
//	};
//
//	ostream& endl(ostream &ostm) {
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//
//	ostream cout;
//}
//
//int main() {
//	using mystd::cout;
//	using mystd::endl;
//
//	char *str = "�̷� �͵� ";
//	char c = '!';
//	int n = 20;
//
//	cout << "������ " << str << "�����ϴ�" << c << n << endl;
//}
