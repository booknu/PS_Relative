/*
	HLD with costed edge.
	Unlike the normal HLD, top edge of each chains are also belongs to chain.

	usually (dfs_init, lca, decomposite, eidx, query) don't need to be changed.
	just modify (segtree, init_segs), and if segtree function changed modify (update, query_to)
*/
const int LOGN = 18;
struct hld_edge {
	struct segtree { // just edit segtree ( currently half-open interval [s, e) )
		int n;
		vi t;
		void init(int _n) { n = _n; t.assign(2*n, 0); }
		void update(int u, int x) {
			for(t[u += n] = x; u > 1; u /= 2) t[u/2] = max(t[u], t[u^1]);
		}
		int query(int s, int e) {
			int ret = 0;
			for(s += n, e += n; s < e; s /= 2, e /= 2) {
				if(s&1) ret = max(ret, t[s++]);
				if(e&1) ret = max(ret, t[--e]);
			}
			return ret;
		}
	};
	int n, rt;
	vi ssz, dep, hidx;
	vvi g, par, hvy;
	vector<segtree> segs;
	hld_edge(vvi& g, int rt) : g(g), rt(rt), n(g.size()), ssz(n, 0), dep(n, 0), hidx(n, -1), par(n, vi(LOGN, 0)) { 
		par[rt][0] = rt;
		dfs_init(rt);
		decomposite(rt);
		init_segs();
	}
	void dfs_init(int u) { // initialize dfs info
		ssz[u] = 1;
		FOR(j, 1, LOGN) par[u][j] = par[par[u][j-1]][j-1];
		for(int v : g[u]) {
			if(par[u][0] == v) continue;
			par[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs_init(v);
			ssz[u] += ssz[v];
		}
	}
	int lca(int u, int v) { // consider par[root] = root
		if(dep[u] < dep[v]) swap(u, v);
		int dif = dep[u] - dep[v];
		FOR(j, 0, LOGN) if(dif & (1<<j)) u = par[u][j];
		if(u != v) {
			RFOR(j, LOGN-1, 0) if(par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];
			u = par[u][0];
		}
		return u;
	}
	void decomposite(int rt) { // decomposite tree
		hidx[rt] = -1;
		queue<int> q;
		q.push(rt);
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int v : g[u]) if(par[v][0] == u) q.push(v);
			if(u != rt) {
				int p = par[u][0];
				if(p != rt && ssz[u]*2 >= ssz[p]) { // extend h-path (only if h-path)
					hidx[u] = hidx[p];
					hvy[hidx[u]].pb(u);
				} else { // create h-path (l-path or root-h-path)
					hidx[u] = hvy.size();
					hvy.pb(vi());
					hvy[hidx[u]].pb(p);
					hvy[hidx[u]].pb(u);
				}
			}
		}
	}
	void init_segs() { // initialize segtrees
		segs.assign(hvy.size(), segtree());
		FOR(i, 0, hvy.size()) segs[i].init(hvy[i].size()-1); // m vertices: m-1 edges
	}
	int eidx(int v) { // get u->v edge index in h-path
		return dep[par[v][0]] - dep[hvy[hidx[v]][0]];
	}
	void update(int u, int v, int x) { // u->v edge update
		if(par[u][0] == v) swap(u, v);
		assert(par[v][0] == u);
		segs[hidx[v]].update(eidx(v), x);
	}
	int query_to(int u, int v) { // return u->v path's query
		if(u == v) return 0;
		// modify range if segtree use closed interval [s, e]
		if(hidx[u] == hidx[v]) return segs[hidx[u]].query(eidx(u)+1, eidx(v)+1); // e(u)+1 because target is edge
		return max(query_to(u, hvy[hidx[v]][0]), segs[hidx[v]].query(0, eidx(v)+1)); // query tail path + recur
	}
	int query(int u, int v) {
		int t = lca(u, v);
		return max(query_to(t, u), query_to(t, v));
	}
};