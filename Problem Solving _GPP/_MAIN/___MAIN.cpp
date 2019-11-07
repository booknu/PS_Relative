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

const int ST_MAX = 1<<21, lf = ST_MAX/2; 
struct segtree{
    i64 t[ST_MAX], d[ST_MAX];
    segtree(){ memset(t, 0, sizeof(t)), memset(d, 0, sizeof(d)); }
    void build(){ RFOR(i, lf-1, 1) t[i] = t[i*2]+ t[i*2+1]; } // !! BUILD !!
    void propagate(int u, int ns, int ne){
        if(!d[u]) return;
		if(u < lf){ // propagate to childs
			d[u*2] += d[u];
			d[u*2+1] += d[u];
		}
		t[u] += d[u] * (ne-ns); // update node
		d[u] = 0;
    }
    void add(int s, int e, int x){ add(s, e, x, 1, 0, lf); } // [s, e)
    void add(int s, int e, int x, int u, int ns, int ne){
        propagate(u, ns, ne);
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            d[u] += x;
            propagate(u, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        add(s, e, x, u*2, ns, mid), add(s, e, x, u*2+1, mid, ne);
        t[u] = t[u*2] + t[u*2+1];
    }
    i64 sum(int s, int e){ return sum(s, e, 1, 0, lf); } // [s, e)
    i64 sum(int s, int e, int u, int ns, int ne){
        propagate(u, ns, ne);
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return t[u];
        int mid = (ns+ne)/2;
        return sum(s, e, u*2, ns, mid) + sum(s, e, u*2+1, mid, ne);
    }
};

int n, m, k;
segtree st;
void input() {
	cin >> n >> m >> k;
	m += k;
	FOR(i, 0, n) cin >> st.t[lf+i];
}

int solve() {
	st.build();
	while(m--) {
		int t; cin >> t;
		if(t == 1) {
			int s, e, x; cin >> s >> e >> x; --s;
			st.add(s, e, x);
		} else {
			int s, e; cin >> s >> e; --s;
			cout << st.sum(s, e) << ENDL;
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