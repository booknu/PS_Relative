const int WINF = 0x3fffffff, FINF = 0x3fffffff; // weight/flow inf
struct mcmf {
	struct edg { int v, c, r, w; };
	int n;
	vi dis, par, peg;
	vector<bool> inq;
	vector<vector<edg> > g;
	mcmf(int n) : n(n), g(n, vector<edg>()), par(n), peg(n) {  }
	void addedge(int u, int v, int c, int w) {
		g[u].pb({ v, c, sz(g[v]), w });
		g[v].pb({ u, 0, sz(g[u])-1, -w });
	}
	bool spfa(int s, int t) {
		dis.assign(n, WINF);
		inq.assign(n, 0);
		queue<int> q;
		dis[s] = 0;
		inq[s] = 1;
		q.push(s);
		bool ok = 0;
		while(q.size()) {
			int u = q.front(); q.pop();
			if(u == t) ok = 1;
			inq[u] = 0;
			FOR(eidx, 0, g[u].size()) {
				auto [v, c, r, w] = g[u][eidx];
				if(c > 0 && dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					par[v] = u;
					peg[v] = eidx;
					if(!inq[v]) {
						inq[v] = 1;
						q.push(v);
					}
				}
			}
		}
		return ok;
	}
	ii flow(int s, int t) { // return (max_flow, min_cost)
		int cost = 0, flow = 0;
		while(spfa(s, t)) {
			int cur = FINF;
			for(int u = t; u != s; u = par[u]) cur = min(cur, g[par[u]][peg[u]].c);
			for(int u = t; u != s; u = par[u]) {
				int r = g[par[u]][peg[u]].r;
				g[par[u]][peg[u]].c -= cur;
				g[u][r].c += cur;
			}
			flow += cur;
			cost += dis[t] * cur;
		}
		return { flow, cost };
	}
};