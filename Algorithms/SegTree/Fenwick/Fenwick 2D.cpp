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

struct fenwick2d {
	int n, m;
	vector<vector<i64> > t;
	void init(int _n, int _m) {
		n = _n, m = _m;
		t = vector<vector<i64> >(n+1, vector<i64>(m+1, 0));
	}
	// O(log(n)*log(m))
	void add(int y, int x, i64 c) {
		for(int i = y+1; i <= n; i += (i&-i)) {
			for(int j = x+1; j <= m; j += (j&-j)) {
				t[i][j] += c;
			}
		}
	}
	i64 get(int y, int x) { return sum(y, x, y, x); }
	i64 sum(int y, int x) {
		i64 ret = 0;
		for(int i = y+1; i > 0; i -= (i&-i)) {
			for(int j = x+1; j > 0; j -= (j&-j)) {
				ret += t[i][j];
			}
		}
		return ret;
	}
	i64 sum(int sy, int sx, int ey, int ex) {
		return sum(ey, ex) - sum(sy-1, ex) - sum(ey, sx-1) + sum(sy-1, sx-1);
	}
};