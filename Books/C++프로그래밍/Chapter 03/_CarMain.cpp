///************
//<�ּ�>		: p130 - 3�� ���� �� Main �κ�
//**********
//<�ذ���>	:
//���� 02_Car, 03_CarInline�� �����ϰ� ������ �̰��� ���
//VERSION�� ���� 02, 03�� �����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//// ���� ������ Car ��� ����!
//#define VERSION 1 // 1: CarNormal, 2: CarInline
//
//#if VERSION == 1
//#include "02_Car.h"
//#include <iostream>
//using namespace std;
//using namespace carNormal;
//
//#elif VERSION == 2
//#include "03_CarInline.h"
//using namespace carInline;
//// carInline.h���� std�� using namespace ������ �ʿ�X, iostream include�� ��������
//
//#endif
//
//
//int main(void) {
//	cout << "----- version " << VERSION << " -----" << endl;
//	Car A;
//	A.init("A", 100);
//	A.accel();
//	A.accel();
//	A.showCarStatus();
//	A.stop();
//	A.showCarStatus();
//
//	Car B;
//	B.init("B", 100);
//	B.accel();
//	B.stop();
//	B.showCarStatus();
//
//	return 0;
//}