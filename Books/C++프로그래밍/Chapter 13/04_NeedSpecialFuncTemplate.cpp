///************
//<주소>		: p536
//**********
//<해결방안>	:
//
//아래와 같이 단순하게 max를 찾는 함수 템플릿을 구현하면,
//문자열을 비교할 때 문자열들의 포인터가 넘어가게 되며,
//그들의 주소를 비교하기 때문에 원하지 않는 답이 나온다.
//
//따라서 이렇게 특수한 경우는
//template <>
//char* max(char *a, char *b);
//와 같이 특수화를 해줘야 한다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template <typename T>
//T max(T a, T b) {
//	return a > b ? a : b;
//}
//
//int main() {
//	cout << max(11, 15)			<< endl;
//	cout << max('A', 'Z')		<< endl;
//	cout << max(3.5, 7.5)		<< endl;
//	cout << max("AAA", "ZZZ")	<< endl; // 이와 같은 경우는 단순히 주소 값의 비교 결과가 반환!
//}