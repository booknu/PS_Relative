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
	n을 이진수로 표현했을 때 1의 개수를 반환
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