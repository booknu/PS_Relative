// Caution: All vertices' idx > 0 (par[S] = 0)
const int MAXND = 500, S = 1, T = 2, INF = 0x3fffffff;
struct nflow {
	struct edge {
		edge* rev; 
		int v, c, f; // need initialized
		edge(int v, int c) : v(v), c(c), f(0) { }
		int res() { return c-f; }
		int flow(int x) { f += x, rev->f -= x; }
	};
	vector<edge*> g[MAXND];
	int par[MAXND];
	edge* pedg[MAXND];
	nflow() {
		FOR(i, 0, MAXN) g[i] = vector<edge*>();
	}
	void addedge(int u, int v, int c) { 
		edge *uv = new edge(v, c), *vu = new edge(u, 0);
		uv->rev = vu, vu->rev = uv;
		g[u].pb(uv), g[v].pb(vu);
	}
	i64 maxflow() {
		i64 ret = 0;
		while(true) {
			memset(par, 0, sizeof(par));
			queue<int> q;
			q.push(S);
			par[S] = S;
			while(q.size()) {
				int u = q.front(); q.pop();
				for(auto e : g[u]) {
					if(e->res() && !par[e->v]) {
						q.push(e->v);
						par[e->v] = u;
						pedg[e->v] = e;
						if(e->v == T) break;
					}
				}
				if(par[T]) break;
			}
			if(!par[T]) break;
			int flow = INF;
			for(int u = T; u != S; u = par[u]) flow = min(flow, pedg[u]->res());
			for(int u = T; u != S; u = par[u]) pedg[u]->flow(flow);
			ret += flow;
		}
		return ret;
	}
};