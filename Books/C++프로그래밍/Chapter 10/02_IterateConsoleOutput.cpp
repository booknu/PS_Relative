///************
//<주소>		: p429
//**********
//<해결방안>	:
//
//기존 형식처럼 operator<< 함수의 반환형을 void로 한다면
//
//'ostream 객체 << 다른 자료형 << 다른 자료형'
//'(ostream 객체 << 다른 자료형) << 다른 자료형'
//'void << 다른 자료형'
//
//과 같이 되어 void와의 연산이 되어버려 연속으로 << 연산을 할 수 없었는데,
//
//반환형을 &ostream으로 바꿈으로서 이 문제가 해결됐다. (결국 반환되는 것은 cout = 호출당한 ostream 객체)
//
//**********
//<오답노트>	:
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
//		// ostream&을 반환하게 함으로서, <<연산을 하고 난 뒤에 이어서 <<연산을 할 수 있게 만들어줌
//		// 원래는 반환이 void여서 'ostream 객체 << 다른 자료형 << 다른 자료형' 연산을 하면
//		// '(ostream 객체 << 다른 자료형) << 다른 자료형' 이 되어
//		// 'void << 다른 자료형' 과 같이 되어 컴파일 오류가 났는데,
//		// 반환형을 ostream&로 바꾸면 이 문제가 해결됨
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
//	char *str = "이런 것도 ";
//	char c = '!';
//	int n = 20;
//
//	cout << "이제는 " << str << "가능하다" << c << n << endl;
//}
