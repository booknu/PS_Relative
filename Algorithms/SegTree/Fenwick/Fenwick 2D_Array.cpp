struct segtree {
	vi ys[RANGE], t[RANGE];
	// (x, y)에 update 접근이 있음을 segtree에게 알려준다.
	void initpos(int x, int y) {
		for(++x; x < RANGE; x += (x&-x)) {
			ys[x].pb(y);
		}
	}
	// pos 입력 후 실행 
	void init() {
		FOR(i, 0, RANGE) sort(ALL(ys[i])), UNIQUE(ys[i]), t[i].assign(ys[i].size()+1, 0);
	}
	// (x, y)에 value 추가
	void add(int x, int y, int c) {
		for(++x; x < RANGE; x += (x&-x)) {
			for(int j = getidx(ys[x], y)+1; j < sz(t[x]); j += (j&-j)) {
				t[x][j] += c;
			}
		}
	}
	// ([..x], [..y]) 구간 합
	int sum(int x, int y) {
		int ret = 0;
		for(++x; x > 0; x -= (x&-x)) {
			// query에서의 y의 경우 ys에 없을 수 있으므로 따로 처리
			int j = getidx(ys[x], y);
			if(j == ys[x].size() || ys[x][j] > y) --j;
			for(++j; j > 0; j -= (j&-j)) {
				ret += t[x][j];
			}
		}
		return ret;
	}
} seg;
