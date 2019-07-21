/************
<�ּ�>		: p618 - OOP ������Ʈ 11�ܰ�
**********
<�ذ���>	:

Account ��ü���� �����ϱ� ���� Array Ŭ����

**********
<�����Ʈ>	:

1. [] �����ڸ� �����ε� �� �� ��ȯ���� ��� �� �� �����
   ó������ Account&�� ��ȯ�ϰ� ������µ�, �迭�� ���� �� new �� ���� �ִ´ٴ� ���� ���ݰ�
   Account*�� ��ȯ�ϰ� ���������,
   �� ���� ��ȯ�� �����ͷ� ���� �������� ���ϴ� ������ �־���.
   ==> ���� �����ϰ� �Ϸ��� ACC_PTR&�� ��ȯ�ϰ� ����

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


//////// ������
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