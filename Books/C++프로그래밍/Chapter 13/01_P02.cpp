///************
//<주소>		: p536
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template <class T>
//T sum(T arr[], int len) {
//	T sum = 0;
//	for (int i = 0; i < len; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//int main() {
//	const int ARR_LEN = 10;
//	int arrInt[ARR_LEN];
//	for (int i = 0; i < ARR_LEN; i++) {
//		arrInt[i] = i + 1;
//	}
//
//	double arrDouble[ARR_LEN];
//	for (int i = 0; i < ARR_LEN; i++) {
//		arrDouble[i] = 0.1 * (i + 1);
//	}
//
//	int s1 = sum(arrInt, ARR_LEN);
//	double s2 = sum(arrDouble, ARR_LEN);
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//}