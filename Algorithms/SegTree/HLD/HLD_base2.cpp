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

const int MAXN = 1e5+10, LOGN = 18;
struct fenwick {
	int n;
	vector<i64> t;
	void init(int _n) { n = _n; t.assign(n+1, 0); }
	void add(int u, i64 x) { for(++u; u <= n; u += (u&-u)) t[u] += x; }
	i64 sum(int u) { i64 ret = 0; for(++u; u > 0; u -= (u&-u)) ret += t[u]; return ret; }
	i64 sum(int s, int e) { return sum(e) - sum(s-1); }
};

int n, hn, qq, par[MAXN][LOGN], dep[MAXN], ssz[MAXN], hidx[MAXN];
vii g[MAXN];
vi hvy[MAXN];
vector<fenwick> segs;
void input() {
	cin >> n;
	FOR(i, 0, n-1) {
		int u, v, c; cin >> u >> v >> c; --u, --v;
		g[u].pb({ v, c });
		g[v].pb({ u, c });
	}	
	cin >> qq;
}

void dfs_init(int u) {
	ssz[u] = 1;
	FOR(j, 1, LOGN) par[u][j] = par[par[u][j-1]][j-1];
	for(auto [v, c] : g[u]) {
		if(par[u][0] == v) continue;
		par[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs_init(v);
		ssz[u] += ssz[v];
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int dif = dep[u] - dep[v];
	FOR(j, 0, LOGN) if(dif & (1<<j)) u = par[u][j];
	if(u != v) {
		RFOR(j, LOGN-1, 0) if(par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];
		u = par[u][0];
	}
	return u;
}

void hld(int rt) {
	hidx[rt] = -1;
	queue<int> q;
	q.push(rt);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(auto [v, c] : g[u]) if(par[v][0] == u) q.push(v);
		int p = par[u][0];
		if(u != rt) {
			if(p != rt && ssz[u]*2 >= ssz[p]) {
				hidx[u] = hidx[p];
				hvy[hidx[u]].pb(u);
			} else {
				hidx[u] = hn++;
				hvy[hidx[u]].pb(p);
				hvy[hidx[u]].pb(u);
			}
		}
	}
}

void init_segs() {
	segs.assign(hn, fenwick());
	FOR(i, 0, hn) {
		segs[i].init(hvy[i].size()-1);
	}
}

int eidx(int v) {
	return dep[par[v][0]] - dep[hvy[hidx[v]][0]];
}

i64 query_to(int u, int v) {
	if(u == v) return 0;
	if(hidx[u] == hidx[v]) return segs[hidx[v]].sum(eidx(u)+1, eidx(v));
	else return query_to(u, hvy[hidx[v]][0]) + segs[hidx[v]].sum(0, eidx(v));
}

i64 query(int u, int v) {
	int t = lca(u, v);
	return query_to(t, u) + query_to(t, v);
}

i64 kth(int u, int v, int k) {
	int t = lca(u, v);
	if(k < dep[u]-dep[t]+1) {
		RFOR(i, LOGN-1, 0) if((1<<i) & k) u = par[u][i];
		return u;
	} else {
		k -= dep[u]-dep[t];
		k = (dep[v]-dep[t]) - k;
		RFOR(i, LOGN-1, 0) if((1<<i) & k) v = par[v][i];
		return v;
	}
}

int solve() {
	dfs_init(0);
	hld(0);
	init_segs();
	FOR(u, 0, n) {
		for(auto [v, c] : g[u]) {
			if(par[u][0] == v) continue;
			segs[hidx[v]].add(eidx(v), c);
		}
	}
	while(qq--) {
		int t, u, v; cin >> t >> u >> v; --u, --v;
		if(t == 1) {
			cout << query(u, v) << ENDL;
		} else {
			int k; cin >> k; --k;
			cout << kth(u, v, k)+1 << ENDL;
		}
	}
	return 0;
}

// ................. main .................. //
void execute() {
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