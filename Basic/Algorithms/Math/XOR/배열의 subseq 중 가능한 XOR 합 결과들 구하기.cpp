/************
< 주소 >      : http://codeforces.com/contest/959/problem/F
*************
< 해결방안 >   :
우선, 문제를 해당 구간에서 xor sum의 결과가 k인 수를 세는 것이 아닌, k인게 존재하는지 여부를 알아내는 것으로 생각하자.

이것은 현재 i에 대해 모든 가능한 xor 결과를 유지하며 x^a[i]를 set에 추가해나가면 쉽게 구할 수 있다.
(최초 set은 0을 포함하고 있어야 함.)

하지만, 이것은 O(nA) || O(nAlogA) 시간이 걸리므로 불가능하다.

여기서 두 가지 관찰을 하자.
1. x, y가 set에 존재한다면, x^y도 set에 존재한다.
   이것은 xor 특성을 생각하면 쉽게 알 수 있다.
   x -----
		----- y
	 ---  --- x^y
   이런 식으로 x, y는 각각 현재 a의 i까지 원소들 중 일부를 xor한 결과일 것이고, 그것은 ai가 현재 x에 포함됐는지, 안 됐는지로 표현할 수 있다.
   x, y둘 다에 포함된 원소는 x^y에서 걸러질 것이고, 결국 남는 것도 a의 일부 xor 결과일텐데, 이것도 당연히 set에 있을 것이다.
2. x가 set에 존재하고, y가 set에 존재하지 않는다면, x^y도 set에 존재하지 않을 것이다.
   귀류법으로 증명 가능하다.
   x^y가 set에 존재한다고 가정하면, (x^y)^x도 set에 존재할 것이다. (1번과 마찬가지의 이유로)
   (x^y)^x = y인데, y는 set에 존재하지 않는다고 했으니 모순이다.
   따라서 x^y는 set에 존재하지 않는다.


이제 dp 식을 짜보자. (존재 여부가 아닌, 경우의 수를 세자.)
dp[i][x] = dp[i-1][x] + dp[i-1][x^a[i]]
이 때, 모든 a[i]의 결과에 대해 dp를 수정 할 필요가 없다.
1. a[i]가 set에 존재 할 경우: 현재 dp[i][x]의 존재하는 모든 x에 dp[i-1][x]*2를 적용한다.
2. a[i]가 set에 존재하지 않을 경우: set에 a[i]^setx 를 넣는다. (경우의 수는 바뀌지 않는다.)

따라서 쿼리 소팅을 한 후, dp를 적용하며 답을 만들어가면 된다.
= O((n + A)log(A))

*************
< 오답노트 >   :
[ 추가 문제 ]
A = 2^30, online으로 처리해야 한다는 조건이 붙으면 선형 결합을 통해 해결해야 한다. --> Editorial 참조!

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
inline int getidx(const vi& ar, int x) { lower_bound(ALL(ar), x) - ar.begin(); } // 좌표 압축에 사용: 정렬된 ar에서 x의 idx를 찾음
inline i64 GCD(i64 a, i64 b) { i64 n; if(a<b) swap(a, b); while(b!=0) { n = a%b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ....................................................... //

const int MAXN = 1e5, RANGE = (1 << 20) + 1;
const i64 MOD = 1e9 + 7;
int n, q, ar[MAXN], l[MAXN], x[MAXN], ord[MAXN], res[MAXN];
set<int> s;
void input() {
	cin >> n >> q;
	FOR(i, 0, n) cin >> ar[i];
	FOR(i, 0, q) cin >> l[i] >> x[i], --l[i];
}

int solve() {
	FOR(i, 0, q) ord[i] = i;
	sort(ord, ord + q, [](int u, int v) { return l[u] < l[v]; });
	int p = 0;
	i64 cnt = 1;
	s.insert(0);
	FOR(i, 0, n) {
		if(s.count(ar[i])) (cnt *= 2) %= MOD;
		else {
			for(auto& u : s) s.insert(u^ar[i]);
		}
		while(p < q && l[ord[p]] == i) {
			debug(l[ord[p]]);
			res[ord[p]] = (s.count(x[ord[p]]) ? cnt : 0);
			++p;
		}
	}
	FOR(i, 0, q) cout << res[i] << ENDL;
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