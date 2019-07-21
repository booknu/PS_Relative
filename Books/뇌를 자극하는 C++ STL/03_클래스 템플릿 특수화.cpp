/************
<주소>		: p111
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ObjectInfo {
private:
	T data;

public:
	ObjectInfo(const T& d) : data(d) { }

	void Print() {
		// string의 정보에 대해서는 제대로 된 크기(길이)를 나타내지 못한다. (특수화 필요)
		cout << "타입: " << typeid(data).name() << endl;
		cout << "크기: " << sizeof(data) << endl;
		cout << "값: " << data << endl;
		cout << endl;
	}
};

// 클래스 템플릿 특수화
template <>
class ObjectInfo<string> {
private:
	string data;

public:
	ObjectInfo(const string &data) : data(data) { }

	void Print() {
		cout << "타입: " << "string" << endl;
		cout << "문자열 길이: " << data.length() << endl;
		cout << "값: " << data << endl;
		cout << endl;
	}
};

int main(void) {
	ObjectInfo<int> i1(10);
	i1.Print();

	ObjectInfo<double> i2(10.1);
	i2.Print();

	ObjectInfo<string> i3("THIS IS STRING");
	i3.Print();

	return 0;
}