struct tarjan {
	int n, ncnt, scnt;
	vi scc, dis;
	vvi& g;
	stack<int> sta;
	tarjan(vvi& _g) : g(_g), n(_g.size()), ncnt(0), scnt(0), scc(n, -1), dis(n, -1) { }
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
	vi& getScc() {
		FOR(i, 0, n) if(dis[i] == -1) f(i);
		dis.clear();
		return scc;
	}
};