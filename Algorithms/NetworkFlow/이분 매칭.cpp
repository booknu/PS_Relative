/************
< 주소 >      : https://www.acmicpc.net/problem/1348
*************
< 해결방안 >   :
모든 차 -> 모든 주차장 최단거리 구해놓고,
최장거리가 k일 때 모두 매칭이 가능한지 여부를 알려주는 chk(k)를 bipartite match를 통해 구현해 binary search를 하면 됨.

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
#define sz(A) (int)(A).size()
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define next next9876
#define prev prev1234
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;
// inline i64 GCD(i64 a, i64 b) { if(b == 0) return a; return GCD(b, a % b); }
inline int getidx(const vi& ar, int x) { return lower_bound(ALL(ar), x) - ar.begin(); } // 좌표 압축에 사용: 정렬된 ar에서 x의 idx를 찾음
inline i64 GCD(i64 a, i64 b) { i64 n; if(a<b) swap(a, b); while(b!=0) { n = a%b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // 음수일 때 이상하게 작동할 수 있음.
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
	return os << "(" << p.fi << "," << p.se << ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ....................................................... //

const int MAXN = 50, MAXCAR = 100, INF = 0x3ffffff;
const int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

int n, m;
string mp[MAXN];
vii sp, tp;
vvi spath[MAXCAR];
vi g[MAXCAR];
void input() {
	cin >> n >> m;
	FOR(i, 0, n) cin >> mp[i];
}

vvi getspath(int sy, int sx) {
	queue<ii> q;
	vvi dis(n, vi(m, INF));
	dis[sy][sx] = 0;
	q.push({ sy, sx });
	while(q.size()) {
		int y = q.front().fi, x = q.front().se; q.pop();
		FOR(dir, 0, 4) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(0 <= ny && ny < n && 0 <= nx && nx < m && mp[ny][nx] != 'X' && dis[ny][nx] == INF) {
				dis[ny][nx] = dis[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
	return dis;
}

// ************* Bipartite Match ************* //
vi ato, bto;
bool vis[MAXCAR];
bool dfs(int u) {
	if(vis[u]) return false;
	vis[u] = 1;
	for(int v : g[u]) {
		if(bto[v] == -1 || dfs(bto[v])) {
			ato[u] = v, bto[v] = u;
			return true;
		}
	}
	return false;
}

int bimatch() {
	ato.assign(sp.size(), -1), bto.assign(tp.size(), -1);
	int ret = 0;
	FOR(i, 0, sp.size()) {
		memset(vis, 0, sizeof(vis));
		if(dfs(i)) ++ret;
	}
	return ret;
}
// ******************************************** //

bool chk(int k) {
	FOR(i, 0, sp.size()) {
		g[i].clear();
		FOR(j, 0, tp.size()) {
			if(spath[i][tp[j].fi][tp[j].se] <= k) {
				g[i].pb(j);
			}
		}
	}
	return bimatch() == sp.size();
}

int solve() {
	FOR(i, 0, n) FOR(j, 0, m) if(mp[i][j] == 'C') sp.pb({ i, j }); else if(mp[i][j] == 'P') tp.pb({ i, j });
	FOR(i, 0, sp.size()) spath[i] = getspath(sp[i].fi, sp[i].se);
	int lo = -1, hi = INF;
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(chk(mid)) hi = mid;
		else lo = mid;
	}
	if(hi == INF) cout << -1 << ENDL;
	else cout << hi << ENDL;
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