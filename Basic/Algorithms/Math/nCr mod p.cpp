/*
	http://koosaga.com/63
	--> 아직 검증 안 해봄

	목적: 일정 범위 내의 n에 대해 특수한 전처리를 통해 nCr % p 쿼리를 O(1)에 처리.
		 단, p는 소수

	1. c[n][r] = c[n-1][r-1] + c[n-1][r] 활용
	   Time = O(n^2), Space = O(n^2)

	2. nCr = n! / ((n-r)! * r!)에서, n!, n!^-1 전처리
	   Time = O(nlgp), Space = O(n)
	   n!^-1을 페르마 소정리를 통한 mod inverse로 구함.

	3. (n-1)!^-1 = n * n!^-1  점화식 활용: 2번 최적화
	   Time = O(n + lgp), Space = O(n)

	4. inv(1) = 1, inv(i) = -floor(p/i) + inv(p%i)   를 통해 inv(n)을 전처리 ★★★★ --> 굳이 nCr 말고 inv(n) 구할 때도 좋음
	   Time = O(n), Space = O(n)
		 pf) p = floor(p/i) * i + p % i    (p를 i로 나눴을 때 몫과 나머지를 생각해보면 됨.)
			 floor(p/i) * i == p%i (mod p)
			 floor(p/i) * (p%i)^-1 == i^-1 (mod p)
			   --> mod 안의 수를 나눌 수 있는 이유는, (p%i)^-1은 이미 구해진 수이고, i^-1은 구할 수이기 때문.

*/

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

// POW, INV
const i64 MOD = 1e9 + 7;
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a, ret %= MOD; a = a * a, a %= MOD; n /= 2; }
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

// 꼭 POW에도 MOD 사용해줄 것!!!!!!!!
const int RANGE = 1e6;
void secondPrecalc() {
	i64 ftr[RANGE], iftr[RANGE];
	ftr[0] = iftr[0] = 1;
	FOR(i, 1, RANGE) {
		ft[i] = (ft[i-1] * (i64)i) % MOD;
		ift[i] = (ift[i-1] * POW((i64)i, MOD-2)) % MOD;
	}
}

void thirdPrecalc() {
	i64 ftr[RANGE], iftr[RANGE];
	ftr[0] = iftr[0] = 1;
	FOR(i, 1, RANGE) ftr[i] = ftr[i-1] * i;
	iftr[RANGE-1] = POW(ftr[RANGE-1], MOD-2);
	RFOR(i, RANGE-2, 0) iftr[i] = (i * iftr[i+1]) % MOD;
}

void fourthPrecalc() {
	i64 inv[RANGE+1], ftr[RANGE], iftr[RANGE];
	inv[1] = 1;
	FOR(i, 2, RANGE+1) {
		inv[i] = inv[MOD % i] - (MOD / i);
		if(inv[i] < 0) inv[i] += MOD;
		inv[i] %= MOD;
	}
}