/************
< 주소 >      : https://www.acmicpc.net/problem/9248
*************
< 해결방안 >   :
<< Suffix Array >>
sfx[i] = i번째 suffix
ord[i] = [i..] suffix의 suffix array에서의 위치 (모든 정렬이 끝난 후에만, 아직 정렬중일 때는 이 값이 중복되게 존재할 수 있어 위치를 표시하지는 못하고, 관계를 표시할 수는 있음.)

ord[i], ord[i+t]는 [i..] suffix에 대해 일종의 가중치가 될 수 있다 --> 이것의 비교를 통해 정렬을 하는 것임.

모든 정렬이 끝난 후에는 임의의 i에 대해 ord[sfx[i]] = i가 성립한다.
즉, 그룹의 개수가 총 n개가 되고, 각 그룹에 속하는 sfx가 정확히 1개씩일 때 = ord - sfx가 일대일 매칭이 될 때

[ O(nlogn) 아이디어 ]
비교의 수를 줄여 총 logn번의 정렬을 하는데, 이 때 정렬의 시간을 O(n)으로 줄이면 총 O(nlogn)만에 Suffix Array를 구할 수 있다.
O(n)정렬 시간을 갖는 정렬은 counting sort가 있다.
--> 각 suffix는 최대 max(257, n)개의 서로다른 위치를 가지기 때문 ( = 순서에 대한 가중치)

문제는 i, i+t에 i를 우선으로 보고 같으면 i+t를 봐서 sort를 해야한다는 것인데, 이것은 radix sort와 같다.

따라서 우선 i+t를 보고 정렬을 해놓은 뒤,
i를 보고 정렬을 하면된다. (이 때 이전 정렬 결과에 대해 순서가 바뀌지 않도록 stable sort를 해야 함.)

i+t를 보고 정렬할 때는 i의 순서와 상관없기 때문에 간단하게 모든 i에 대해 현재


<< LCP >>
LCP 특성
1. sa 상에서 인접한 두 접미사의 lcp가 떨어진 두 접미사의 lcp보다 항상 크거나 같다.
2. lcp(sa[i-1], sa[i]) = h, h >= 1 이면
   lcp(sa[i-1]+1, sa[i]+1) = h-1 이다.

LCP 특성 2에 1을 가미하면 sa 상에서 인접한 lcp에 대한 값인 lcp 배열을 O(n)에 구할 수 있다.
lcp(sa[i-1], sa[i]) = h, h >= 1 이면
lcp(sa[i-1]+1, sa[i]+1) = h-1 인데, 이 때 sa[i-1]+1, sa[i]+1이 sa 상에서 인접하지 않을 수 있기 때문에
lcp[sa[i]+1] >= h-1 이다. (특성 1에 의해)

위 특성을 이용해 가장 긴 suffix부터 만들어가면 O(n)만에 lcp 배열을 구할 수 있다.

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

const int MAXN = 2e5;
int n;
string str;
vi sa, lcp, ord;
void input() {
	cin >> n >> str;
}

void getsa() {
	sa = ord = vi(n+1);
	FOR(i, 0, n) sa[i] = i, ord[i] = str[i]; ord[n] = 0;
	for(int t = 1; t <= n; t *= 2) {
		int sz = max(257, n+1);
		vi cnt, tmp;
		cnt = tmp = vi(sz, 0);
		FOR(i, 0, n) ++cnt[ord[min(n, i+t)]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		FOR(i, 0, n) tmp[--cnt[ord[min(n, i+t)]]] = i;
		cnt = vi(sz, 0);
		FOR(i, 0, n) ++cnt[ord[i]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		RFOR(i, n-1, 0) sa[--cnt[ord[tmp[i]]]] = tmp[i];
		tmp[sa[0]] = 1;
		FOR(i, 1, n) {
			int u = sa[i-1], v = sa[i];
			tmp[v] = tmp[u] + (ord[u] < ord[v] || ord[u+t] < ord[v+t]);
		}
		ord = tmp;
		if(ord[sa[n-1]] == n) break;
	}
	FOR(i, 0, n) --ord[i];
}

void getlcp() {
	lcp = vi(n, 0);
	for(int i = 0, len = 0; i < n; ++i, len = max(0, len-1)) {
		if(ord[i]) {
			for(int j = sa[ord[i]-1]; str[i+len] == str[j+len]; ++len);
			lcp[i] = len;
		}
	}
}

int solve() {
	getsa();
	getlcp();
	int ans = 0;
	FOR(i, 0, n) ans = max(ans, lcp[ord[i]]);
	cout << ans << ENDL;
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