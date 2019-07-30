const int MAXN = 5e2+10;
int vis[MAXN], ato[MAXN], bto[MAXN];

bool dfs(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int v : g[u]) {
		if(bto[v] == -1 || dfs(bto[v])) {
			ato[u] = v;
			bto[v] = u;
			return 1;
		}
	}
	return 0;
}

int bimatch() {
	memset(ato, -1, sizeof(ato)), memset(bto, -1, sizeof(bto));
	int ret = 0;
	FOR(u, 0, n) {
		memset(vis, 0, sizeof(vis));
		if(dfs(u)) ++ret;
	}
	return ret;
}