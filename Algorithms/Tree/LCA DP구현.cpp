/************
< �ּ� >      : https://www.acmicpc.net/problem/6059
*************
< �ذ��� >   :
LCA
2�� �������� �̿��� dif�� ȿ�������� �ٿ����ٴ°� ����Ʈ.
dif�� �������� ǥ���� 1�� ��Ʈ�� �������� �Ͱ� ����.

*************
< �����Ʈ >   :

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

// dfs Ʈ���� ������.
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
// 1. �ϴ� ���� ���� ���� ���ش�.
// 2. ���� ���� ���� ���µ�, u, v�� �ٸ��� ���ÿ� ����÷��ش�.
int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	int dif = h[u] - h[v];
	// ���� ��(diff)�� ���ָ� u�� �̵���Ŵ
	for(int j = 0; dif; j++) {
		if(dif % 2) u = par[u][j];
		dif /= 2;
	}
	// u, v�� �ٸ��� ���ÿ� ���� ���̸�ŭ ����ø�.
	if(u != v) {
		// ���̰� ���� ������ �õ�
		RFOR(j, LOGN-1, 0) {
			if(par[u][j] != -1 && par[u][j] != par[v][j]) {
				u = par[u][j];
				v = par[v][j];
			}
		}
		// �������� �� ���� u, v�� �θ� �����Ƿ� �� �� �� �ø�
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
	// par[i][j+1] = par[par[i][j]][j]: 2^j�� �� �� �پ����.
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