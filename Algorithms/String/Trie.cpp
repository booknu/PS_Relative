const int MAX_NODE = 1e6+10;
int cld[MAX_NODE][30];
i64 cnt[MAX_NODE];
int ncnt = 1;
void push(const string& x) {
	int u = 0;
	FOR(i, 0, x.size()) {
		if(!cld[u][x[i]-'a']) cld[u][x[i]-'a'] = ncnt++;
		u = cld[u][x[i]-'a'];
	}
	++cnt[u];
}
void calc_back(int u) {
	FOR(i, 0, 30) {
		if(cld[u][i]) {
			calc_back(cld[u][i]);
			cnt[u] += cnt[cld[u][i]];
		}
	}
	cnt[u] %= MOD;
}