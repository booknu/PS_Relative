///************
//<�ּ�>		: p550 - ����
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include "04_ArrTemplate.h"
//#include "04_Point.h"
//
//int main() {
//	const int ARR_LEN = 10;
//
//	// Point �� ��ü ����
//	Array<Point> pArr(ARR_LEN);
//	for (int i = 0; i < pArr.length; i++) {
//		pArr[i] = Point(i+1, (i+1) * 10);
//	}
//
//	for (int i = 0; i < pArr.length; i++) {
//		cout << pArr[i] << ' ';
//	}
//	cout << endl;
//
//	// int �ڷ��� ����
//	Array<int> iArr(ARR_LEN);
//	for (int i = 0; i < iArr.length; i++) {
//		iArr[i] = i+1;
//	}
//
//	for (int i = 0; i < iArr.length; i++) {
//		cout << iArr[i] << ' ';
//	}
//	cout << endl;
//
//	// double �ڷ��� ����
//	Array<double> dArr(ARR_LEN);
//	for (int i = 0; i < dArr.length; i++) {
//		dArr[i] = (i + 1) * 0.1;
//	}
//
//	for (int i = 0; i < dArr.length; i++) {
//		cout << dArr[i] << ' ';
//	}
//	cout << endl;
//	
//	// Point ��ü�� ������ ����
//	typedef Point* P_PTR;
//	Array<P_PTR> ppArr(ARR_LEN);
//	for (int i = 0; i < ppArr.length; i++) {
//		ppArr[i] = new Point(i, -i);
//	}
//
//	for (int i = 0; i < ppArr.length; i++) {
//		cout << *(ppArr[i]) << ' ';
//		delete ppArr[i]; // ���� �Ҵ�� ��ü�� ����!
//	}
//	cout << endl;
//}
