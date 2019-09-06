struct pst {
	i64 x[MAXN*LOGN];
	int l[MAXN*LOGN], r[MAXN*LOGN], tcnt;
	// 0�� Ʈ�� ����
	int base(int ns = 0, int ne = MAXN-1) {
		int u = tcnt++;
		l[u] = u, r[u] = u;
	}
	// bef
	int make(int idx, int c, int u, int ns = 0, int ne = MAXN-1) {
		if(idx < ns || ne < idx) return u;
		int v = tcnt++;
		if(ns == ne) x[v] = (x[u] + c) % MOD;
		else {
			int m = (ns+ne)/2;
			l[v] = make(idx, c, l[u], ns, m);
			r[v] = make(idx, c, r[u], m+1, ne);
			x[v] = (x[l[v]] + x[r[v]]) % MOD;
		}
		return v;
	}

	i64 query(int s, int e, int u, int ns = 0, int ne = MAXN-1) {
		if(s <= ns && ne <= e) return x[u];
		if(ne < s || e < ns) return 0;
		int m = (ns+ne)/2;
		return (query(s, e, l[u], ns, m) + query(s, e, r[u], m+1, ne)) % MOD; 
	}
};