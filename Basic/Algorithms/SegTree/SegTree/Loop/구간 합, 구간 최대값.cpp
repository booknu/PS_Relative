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
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //

struct segtree {
	int n, h;
	vi t, d;
	void init(int _n) {
		n = _n;
		t = vi(2*n, 0), d = vi(n, 0);
		h = sizeof(n)*8 - __builtin_clz(n);
	}
	void apply(int u, int x) {
		if(u < n) d[u] += x;
		t[u] += x; // 여기서도 t[u]를 갱신해줘야 함.
	}
	void build(int u) {
		while(u > 1) u /= 2, t[u] = max(t[u*2], t[u*2+1]) + d[u];
	}
	void push(int p) {
		for(int s = h; s > 0; --s) {
			int i = p >> s;
			if(d[i] != 0) {
				apply(i*2, d[i]);
				apply(i*2+1, d[i]);
				d[i] = 0;
			}
		}
	}
	void inc(int s, int e, int x) {
		s += n, e += n;
		int s0 = s, e0 = e;
		for(; s < e; s /= 2, e /= 2) {
			if(s%2) apply(s++, x);
			if(e%2) apply(--e, x);
		}
		build(s0);
		build(e0-1);
	}
	int query(int s, int e) {
		s += n, e += n;
		push(s);
		push(e - 1);
		int ret = -2e9;
		for(; s < e; s /= 2, e /= 2) {
			if(s%2) ret = max(ret, t[s++]);
			if(e%2) ret = max(t[--e], ret);
		}
		return ret;
	}
};