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

// y축 기준으로 segtree가 있고,
// 해당 y segtree의 node마다 x축 기준 segtree가 있다.
struct segtree {
	int n, m;
	vvi t;
	void init(const vvi& ar) {
		n = ar.size(), m = ar[0].size();
		t.assign(2*n, vi(2*m, 0));
		// 일단 leaf에 넣고
		FOR(y, 0, n) {
			FOR(x, 0, m) {
				t[n+y][m+x] = ar[y][x];
			}
		}
		// construct 하는데, y자식, x자식 각각을 이용.
		RFOR(y, 2*n-1, 1) {
			RFOR(x, 2*m-1, 1) {
				if(y < n) t[y][x] = t[y*2][x] + t[y*2+1][x];
				if(x < m) t[y][x] = t[y][x*2] + t[y][x*2+1];
			}
		}
	}
	void modify(int y, int x, int c) {
		// 일단 leaf 갱신
		t[y + n][x + m] = c;
		for(y += n; y > 0; y /= 2) {
			for(int x2 = x + m; x2 > 0; x2 /= 2) {
				// 갱신 후 해당 leaf의 부모들을 갱신
				if(y < n) t[y][x2] = t[y*2][x2] + t[y*2+1][x2];
				if(x2 < m) t[y][x2] = t[y][x2*2] + t[y][x2*2+1];
			}
		}
	}
	// O(logN*logM)
	int query(int sy, int sx, int ey, int ex) {
		int ret = 0;
		for(sy += n, ey += n; sy < ey; sy /= 2, ey /= 2) {
			for(int x1 = sx + m, x2 = ex + m; x1 < x2; x1 /= 2, x2 /= 2) {
				if(sy&1) {
					if(x1&1) ret += t[sy][x1];
					if(x2&1) ret += t[sy][x2-1];
				}
				if(ey&1) {
					if(x1&1) ret += t[ey-1][x1];
					if(x2&1) ret += t[ey-1][x2-1];
				}
				if(x1&1) ++x1;
				if(x2&1) --x2;
			}
			if(sy&1) ++sy;
			if(ey&1) --ey;
		}
		return ret;
	}
};