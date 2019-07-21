/************
<�ּ�>		: p128 - 3���� File �� Car ���� ����
**********
<�ذ���>	:
3���� ���ҵ� ���� �� Car�� ��������

**********
<�����Ʈ>	:

*/

#ifndef __CAR_H	// __CAR_H�� ������� �ʾ����� #endif���� ������ (���� include ������ �ذ��ϱ� ����)
#define __CAR_H	// __CAR_H�� ����
namespace carNormal { // 03_Car ���� ������ ���� namespace�� ���
	namespace CAR_CONST {
		enum {
			ID_LEN = 20,
			MAX_SPD = 200,
			FUEL_STEP = 2,
			ACC_STEP = 10,
			BRK_STEP = 10
		};
	}

	class Car {
	private:
		char gamerID[CAR_CONST::ID_LEN];
		int fuel;
		int speed;
	public:
		void init(char *ID, int fuel); // Constructor ���� �Լ� �߰�
		void showCarStatus();
		void accel();
		void stop();
	};
}
#endif	// __CAR_H�� ������� �ʾ����� ������� ������