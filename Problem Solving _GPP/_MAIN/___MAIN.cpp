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

const int MAXN = 1e4+10;
const char clis[2] = { 'R', 'B' };
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

int n, m, ar[MAXN], ord[MAXN], ans[MAXN];
vi scs[MAXN];
vvi g;
vii pic[MAXN];
void input() {
	cin >> n >> m;
	FOR(i, 0, m) {
		FOR(k, 0, 3) {
			int u; char c; cin >> u >> c; --u;
			FOR(j, 0, 2) {
				if(c == clis[j]) pic[i].pb({ u, j });
			}
		}
	}
	g.assign(2*n, vi());
}

// u
int nd(int u, int nott) {
	return u + nott * n;
}

// ~u
int opnd(int u) {
	return (u + n) % (2*n);
}

// u || v
void addedg(int u, int v) {
	g[opnd(u)].pb(v);
	g[opnd(v)].pb(u);
}

int solve() {
	// 한 사람에 대한 식 추가
	FOR(i, 0, m) {
		FOR(j, 0, 3) {
			addedg(nd(pic[i][j].fi, pic[i][j].se), nd(pic[i][(j+1)%3].fi, pic[i][(j+1)%3].se));
		}
	}
	// SCC
	tarjan tj(g);
	vi scc = tj.getScc();
	// 같은 scc에 ~x, x 같이 들어있는지 확인
	FOR(u, 0, n) if(scc[u] == scc[u+n]) {
		cout << -1 << ENDL;
		return 0;
	}
	// 변수 대입
	FOR(i, 0, 2*n) ord[i] = i;
	sort(ord, ord + 2*n, [&](int u, int v) { return scc[u] > scc[v]; });
	memset(ans, -1, sizeof(ans));
	FOR(i, 0, 2*n) {
		int u = ord[i];
		if(ans[u%n] == -1) ans[u%n] = !(u<n);
	}
	FOR(i, 0, n) cout << (clis[!ans[i]]); cout << ENDL;
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