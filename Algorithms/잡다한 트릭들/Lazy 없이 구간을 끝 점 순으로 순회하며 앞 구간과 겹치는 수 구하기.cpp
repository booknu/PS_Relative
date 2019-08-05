#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class key, class value, class cmp = less<key>>
using treemap = tree<key, value, less<int>, rb_tree_tag, tree_order_statistics_node_update>; // key, val, comp, implements, ��� �Һ� ��Ģ
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
inline int getidx(const vi& ar, int x) { return lower_bound(ALL(ar), x) - ar.begin(); } // ��ǥ ���࿡ ���: ���ĵ� ar���� x�� idx�� ã��
inline i64 GCD(i64 a, i64 b) { i64 n; if(a < b) swap(a, b); while(b != 0) { n = a % b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // ������ �� �̻��ϰ� �۵��� �� ����.
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
template <class T> ostream& operator<<(ostream& os, multiset<T> v) {
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
int n;
ii seg[MAXN];
void input() {
	cin >> n;
	FOR(i, 0, n) cin >> seg[i].fi >> seg[i].se;
}

// https://www.acmicpc.net/problem/17364
// �����Ϸ��� multiset + fenwick ����ؼ� ���� �ɵ� (fenwick�� ����ص� �ǳ�?)
int solve() {
	// end ������ ��ȸ
	sort(seg, seg + n, [&](ii& u, ii& v) { return u.se < v.se; });
	multiset<int> s; // ���� �ֱٿ� ���� ������ ����
	FOR(i, 0, n) {
		// ���� ������ l�� ������ set ���� �� ���� ��� ������ ��ġ�� ��!!
		// ��, set[l..]�� ������ �� ���� ������ �� �������� ��ġ�� ��!!
		// ��, �� ���� ���� �������� ���� ���� ����!! (��ȸ ������ ���� ���� �����̶� ��ġ�� ���� �ٸ��� counting)
		auto l = s.lower_bound(seg[i].fi);
		// �̰��� ��, ���� ������ --l���� ��ġ�� �ʴµ�, ��ȸ�� �������̹Ƿ� �ִ��� �����ʿ��� ������ ������ �����ϴ°� �̵��̹Ƿ� �̰ɷ� �ٲ��� ��!
		// �ᱹ �� ��ġ�� ������ ������ ������, �� ���� �� ����� ������ ��ġ���� ������ �� ����!!
		if(l != s.begin()) s.erase(--l);
		s.insert(seg[i].se);
		debug(s);
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