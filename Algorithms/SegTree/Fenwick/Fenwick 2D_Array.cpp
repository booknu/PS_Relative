struct segtree {
	vi ys[RANGE], t[RANGE];
	// (x, y)�� update ������ ������ segtree���� �˷��ش�.
	void initpos(int x, int y) {
		for(++x; x < RANGE; x += (x&-x)) {
			ys[x].pb(y);
		}
	}
	// pos �Է� �� ���� 
	void init() {
		FOR(i, 0, RANGE) sort(ALL(ys[i])), UNIQUE(ys[i]), t[i].assign(ys[i].size()+1, 0);
	}
	// (x, y)�� value �߰�
	void add(int x, int y, int c) {
		for(++x; x < RANGE; x += (x&-x)) {
			for(int j = getidx(ys[x], y)+1; j < sz(t[x]); j += (j&-j)) {
				t[x][j] += c;
			}
		}
	}
	// ([..x], [..y]) ���� ��
	int sum(int x, int y) {
		int ret = 0;
		for(++x; x > 0; x -= (x&-x)) {
			// query������ y�� ��� ys�� ���� �� �����Ƿ� ���� ó��
			int j = getidx(ys[x], y);
			if(j == ys[x].size() || ys[x][j] > y) --j;
			for(++j; j > 0; j -= (j&-j)) {
				ret += t[x][j];
			}
		}
		return ret;
	}
} seg;
