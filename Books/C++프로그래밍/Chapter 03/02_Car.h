/************
<주소>		: p128 - 3개의 File 중 Car 선언 파일
**********
<해결방안>	:
3개로 분할된 파일 중 Car의 선언파일

**********
<오답노트>	:

*/

#ifndef __CAR_H	// __CAR_H가 선언되지 않았으면 #endif까지 컴파일 (다중 include 문제를 해결하기 위함)
#define __CAR_H	// __CAR_H를 선언
namespace carNormal { // 03_Car 과의 구분을 위해 namespace를 사용
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
		void init(char *ID, int fuel); // Constructor 역할 함수 추가
		void showCarStatus();
		void accel();
		void stop();
	};
}
#endif	// __CAR_H가 선언되지 않았으면 여기까지 컴파일