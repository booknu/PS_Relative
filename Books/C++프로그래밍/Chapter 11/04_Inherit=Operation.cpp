///************
//<주소>		: p449
//**********
//<해결방안>	:
//
//[ Derived에서 대입연산자 정의 X ]
//Base에서 operator= 이 오버로딩 되었고
//Derived에서 operator= 이 오버로딩 되지 않았으면
//
//Derived의 default operator= 이 실행되고, 거기서
//Base의 operator= 이 실행된다.
//
//[ Derived에서 대입연산자 정의 O ]
//Base에서 operator= 이 오버로딩 되었고,
//Derived에서 operator= 이 오버로딩 되었으면,
//
//Derived의 operator= 이 실행된다.
//==> but, 자동으로 Base의 operator= 이 실행되지는 않는다. (!!! 중요 !!!)
//
//
//[ 결 론 ]
//Derived의 operator= 정의에서, 명시적으로 Base의 operator=이 호출되지 않으면,
//자동으로 호출되지 않으니, 명시적으로 Base의 operator=을 호출하자
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class First {
//private:
//	int n1, n2;
//
//public:
//	First(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
//	
//	friend ostream& operator<<(ostream &os, First &f);
//
//	/*
//		operator<< 오버로딩용
//		dynamic type에 따라 출력하기 위함
//	*/
//	virtual void out(ostream &os) {
//		os << n1 << ", " << n2;
//	}
//
//	// operator= 오버로딩
//	First& operator=(const First& ref) {
//		cout << "First& operator=()" << endl;
//		n1 = ref.n1;
//		n2 = ref.n2;
//		return *this;
//	}
//};
//
//ostream& operator<<(ostream &os, First &f) {
//	f.out(os);
//	return os;
//}
//
//class Second : public First {
//private:
//	int n3, n4;
//
//public:
//	Second(int n1, int n2, int n3, int n4) : First(n1, n2), n3(n3), n4(n4) { }
//
//	/*
//		operator<< 오버로딩용
//		dynamic type에 따라 출력하기 위함
//	*/
//	virtual void out(ostream &os) {
//		First::out(os);
//		os << ", " << n3 << ", " << n4;
//	}
//
//	// operator= 오버로딩
//	Second& operator=(const Second &ref) {
//		First::operator=(ref); // 이걸 꼭 삽입해야 Base의 operator= 도 실행됨!!
//		cout << "Second& operator=()" << endl;
//		n3 = ref.n3;
//		n4 = ref.n4;
//		return *this;
//	}
//};
//
//int main(void) {
//	Second ssrc(1, 2, 3, 4);
//	Second scpy(0, 0, 0, 0);
//	scpy = ssrc;
//	cout << scpy << endl;
//
//	// Second에서 opera
//
//	return 0;
//}