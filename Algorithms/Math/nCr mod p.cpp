/*
	http://koosaga.com/63
	--> ���� ���� �� �غ�

	����: ���� ���� ���� n�� ���� Ư���� ��ó���� ���� nCr % p ������ O(1)�� ó��.
		 ��, p�� �Ҽ�

	1. c[n][r] = c[n-1][r-1] + c[n-1][r] Ȱ��
	   Time = O(n^2), Space = O(n^2)

	2. nCr = n! / ((n-r)! * r!)����, n!, n!^-1 ��ó��
	   Time = O(nlgp), Space = O(n)
	   n!^-1�� �丣�� �������� ���� mod inverse�� ����.

	3. (n-1)!^-1 = n * n!^-1  ��ȭ�� Ȱ��: 2�� ����ȭ
	   Time = O(n + lgp), Space = O(n)

	4. inv(1) = 1, inv(i) = -floor(p/i) + inv(p%i)   �� ���� inv(n)�� ��ó�� �ڡڡڡ� --> ���� nCr ���� inv(n) ���� ���� ����
	   Time = O(n), Space = O(n)
		 pf) p = floor(p/i) * i + p % i    (p�� i�� ������ �� ��� �������� �����غ��� ��.)
			 floor(p/i) * i == p%i (mod p)
			 floor(p/i) * (p%i)^-1 == i^-1 (mod p)
			   --> mod ���� ���� ���� �� �ִ� ������, (p%i)^-1�� �̹� ������ ���̰�, i^-1�� ���� ���̱� ����.

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
inline int getidx(const vi& ar, int x) { lower_bound(ALL(ar), x) - ar.begin(); } // ��ǥ ���࿡ ���: ���ĵ� ar���� x�� idx�� ã��
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

// �� POW���� MOD ������� ��!!!!!!!!
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