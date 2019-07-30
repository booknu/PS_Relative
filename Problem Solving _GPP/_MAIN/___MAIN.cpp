#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class key, class value, class cmp = less<key>>
using treemap = tree<key, value, less<int>, rb_tree_tag, tree_order_statistics_node_update>; // key, val, comp, implements, 노드 불변 규칙
template<class key, class cmp = less<key>>
using treeset = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL_BOOKNU
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ........................macro.......................... //
#define FOR(i, f, n) for(int (i) = (f); (i) < (int)(n); ++(i))
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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long i64;
typedef unsigned long long ui64;
// inline i64 GCD(i64 a, i64 b) { if(b == 0) return a; return GCD(b, a % b); }
inline int getidx(const vi& ar, int x) { return lower_bound(ALL(ar), x) - ar.begin(); } // 좌표 압축에 사용: 정렬된 ar에서 x의 idx를 찾음
inline i64 GCD(i64 a, i64 b) { i64 n; if(a < b) swap(a, b); while(b != 0) { n = a % b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // 음수일 때 이상하게 작동할 수 있음.
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d) * 2 >= d); }
const i64 MOD = 1e9+7;
inline i64 POW(i64 a, i64 n) {
	assert(0 <= n);
	i64 ret;
	for(ret = 1; n; a = a*a%MOD, n /= 2) { if(n%2) ret = ret*a%MOD; }
	return ret;
}
template <class T> ostream& operator<<(ostream& os, vector<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class T> ostream& operator<<(ostream& os, set<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class L, class R> ostream& operator<<(ostream& os, pair<L, R> p) { return os << "(" << p.fi << "," << p.se << ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H, debug_out(T...); }
// ....................................................... //

const int MAXN = 12, MAXND = MAXN*MAXN;
const int dy[6] = { 0, 0, -1, -1, 1, 1 }, dx[6] = { -1, 1, -1, 1, -1, 1 };
int n, m, ato[MAXND], bto[MAXND], vis[MAXND];
string ar[MAXN];
vi g[MAXND];
void input() {
	cin >> n >> m;
	FOR(i, 0, n) cin >> ar[i];
}

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

int bmatch() {
	memset(ato, -1, sizeof(ato));
	memset(bto, -1, sizeof(bto));
	int ret = 0;
	FOR(y, 0, n) FOR(x, 0, m) {
		if(x%2) {
			memset(vis, 0, sizeof(vis));
			if(dfs(y*m+x)) ++ret;
		}
	}
	return ret;
}

int solve() {
	FOR(i, 0, MAXND) g[i].clear();
	FOR(y, 0, n) FOR(x, 0, m) {
		if(x%2 && ar[y][x] == '.') {
			FOR(dir, 0, 6) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if(0 <= ny && ny < n && 0 <= nx && nx < m && ar[ny][nx] == '.') {
					g[y*m+x].pb(ny*m+nx);
				}
			}
		}
	}
	int tot = 0;
	FOR(y, 0, n) FOR(x, 0, m) if(ar[y][x] == '.') ++tot;
	cout << tot - bmatch() << ENDL;
	return 0;
}

// ................. main .................. //
void execute() {
	int TT; cin >> TT;
	while(TT--)
	input(), solve();
}

int main(void) {
#ifdef LOCAL_BOOKNU
	freopen("__IO/input.txt", "r", stdin);
	// freopen("__IO/out.txt", "w", stdout);
#endif
	cin.tie(0), ios_base::sync_with_stdio(false);
	execute();
	return 0;
}
// ......................................... //