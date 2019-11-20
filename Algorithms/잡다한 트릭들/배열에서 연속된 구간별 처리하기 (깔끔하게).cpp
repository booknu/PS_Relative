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

// online으로 깔끔하게 처리하는 법
int main(void) {
	int p = 0, pp = 0; // p: 현재 구간의 시작점, p2: 이전 구간의 시작점
	FOR(i, 0, n) {
		if(ar[p] != ar[i]) { // change seg start points
			pp = p;
			p = i;
		}
		// .... DO SOMETHING: [pp, p), [p, i) --> prev/cur segs .... //
	}
}