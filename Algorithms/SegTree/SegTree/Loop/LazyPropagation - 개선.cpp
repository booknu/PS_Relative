struct lazy { // range (add / max query) with lazy propagation
	int n, h;
	i64 def_val = 0, def_lazy = 0; // TODO: MODIFTY DEFAULT VALUES !!
	vector<i64> t, d; // t는 항상 해당 d가 적용된 최신 값을 가지고 있어야 함!
	lazy(int _n) {
		n = _n;
		h = 8*sizeof(n) - __builtin_clz(n);
		t.assign(2*n, def_val), d.assign(n, def_lazy);
	}
	void calc(int u, int k) { // = recalc node with d[u]
							  // TODO: MODIFTY CALC FUNCTION !!
		t[u] = max(t[u<<1], t[u<<1|1]) + d[u];
	}
	void apply(int u, i64 x, int k) { // = add x to single node
									  // TODO: MODIFTY APPLY FUNCTION !!
		t[u] += x;
		if(u < n) d[u] += x;
	}
	void build(int s, int e) { // = recalc [s..e]'s parent nodes with current lazy
		s += n, e += n-1;
		for(int k = 2; s > 1; k <<= 1) {
			s >>= 1, e >>= 1;
			for(int i = e; i >= s; --i) calc(i, k);
		}
	}
	void push(int s, int e) { // = propagate all [s..e]'s parents
		s += n, e += n-1;
		for(int c = h, k = 1 << (h-1); c > 0; --c, k >>= 1) {
			for(int i = s >> c; i <= e >> c; ++i) {
				if(d[i] != def_lazy) {
					apply(i<<1, d[i], k);
					apply(i<<1|1, d[i], k);
					d[i] = def_lazy;
				}
			}
		}
	}
	void add(int s, int e, i64 x) { // [s, e)
		push(s, s+1);
		push(e-1, e);
		int s0 = s, e0 = e, k = 1;
		for(s += n, e += n; s < e; s >>= 1, e >>= 1, k <<= 1) {
			if(s&1) apply(s++, x, k);
			if(e&1) apply(--e, x, k);
		}
		build(s0, s0+1);
		build(e0-1, e0);
	}
	i64 query(int s, int e) {
		push(s, s+1);
		push(e-1, e);
		i64 ret = def_val;
		for(s += n, e += n; s < e; s >>= 1, e >>= 1) {
			// TODO: MODIFTY VALUE COMBINATION !!
			if(s&1) ret = max(ret, t[s++]);
			if(e&1) ret = max(ret, t[--e]);
		}
		return ret;
	}
};