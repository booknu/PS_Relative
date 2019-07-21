class Object {
private:
	const int member;
	// private 멤버, 함수들
	
protected:
	// protected 멤버, 함수들

public:
	/*************
	 *	생성자
	 *************/
	Object(int param) : member(param) { }

	/*************
	 *	복사 생성자
	 *************/
	Object(Object &copy) : member(copy.member) {
		// 이니셜라이저에서 상위 상속 생성자 호출

		// 깊은 복사
	}

	/**************
	 *	대입 연산자
	 **************/
	Object& operator=(Object &copy) {
		// 상속 시 상위 대입연산자 호출

		// 현재 참조하고 있는 heap 메모리 delete

		// 깊은 복사

	}

	/**************
	 *	소멸자
	 **************/
	virtual ~Object() {
		// virtual로 선언하기

		// heap delete
	}
};