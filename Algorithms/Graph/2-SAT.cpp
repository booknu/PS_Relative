/*
	2-SAT: (A || B) && (C || D) && (E || F) ...
	1. X || Y = !X -> Y, !Y -> X  (Proposition)
		False: T -> F, True: Others
	2. !X, X in same SCC: no solution
	3. For every SCC, each node in same SCC must have same flag (if both T, F exists in same SCC, T->F exists)
	4. Assign False to (Don't have in edge & Unassigned node) and erase node
		- sort nodes topologically, iterate nodes with assigning False to var if var is unassigned
			- !X node: X = True, X node: X = False
*/
struct sat2 {
	struct tarjan {
		int n, ncnt, scnt;
		vi scc, dis;
		vvi g;
		stack<int> sta;
		tarjan(int n) : n(n), g(n, vi()) { } // n: number of variables (NOT NODES!)
		void addedge(int u, int v) { g[u].pb(v); } // directed graph
		int f(int u) {
			int ret = dis[u] = ncnt++;
			sta.push(u);
			for(int v : g[u]) {
				if(dis[v] == -1) ret = min(ret, f(v));
				else if(scc[v] == -1) ret = min(ret, dis[v]);
			}
			if(ret == dis[u]) {
				while(1) {
					int t = sta.top(); sta.pop();
					scc[t] = scnt;
					if(t == u) break;
				}
				++scnt;
			}
			return ret;
		}
		vi& get_scc() {
			ncnt = scnt = 0;
			scc = dis = vi(n, -1);
			sta = stack<int>();
			FOR(i, 0, n) if(dis[i] == -1) f(i);
			dis.clear();
			return scc;
		}
	};
	int n;
	vi res;
	tarjan tj;
	sat2(int n) : n(n), tj(2*n) { }
	int nd(int u, int neg) { return u + neg*n; } // var u's node
	int neg(int u) { return (u+n)%(2*n); } // ~u
	void addedge(int u, int nu, int v, int nv) { // add (X || Y) clauses
		u = nd(u, nu), v = nd(v, nv);
		tj.addedge(neg(u), v);
		tj.addedge(neg(v), u); 
	} 
	vi& solve() { // return solved vars, if no solution return vi()
		vi& scc = tj.get_scc();
		FOR(u, 0, n) if(scc[u] == scc[u+n]) return res;
		res.assign(n, -1);
		vi ord(2*n);
		FOR(i, 0, 2*n) ord[i] = i;
		sort(ALL(ord), [&](int u, int v) { return scc[u] > scc[v]; });
		FOR(i, 0, 2*n) {
			int u = ord[i];
			if(res[u%n] == -1) res[u%n] = !(u<n);
		}
		return res;
	}
};