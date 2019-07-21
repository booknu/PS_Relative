///************
//<주소>		: p264
//**********
//<해결방안>	:
//
//const 멤버 변수는 이니셜라이저(초기화 리스트)를 통해서만 초기화 가능
//
//const static 멤버 변수는 = 대입자를 통해 초기화 가능 
//(static 멤버 변수도 가능하지만, 객체가 생성될 때마다 static 멤버 변수도 초기화되는 문제 발생!)
//(따라서 값이 바뀌지 않는 const static의 경우에 이 방법 사용)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class CountryArea {
//public:
//	// 이런식으로 const static 멤버 변수 초기화 가능!
//	const static int RUSSIA = 1707540;
//	const static int CANADA = 998467;
//	const static int CHINA = 957290;
//	const static int SOUTH_KOREA = 9922;
//	const static int UNKNOWN_COUNTRY;
//};
//
//// 이런식으로도 const static 멤버 변수 초기화 가능!
//const int CountryArea::UNKNOWN_COUNTRY = -1;
//
//int main() {
//	cout << "러시아: " << CountryArea::RUSSIA << endl;
//	cout << "캐나다: " << CountryArea::CANADA << endl;
//	cout << "중국: " << CountryArea::CHINA << endl;
//	cout << "한국: " << CountryArea::SOUTH_KOREA << endl;
//	cout << "알려지지 않음: " << CountryArea::UNKNOWN_COUNTRY << endl;
//}
