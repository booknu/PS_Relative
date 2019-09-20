int main(void) {
	// delim 단위로 분해하는 경우
	int p = 0;
	FOR(i, 0, n+1) {
		if(i == n || ar[i] == delem) {
			// 이전 구간 처리하고 [p, i)
			// .... DO SOMETHING .... //
			// 현재 구간 시작점을 다음 점으로
			p = i+1;
		}
	}

	// 값이 같은 단위로 분해하는 경우
	int p = 0;
	FOR(i, 1, n+1) {
		if(i == n || ar[i] != ar[i-1]) {
			// 이전 구간 처리하고 [p, i)
			// .... DO SOMETHING .... //
			// 현재 구간 시작점을 현재 점으로
			p = i;
		}
	}
}