/************
<�ּ�>		: p111
**********
<�ذ���>	:

**********
<�����Ʈ>	:

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
		// string�� ������ ���ؼ��� ����� �� ũ��(����)�� ��Ÿ���� ���Ѵ�. (Ư��ȭ �ʿ�)
		cout << "Ÿ��: " << typeid(data).name() << endl;
		cout << "ũ��: " << sizeof(data) << endl;
		cout << "��: " << data << endl;
		cout << endl;
	}
};

// Ŭ���� ���ø� Ư��ȭ
template <>
class ObjectInfo<string> {
private:
	string data;

public:
	ObjectInfo(const string &data) : data(data) { }

	void Print() {
		cout << "Ÿ��: " << "string" << endl;
		cout << "���ڿ� ����: " << data.length() << endl;
		cout << "��: " << data << endl;
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