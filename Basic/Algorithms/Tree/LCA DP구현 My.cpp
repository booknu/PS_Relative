/************
< 주소 >      : https://www.acmicpc.net/problem/11437
*************
< 해결방안 >   :
LCA

*************
< 오답노트 >   :

*************/

#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;

// ........................macro.......................... //
// [i, n)
#define FOR(i, f, n) for(int (i) = (f); (i) < (int)(n); ++(i))
// [i, n]
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (int)(n); --(i))
#define pb push_back
#define emb emplace_back
#define fi first
#define se second
#define ENDL '\n'
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;
inline i64 GCD(i64 a, i64 b) { while(b != 0) { int t = a; a = b; b = t % b; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a*b / GCD(a, b); }
inline i64 CEIL(i64 n, i64 d) { return n / d + n % d != 0; }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //

const int MAXN = 5e4, LOGN = 18;
int n, q, par[MAXN][LOGN], dep[MAXN];
vi g[MAXN];
void input() {
	cin >> n;
	FOR(i, 0, n-1) {
		int u, v; cin >> u >> v, --u, --v;
		g[u].pb(v), g[v].pb(u);
	}
	cin >> q;
}

void dfs(int u) {
	for(auto& v : g[u]) {
		if(par[v][0] == -1) {
			par[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int dif = dep[u] - dep[v];
	for(int i = 0; dif; ++i) {
		if(dif & (1 << i)) {
			dif -= (1 << i);
			u = par[u][i];
		}
	}
	if(u != v) {
		RFOR(i, LOGN-1, 0) {
			if(par[u][i] != -1 && par[u][i] != par[v][i]) {
				u = par[u][i], v = par[v][i];
			}
		}
		u = par[u][0];
	}
	return u;
}

int solve() {
	memset(par, -1, sizeof(par));
	par[0][0] = 0;
	dfs(0);
	FOR(j, 1, LOGN) {
		FOR(i, 0, n) {
			if(par[i][j-1] != -1) par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	while(q--) {
		int u, v; cin >> u >> v; --u, --v;
		cout << lca(u, v)+1 << ENDL;
	}
	return 0;
}

// ................. main .................. //
void execute() {
	input(), solve();
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	cin.tie(0); ios_base::sync_with_stdio(false);
	execute();
	return 0;
}
// ......................................... //