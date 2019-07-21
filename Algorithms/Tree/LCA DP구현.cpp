/************
< 주소 >      : https://www.acmicpc.net/problem/6059
*************
< 해결방안 >   :
LCA
2의 제곱수를 이용해 dif를 효율적으로 줄여간다는게 포인트.
dif를 이진수로 표현해 1인 비트를 지워가는 것과 같음.

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

const int MAXN = 1e3, LOGN = 12;
int n, q, h[MAXN], dis[MAXN], par[MAXN][LOGN];
vii g[MAXN];
void input() {
	cin >> n >> q;
	FOR(i, 0, n-1) {
		int u, v, c; cin >> u >> v >> c; --u, --v;
		g[u].pb({ c, v });
		g[v].pb({ c, u });
	}
}

// dfs 트리를 만들자.
void dfs(int u) {
	for(auto& e : g[u]) {
		int v = e.se, c = e.fi;
		if(h[v] == -1) {
			par[v][0] = u;
			h[v] = h[u] + 1;
			dis[v] = dis[u] + c;
			dfs(v);
		}
	}
}
// 1. 일단 둘의 깊이 차를 없앤다.
// 2. 이제 깊이 차는 없는데, u, v가 다르면 동시에 끌어올려준다.
int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	int dif = h[u] - h[v];
	// 깊이 차(diff)를 없애며 u를 이동시킴
	for(int j = 0; dif; j++) {
		if(dif % 2) u = par[u][j];
		dif /= 2;
	}
	// u, v가 다르면 동시에 일정 높이만큼 끌어올림.
	if(u != v) {
		// 높이가 높은 순으로 시도
		RFOR(j, LOGN-1, 0) {
			if(par[u][j] != -1 && par[u][j] != par[v][j]) {
				u = par[u][j];
				v = par[v][j];
			}
		}
		// 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
		u = par[u][0];
	}
	return u;
}

int solve() {
	memset(h, -1, sizeof(h));
	memset(par, -1, sizeof(par));
	h[0] = 0;
	dis[0] = 0;
	dfs(0);
	// par[i][j+1] = par[par[i][j]][j]: 2^j를 두 번 뛰어오름.
	FOR(j, 1, LOGN) {
		FOR(i, 1, n) {
			if(par[i][j-1] != -1) {
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
	}
	while(q--) {
		int u, v; cin >> u >> v; --u, --v;
		int r = lca(u, v);
		cout << dis[u] + dis[v] - 2*dis[r] << ENDL;
	}
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
}
// ......................................... //