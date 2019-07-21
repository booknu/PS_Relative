///************
//<주소>		: p429
//**********
//<해결방안>	:
//
//cout, endl의 작동 방식
//
//cout은 ostream 객체이고,
//endl은 ostream 객체를 인자로 받는 함수이다.
//
//ostream 객체는 << 연산자 오버로딩을 통해
//'ostream << 여러 자료형' 연산을 가능하게 만든다.
//
//그 중에서 
//'ostream << (ostream&을 반환하고, ostream &ostm을 인자로 받는 함수의 포인터)' 연산도 가능한데,
//위에서 인자로 받는 함수 포인터는 endl이 될 수 있고,
//즉 cout << endl; 연산이 가능하다는 소리이다.
//
//이것이 호출되면
//endl(cout); 이 호출되는데,
//그 함수에서는 한 줄을 띄우는 역할을 한다.
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
//		// 'ostream << 여러 자료형' 의 연산을 가능하게 하도록 연산자 오버로딩을 하고 있다.
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
//		// 'ostream << (ostream&을 반환하고, ostream &ostm을 인자로 받는 함수의 포인터)' 의 연산자 오버로딩을 하고 있다. 
//		// 즉, cout << endl 연산이 가능하다는 소리이다.
//		void operator<< (ostream& (*fp)(ostream &ostm)) {
//			// 인자로 받은 함수를 호출하며 현재 객체를 인자로 넘긴다.
//			// 즉, cout << endl을 호출했다면,
//			// cout.operator<<(endl); 이 호출되고,
//			// 그 내부에서는 함수 endl에 cout을 인자로 넘겨 호출하는 작업을 할 것이다.
//			// endl(cout);
//			fp(*this);
//		}
//	};
//
//	// ostream&를 반환하고, ostream &ostm을 인자로 받는 함수
//	// 즉, cout도 ostream 객체이므로, endl(cout);이 호출되면
//	// 이 함수가 실행될 것이다.
//	ostream& endl(ostream &ostm) {
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//
//	// ostream의 멤버 변수
//	// ostream 객체이기도 함.
//	// 따라서 cout과 다른 자료형은 << 연산자를 통해 연산할 수 있음 (endl 함수도 포함)
//	ostream cout;
//}
//
//int main() {
//	using mystd::cout;
//	using mystd::endl;
//	// cout.operator<<("Simple String");
//	cout << "Simple String";
//	// cout.operator<<(endl);  endl 함수포인터가 인자로 전달됨
//	cout << endl;
//	// ...
//	cout << 3.14;
//	cout << endl;
//	cout << 123;
//	endl(cout);
//
//	// 원래는 이렇게 사용할 필요도 없지만,
//	// ostream 클래스 안의 cout도 하나의 객체임을 보이기 위해서 삽입함.
//	// 결국 'ostream 객체 << 다른 자료형' 의 연산이 오버로딩 된 것임
//	mystd::ostream anotherCout;
//	anotherCout << "이것도 된다!";
//	anotherCout << endl;
//
//	// 결국 실제 std의 cout은 ostream 객체이며,
//	// << 연산 또한 오버로딩 된 것이고,
//	// endl은 함수 포인터이다.
//	std::cout.operator<<(std::endl);
//}
