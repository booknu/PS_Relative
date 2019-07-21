/*
	일반 fenwick 2개를 사용하여 range add, range query를 사용할 수 있음. (Lazy Propagation 필요 x)
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
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;
inline i64 GCD(i64 a, i64 b) { while(b != 0) { int t = a; a = b; b = t % b; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a*b / GCD(a, b); }
inline i64 CEIL(i64 n, i64 d) { return n / d + n % d != 0; }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //

// 기본적인 fenwick
struct fenwick {
	int n;
	vector<i64> t;
	void init(int _n) { n = _n; t = vector<i64>(n+1, 0); }
	void add(int u, i64 x) { for(++u; u < t.size(); u += (u&-u)) t[u] += x; }
	i64 sum(int u) { i64 ret = 0; for(++u; u > 0; u -= (u&-u)) ret += t[u]; return ret; }
};
// 
struct rfenwick {
	fenwick ax, b;
	void init(int n) { ax.init(n), b.init(n); }
	void add(int u, i64 x) { b.add(u, x); }
	void add(int s, int e, i64 x) {
		ax.add(s, x);
		ax.add(e+1, -x);
		b.add(s, -x * (s-1));
		b.add(e+1, x * e);
	}
	i64 sum(int u) {
		return u * ax.sum(u) + b.sum(u);
	}
};