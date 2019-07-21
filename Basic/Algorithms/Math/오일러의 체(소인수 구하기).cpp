/************
< 주소 >      : https://cp-algorithms.com/algebra/prime-sieve-linear.html
*************
< 해결방안 >   :
1. 에라토스테네스의 체를 O(n)에 구할 수 있게 한다.
2. 범위 내의 수들에 대해 spf[x] = x의 가장 작은 소인수를 저장하여 소인수분해를 O(logn)에 할 수 있게 해준다.


일반적인 방법으로 소인수분해를 하려면, sqrt(x)이하의 모든 소수에 대해 나누는 것을 시도한 후, 남는 x도 소인수에 포함하는 방식을 취하는데,
오일러의 체는 애초에 대상이 되지 않는 소수는 시도도 하지 않아 효율적이다.

오일러의 체를 구하는 방법은 에라토스테네스의 체를 구하는 방법과 비슷하다.
x = [2..RANGE]까지 돌며 안쪽 루프에서 그것의 배수를 체크하는 방식인데,

에라토스테네스의 체 같은 경우는 같은 수를 여러번 방문하며 isprime을 체크하기 때문에 시간복잡도가 O(nloglogn)이다.


하지만, 오일러의 체는 같은 수를 유일하게 방문한다.

그 방법은 현재 x의 prime 배수 중, pr <= spf[x]인 pr들만 방문하는 것이다.
이 덕분에 당연히 spf[x*pr] = pr이고, 모든 수를 1번씩만 방문할 수 있다.

모든 수를 딱 1번씩 방문한다는 증명은,
자연수 i > 1에 대하여
i = spf[i] * x로 표현 가능하기 때문.
(이 때, spf[x] <= spf[i] 이기 때문에, 위와 같은 표현식은 i당 단 1개밖에 존재할 수 없다.)

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
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // 음수일 때 이상하게 작동할 수 있음.
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
	return os << "(" << p.fi << "," << p.se << ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ....................................................... //

// --> x*pr[j]에서 overflow 발생할 수 있음! 그러나 적당히 작은 RANGE에서는 소수 분포가 촘촘하기 때문에 발생하지 않음.
// --> RANGE 내의 소수 개수 = RANGE/ln(RANGE) --> 2e7에서 인접 소수 최대 차이 = 180, 4e6 = 140
const int RANGE = 2e7;
int pn, spf[RANGE], pr[RANGE]; // pr은 vi로 구현해도 됨. --> but 실행 시간 많이 늘어남.
void eulerSieve() {
	FOR(x, 2, RANGE) {
		if(!spf[x]) spf[x] = pr[pn++] = x; // x 자체가 소수이면 spf[x] = x이다.
		for(int j = 0; x*pr[j] < RANGE; ++j) { // x의 소수배들에 spf[x*pr] = pr로 칠해준다. (단, pr <= spf[x])
			spf[x*pr[j]] = pr[j];
			if(x % pr[j] == 0) break; // 좀 더 직관적으로 if(spf[x] == pr[j])로 구현해도 되지만, 똑같은 효과를 가진 코드이다.
		}
	}
}

// 좀 더 직관적으로 구현하면 다음과 같다.
// but, 위의 고정 배열을 이용한 방법은 2e7 범위에서 180ms, 이 방법은 3500ms --> 동적 배열의 한계인듯 --> 근데 실제로 제출해보면 똑같음
int spf[RANGE];
vi pr;
void eulerSieve() {
	FOR(x, 2, RANGE) {
		if(!spf[x]) spf[x] = x, pr.pb(x);
		for(int y : pr) {
			if(spf[x] < y || RANGE <= x*y) break;
			spf[x*y] = y;
		}
	}
}


vi getPrimeFactor(int x) {
	vi ret;
	while(x > 1) {
		int p = spf[x];
		ret.pb(p);
		while(x % p == 0) x /= p;
	}
	return ret;
}