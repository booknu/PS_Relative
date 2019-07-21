///************
//<주소>		: p506
//**********
//<해결방안>	:
//
//string 헤더파일을 이용한 std string 사용
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string s1 = "I like ";
//	string s2 = "string class";
//	string cat = s1 + s2; // + 연산자가 오버로딩 되서 이렇게 사용 가능!
//
//	// << 연산자도 오버로딩 됨
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << cat << endl;
//
//	// == 연산자도 오버로딩 됨
//	if (s1 == s2) {
//		cout << "동일 문자열" << endl;
//	} else {
//		cout << "다른 문자열" << endl;
//	}
//
//	// >> 연산자도 오버로딩 됨
//	string in;
//	cout << "문자열 입력: ";
//	cin >> in;
//	cout << "입력한 문자열: " << in << endl;
//
//	return 0;
//}