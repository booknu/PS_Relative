// https://codeforces.com/blog/entry/18051
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

struct segtree {
	int n, h;
	i64 init_val;
	vector<i64> t, d;
	segtree(i64 init_val) : init_val(init_val) { }
	void init(const vi& ar) {
		n = ar.size();
		h = 8*sizeof(n) - __builtin_clz(n);
		t.assign(2*n, 0), d.assign(n, 0);
		FOR(i, 0, n) t[n+i] = ar[i];
		RFOR(i, n-1, 0) t[i] = t[i<<1] + t[i<<1|1];
	}
	void calc(int u, int k) { // = recalc node with d[u]
		t[u] = t[u<<1] + t[u<<1|1] + k*d[u];
	}
	void apply(int u, i64 x, int k) { // = propagate single node
		t[u] += k*x;
		if(u < n) d[u] += x;
	}
	void build(int s, int e) { // = recalc [s..e]'s parent
		s += n, e += n-1;
		for(int k = 2; s > 1; k <<= 1) {
			s >>= 1, e >>= 1;
			for(int i = e; i >= s; --i) calc(i, k);
		}
	}
	void push(int s, int e) { // = propagate all [s..e]'s parents
		s += n, e += n-1;
		for(int c = h, k = 1 << (h-1); c > 0; --c, k >>= 1) {
			for(int i = s >> c; i <= e >> c; ++i) {
				if(d[i] != 0) {
					apply(i<<1, d[i], k);
					apply(i<<1|1, d[i], k);
					d[i] = 0;
				}
			}
		}
	}
	void add(int s, int e, i64 x) {
		int s0 = s, e0 = e, k = 1;
		for(s += n, e += n; s < e; s >>= 1, e >>= 1, k <<= 1) {
			if(s&1) apply(s++, x, k);
			if(e&1) apply(--e, x, k);
		}
		build(s0, s0+1);
		build(e0-1, e0);
	}
	i64 query(int s, int e) {
		push(s, s+1);
		push(e-1, e);
		i64 ret = init_val;
		for(s += n, e += n; s < e; s >>= 1, e >>= 1) {
			if(s&1) ret += t[s++];
			if(e&1) ret += t[--e];
		}
		return ret;
	}
};