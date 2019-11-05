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
const int MAXN = 1e4+10;
int n, m, res[MAXN];
vvi g;

int nd(int u, int nott) { // u
	return u + nott * n;
}

int opnd(int u) { // ~u
	return (u + n) % (2*n);
}

void addedg(int u, int v) { // u || v
	g[opnd(u)].pb(v);
	g[opnd(v)].pb(u);
}

int solve() {
	// add (X || Y) Clauses
	FOR(i, 0, m) addedge(x[i], y[i]);
	// SCC
	tarjan tj(g); vi scc = tj.getScc();
	// X, !X in same SCC
	FOR(u, 0, n) if(scc[u] == scc[u+n]) {
		cout << -1 << ENDL;
		return 0;
	}
	// find solution
	FOR(i, 0, 2*n) ord[i] = i;
	sort(ord, ord + 2*n, [&](int u, int v) { return scc[u] > scc[v]; });
	memset(res, -1, sizeof(res));
	FOR(i, 0, 2*n) {
		int u = ord[i];
		if(res[u%n] == -1) res[u%n] = !(u<n);
	}
	return 0;
}