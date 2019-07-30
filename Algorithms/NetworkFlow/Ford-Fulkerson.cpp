// **** 주의 **** //
// 모든 정점 번호는 0보다 커야한다. (par[S] = 0 으로 사용하기 때문.)
const int MAXND = 500, S = 1, T = 2, INF = 0x3fffffff;
struct nflow {
	struct edge {
		edge* rev; // 외부에서 초기화
		int v, c, f; // 모두 초기화 필요
		edge(int v, int c) : v(v), c(c), f(0) { }
		int res() { return c-f; } // residual capacity
		int flow(int x) { f += x, rev->f -= x; }
	};
	vector<edge*> g[MAXND]; // 객체 생성 시 초기화 필요
	int par[MAXND]; // flow마다 초기화
	edge* pedg[MAXND]; // 초기화 불필요
					  // 없어도 되나?
					  // nflow() {
					  // 	FOR(i, 0, MAXN) g[i] = vector<edge*>();
					  // }
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