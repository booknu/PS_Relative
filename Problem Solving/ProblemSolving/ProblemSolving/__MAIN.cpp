#include <bits/stdc++.h>
using namespace std;

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

const int MAXN = 1e4+10;
const i64 INF = 0x7fffffffffffffff;
i64 n, m, t, ar[MAXN], par[MAXN];
i64 dis[MAXN];
vii g[MAXN];
vi g2[MAXN];
void input() {
	cin >> n >> m >> t;
	FOR(i, 0, n) cin >> ar[i];
	while(m--) {
		int u, v, c; cin >> u >> v >> c; --u, --v;
		g[u].pb({ c, v });
		g[v].pb({ c, u });
	}
}

i64 ans = 0;
i64 f(int u) {
	i64 ret = ar[u];
	for(int v : g2[u]) {
		ret += f(v);
	}
	if(t < dis[u]) ans = max(ans, (dis[u]-t) * ret);
	return ret;
}

int solve() {
	memset(par, -1, sizeof(par));
	FOR(i, 0, MAXN) {
		dis[i] = INF;
	}
	priority_queue<pair<i64, int>> q;
	q.push({ 0, 0 });
	dis[0] = 0;
	while(q.size()) {
		int u = q.top().se;
		i64 cdis = -q.top().fi;
		q.pop();
		if(cdis > dis[u]) continue;
		for(ii& e : g[u]) {
			int v = e.se, c = e.fi;
			if(dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				par[v] = u;
				q.push({ -dis[v], v });
			} else if(dis[v] == dis[u] + c &&  u < par[v]) {
				par[v] = u;
			}
		}
	}
	FOR(i, 1, n) {
		g2[par[i]].pb(i);
	}
	f(0);
	cout << ans << ENDL;
	return 0;
}

// ................. main .................. //
void execute() {
	input(), solve();
}

int main(void) {
#ifdef LOCAL_BOOKNU
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	cin.tie(0), ios_base::sync_with_stdio(false);
	execute();
	return 0;
}
// ......................................... //