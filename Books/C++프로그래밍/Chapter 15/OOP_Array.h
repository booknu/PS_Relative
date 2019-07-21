/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

Account 객체들을 저장하기 위한 Array 클래스

**********
<오답노트>	:

1. [] 연산자를 오버로딩 할 때 반환형을 어떻게 할 지 헤멨음
   처음에는 Account&를 반환하게 만들었는데, 배열에 넣을 때 new 를 통해 넣는다는 것을 깨닫고
   Account*을 반환하게 만들었지만,
   이 경우는 반환된 포인터로 값을 수정하지 못하는 문제가 있었음.
   ==> 값을 수정하게 하려고 ACC_PTR&를 반환하게 만듬

*/

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

template<class T>
class Array {
	typedef T* T_PTR;

private:
	T_PTR *arr;
	Array(const Array &copy);
	Array& operator=(const Array &copy);

public:
	const int length;

public:
	Array(int length);

	T_PTR& operator[](int index);
	T_PTR operator[](int index) const;

	~Array();
};


//////// 구현부
template<class T>
Array<T>::Array(const Array<T> &copy) : length(0) { }

template<class T>
Array<T>& Array<T>::operator=(const Array<T> &copy) { return *this; }

template<class T>
Array<T>::Array(int length) : length(length) {
	arr = new T*[length];
}

template <class T>
T*& Array<T>::operator[](int index) {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

template<class T>
T* Array<T>::operator[](int index) const {
	if (index < 0 || index > length) {
		cout << "Exception: ArrayIndexOutOfBoundExceptin (" << index << ')' << endl;
		exit(1);
	}
	return arr[index];
}

template<class T>
Array<T>::~Array() {
	delete[] arr;
}

#endif