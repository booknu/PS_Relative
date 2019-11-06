/*
	1. build level graph with bfs ( O(E) )
	2. flow blocking flow in level graph ( O(VE) )
	In each step, level grows at least by 1, and eventually grows upto O(V)
	So total time complexity is O(V^2E)
*/
struct dinic { // O(V^2 E)
	struct edg { int v, c, r; };
	int n;
	vi dis, itr;
	vector<vector<edg>> g;
	dinic(int n) : n(n), g(n, vector<edg>()), dis(n), itr(n) {  }
	void addedge(int u, int v, int c) {
		g[u].pb({ v, c, sz(g[v]) });
		g[v].pb({ u, 0, sz(g[u])-1 });
	}
	bool bfs(int s, int t) { // build level graph
		dis.assign(n, 0), itr.assign(n, 0);
		queue<int> q;
		q.push(s);
		dis[s] = 1;
		while(q.size()) {
			int u = q.front(); q.pop();
			for(auto& [v, c, r] : g[u]) {
				if(c > 0 && !dis[v]) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[t] > 0;
	}
	int dfs(int u, int t, int f) { // get blocking flow
		if(u == t) return f;
		for( ; itr[u] < g[u].size(); itr[u]++) {
			auto& [v, c, r] = g[u][itr[u]];
			if(c > 0 && dis[v] == dis[u] + 1) {
				int w = dfs(v, t, min(f, c));
				if(w) {
					g[u][itr[u]].c -= w;
					g[v][r].c += w;
					return w;
				}
			}
		}
		return 0;
	}
	i64 nflow(int s, int t) { // network flow
		i64 ret = 0;
		while(bfs(s, t)) {
			int r;
			while(r = dfs(s, t, 2e9)) ret += r, debug("-----");
		}
		return ret;
	}
};