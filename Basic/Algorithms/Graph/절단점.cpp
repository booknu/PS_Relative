/************
< �ּ� >      : http://codeforces.com/contest/1000/problem/E
*************
< �ذ��� >   :
������ ��, ������ ����, �� �� s, t�� ���� �ش� s, t ������ ��� ��� �� ���� ������ �� �ۿ� ���� �����鸸 ����.
�� �� �������� ������ �ִ�ȭ ��Ű�� �����̴�.

���� ���õǴ� �������� bridge�� ���ۿ� ����.

dfs spanning tree�� ����� �� �����鿡 ���� bridge���� ������ �����Ѵ�.
(�� ��, �������� �������� ���� bridge�� ���� ���Ѵ�! Ʈ�������� ���ɼ� ����)

�� �� �ٽ� dfs�ϸ鼭 Ʈ��dp �������� dp[u] = u���� ������ ���������� �� �� ���� �� �ִ� �ִ� bridge �� �� ���س���,
dp[u] = max(dp[v] + u->v is bridge? 1 : 0) ���� ���� �� �ִ�.

���� �� u���� u�� ������ �ִ� s->t�� ���Ϸ��� dp[u->v] �� ���� ū �� 2���� ��� ���ϸ� �ȴ�.

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

const int MAXN = 3e5, INF = 0x7fffffff;
int n, m, ncnt, ans, vid[MAXN], par[MAXN], dp[MAXN];
vii g[MAXN]; // fi = �� ������ bridge����?
void input() {
	cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].pb({ 0, v });
		g[v].pb({ 0, u });
	}
}

// bridge ã��
int dfs(int u) {
	int ret = vid[u] = ncnt++;
	for(auto& e : g[u]) {
		int v = e.se, c = INF;
		if(par[u] == v) continue; // Ʈ�������� ����
		if(vid[v] == -1) { // Ʈ������
			par[v] = u;
			c = min(c, dfs(v));
		} else c = min({ c, vid[v], vid[u] }); // ������ or ������
		if(c > vid[u]) e.fi = 1; // bridge
		ret = min(ret, c);
	}
	return ret;
}

void f(int u) {
	int fir = 0, sec = 0;
	for(auto& e : g[u]) {
		int v = e.se, c = e.fi;
		if(par[v] != u) continue;
		f(v);
		dp[u] = max(dp[u], dp[v] + c);
		sec = max(sec, dp[v] + c);
		if(fir < sec) swap(fir, sec);
	}
	ans = max(ans, fir + sec);
}

int solve() {
	memset(vid, -1, sizeof(vid));
	dfs(0);
	f(0);
	cout << ans << ENDL;
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