class Object {
private:
	const int member;
	// private ���, �Լ���
	
protected:
	// protected ���, �Լ���

public:
	/*************
	 *	������
	 *************/
	Object(int param) : member(param) { }

	/*************
	 *	���� ������
	 *************/
	Object(Object &copy) : member(copy.member) {
		// �̴ϼȶ��������� ���� ��� ������ ȣ��

		// ���� ����
	}

	/**************
	 *	���� ������
	 **************/
	Object& operator=(Object &copy) {
		// ��� �� ���� ���Կ����� ȣ��

		// ���� �����ϰ� �ִ� heap �޸� delete

		// ���� ����

	}

	/**************
	 *	�Ҹ���
	 **************/
	virtual ~Object() {
		// virtual�� �����ϱ�

		// heap delete
	}
};