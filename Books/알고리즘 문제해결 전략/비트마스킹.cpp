/**
* set mask bit to value (true = 1, false = 0)
*
* @param n n bit
* @param value true = 1, false = 0
* @param mask mask
* @return changed mask
*/
int setBit(int n, bool value, int mask) {
	if (value) {
		return mask | (1 << n);
	} else {
		return mask & (~(1 << n));
	}
}

/**
* get mask bit
*
* @param n n bit
* @param mask mask
* @return true / false
*/
int getBit(int n, int mask) {
	return mask & (1 << n);
}

/*
	n�� �������� ǥ������ �� 1�� ������ ��ȯ
	@param n mask
	@return number of 1 in n
*/
int bitcount(int n) {
	int i;
	for (i = 0; n != 0; i++) {
		n &= (n - 1);
	}
	return i;
}