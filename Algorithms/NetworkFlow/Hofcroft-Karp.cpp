/*
	- alternating path: path consists of (x, y, x, y, x) for X = { x | x is matched edge}, Y = { y | y is not mathed edge } 
	- augmenting path: path consists of (y, x, y, x, y)
	- if augmenting path exists, we can match one more edge with fliping matched state (x, y, x, y, x)

	For maximaum matching A, B
	1. lv[0] = { v | v in A and v is not matched }
	2. starting from lv[0] vertices, get alternating path with bfs
	3. starting from lv[0] vertices, get augmenting path with dfs

	* min cover: selecting minimum vertices to cover all edges
	* max independent set: selecting maximum vertices not connected with edge
	* V - min cover = max independent set
*/
struct hofcroft {
	int n, m;
	vi dis, l, r, vis, chk;
	vvi g;
	hofcroft(int n, int m) : n(n), m(m), g(n, vi()) {  }
	void addedge(int u, int v) { g[u].pb(v); }
	bool bfs() { // build alternating path starts from lv[0] nodes
		queue<int> q;
		bool ok = 0;
		dis.assign(n, 0);
		FOR(u, 0, n) {
			if(l[u] == -1 && !dis[u]) {
				q.push(u);
				dis[u] = 1;
			}
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int v : g[u]) {
				if(r[v] == -1) ok = 1; // v is not matched
				else if(!dis[r[v]]) { // if v is matched, u>v>r[v] can be path
					dis[r[v]] = dis[u] + 1;
					q.push(r[v]);
				}
			}
		}
		return ok;
	}
	bool dfs(int u) { // find augmenting path and flip it!
		if(vis[u]) return 0; // augmenting path start/end with non-matched vertices
		vis[u] = 1;
		for(int v : g[u]) {
			if(r[v] == -1 || (dis[r[v]] == dis[u] + 1 && dfs(r[v]))) {
				l[u] = v; r[v] = u;
				return 1;
			}
		}
		return 0;
	}
	int match() { // bipartite match
		l.assign(n, -1);
		r.assign(m, -1);
		int ret = 0;
		while(bfs()) {
			vis.assign(n, 0);
			FOR(u, 0, n) if(l[u] == -1 && dfs(u)) ++ret;
		}
		return ret;
	}
	void rdfs(int u) { // dfs matched
		if(chk[u]) return;
		chk[u] = 1;
		for(int v : g[u]) {
			chk[v + n] = 1;
			rdfs(r[v]);
		}
	}
	vi getcover() { // get min cover vertices
		match();
		chk.assign(n+m, 0);
		FOR(u, 0, n) if(l[u] == -1) rdfs(u);
		vi ret;
		FOR(u, 0, n) if(!chk[u]) ret.pb(u);
		FOR(u, n, n+m) if(chk[u]) ret.pb(u);
		return ret;
	}
};