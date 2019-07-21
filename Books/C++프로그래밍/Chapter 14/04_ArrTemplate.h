/************
<주소>		: p561
**********
<해결방안>	:

배열 클래스의 템플릿화

**********
<오답노트>	:

*/

#ifndef __ARR_TEMPLATE_H__
#define __ARR_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 *	@class	Array
 *	@brief	템플릿을 활용한 배열
 */
template <class T>
class Array {

private:
	T *items;
	Array(Array &copy);
	Array& operator=(Array &copy);

public:
	const int length;

public:
	Array(int length);

	T& operator[](int index);
	T operator[](int index) const;

	~Array();
};

///// private
template <class T>
Array<T>::Array(Array &copy) : length(0) { }

template <class T>
Array<T>& Array<T>::operator=(Array<T> &copy) { return *this; }

///// public
template <class T>
Array<T>::Array(int length) : length(length) {
	items = new T[length];
}

template <class T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= length) {
		cout << "Exception: ArrayIndexOutOfBoundException (" << index << ')' << endl;
		exit(1);
	}
	return items[index];
}

template <class T>
T Array<T>::operator[](int index) const {
	if (index < 0 || index >= length) {
		cout << "Exception: ArrayIndexOutOfBoundException (" << index << ')' << endl;
		exit(1);
	}
	return items[index];
}


template <class T>
Array<T>::~Array() {
	delete items;
}

#endif