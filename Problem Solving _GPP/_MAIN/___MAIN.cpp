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

const int ST_MAX = 1<<21;
struct SegTree{
	int start;
	i64 arr[ST_MAX], lazy[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}

	// 리프 노드들의 값을 먼저 입력한 후 전체 세그먼트 트리 구축
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}

	// 구간 [ns, ne)인 node의 lazy 값을 propagate
	void propagate(int node, int ns, int ne){
		// lazy 값이 존재하면 실행
		if(lazy[node] != 0){
			// 리프 노드가 아니면 자식들에게 lazy 미룸
			if(node < start){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			// 자신에 해당하는 만큼의 값을 더함
			arr[node] += lazy[node] * (ne-ns);
			lazy[node] = 0;
		}
	}

	// 구간 [s, e)에 k를 더하라
	void add(int s, int e, int k){ add(s, e, k, 1, 0, start); }
	void add(int s, int e, int k, int node, int ns, int ne){
		// 일단 propagate
		propagate(node, ns, ne);

		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			// 이 노드가 구간에 완전히 포함되면 lazy 부여 후 propagate
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(s, e, k, node*2, ns, mid);
		add(s, e, k, node*2+1, mid, ne);
		// 마지막에 자식들의 값을 사용해 다시 자신의 값 갱신
		arr[node] = arr[node*2] + arr[node*2+1];
	}

	// 구간 [s, e)의 합을 구하라
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		// 일단 propagate
		propagate(node, ns, ne);

		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

void input() {
	
}

int solve() {
	
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