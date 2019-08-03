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

const int MAXN = 1e5+10;
int n, m, qq, ar[MAXN], beg[MAXN], ps[MAXN], cont[MAXN], suf[MAXN];
i64 cnt[MAXN];
vi xs; // lis : 겹치지 않는게 최초 등장하는 위치

// PST
struct node {
	i64 x;
	node *l, *r;
	node(i64 _x = 0, node* l = 0, node* r = 0) : x(_x), l(l), r(r) {  }
	node* addtree(int u, i64 c, int ns = 0, int ne = MAXN-1) {
		if(ns <= u && u <= ne) {
			if(ns == ne) return new node(x + c, 0, 0);
			int mid = (ns+ne)/2;
			return new node(x + c, l->addtree(u, c, ns, mid), r->addtree(u, c, mid+1, ne));
		}
		return this;
	}
	// index 반환
	i64 nth(i64 k, int ns = 0, int ne = MAXN-1)  {
		if(ns == ne) {
			assert(x == k);
			return ns; // leaf
		}
		int mid = (ns+ne)/2;
		if(l->x >= k) return l->nth(k, ns, mid);
		else return r->nth(k-l->x, mid+1, ne);
	}
} *root[MAXN+1];

void input() {
	cin >> n >> m >> qq;
	xs.resize(n);
	FOR(i, 0, n) cin >> ar[i], xs[i] = ar[i];
	sort(ALL(xs));
	UNIQUE(xs);
	FOR(i, 0, n) ar[i] = getidx(xs, ar[i]);
}

int solve() {
	memset(beg, -1, sizeof(beg));
	m = xs.size();
	root[n] = new node();
	root[0] = root[n]->l = root[n]->r = root[n];
	FOR(i, 0, n) ++suf[ar[i]];
	FOR(i, 0, n) {
		if(i) ps[i] = ps[i-1]; // 겹치지 않는 개수
		if(i) root[i] = root[i-1];
		if(beg[ar[i]] == -1) beg[ar[i]] = i;
		// 빠진게 suf에서 완전히 빠지며, cont에 포함되지 않았으면
		if((--suf[ar[i]]) == 0 && !cont[ar[i]]) {
			cont[ar[i]] = 1;
			++ps[i];
			root[i] = root[i]->addtree(ar[i], 1);
		} 
	}
	FOR(i, 0, m) {
		cnt[i] = ps[beg[i]];
	}
	FOR(i, 1, m) {
		cnt[i] += cnt[i-1];
	}
	while(qq--) {
		i64 x; cin >> x;
		auto it = lower_bound(cnt, cnt + m, x);
		if(it == cnt+m) { // 불가능한 경우
			cout << -1 << ' ' << -1 << ENDL;
			continue;
		} else {
			i64 idx = it - cnt;
			i64 cc = x - (idx ? cnt[idx-1] : 0ll) - 1ll;
			int ed = root[beg[idx]]->nth(cc+1);
			cout << xs[idx] << ' ' << xs[ed] << ENDL;
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