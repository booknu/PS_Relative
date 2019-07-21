/************
<주소>		: p119
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

// 반복자와 함수 포인터를 템플릿으로 선언하여 범용성을 높임
template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) {
	while (begin != end) {
		pf(*begin++);
	}
}

// 함수 포인터 대신 Functor을 넘기면 더 좋음
// functor은 멤버를 가질 수 있고, 더 빠르고, inline화가 가능하기 때문
template <typename T>
class PrintFunctor {
private:
	string sep; // 출력 구분자
	
public:
	explicit PrintFunctor(const string& _sep = ", ") : sep(_sep) { }

	void operator()(T data) const {
		cout << data << sep;
	}
};

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5 };
	For_each(arr, arr + 5, PrintFunctor<int>());
	cout << endl;

	string sarr[] = { "a", "abc", "한글" };
	For_each(sarr, sarr + 3, PrintFunctor<string>("\n"));
	cout << endl;

	return 0;
}