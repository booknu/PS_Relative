/************
< 주소 >      :
*************
< 해결방안 >   :
포함-배제 원리를 사용하면 다차원 psum도 구현 할 수 있다!

이 때 코드와 데이터를 분리하는 방법을 사용하면 많이 느려지니까 주의하기.

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
inline i64 GCD(i64 a, i64 b) { i64 n; if (a < b) swap(a, b); while (b != 0) { n = a % b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if (a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d) * 2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if (n < 0) return 0;
	i64 ret = 1;
	while (n) { if (n % 2) ret *= a; a = a * a; n /= 2; }
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

const int RANGE = 256;
int n, k, ps[RANGE][RANGE][RANGE], ar[RANGE][RANGE][RANGE];

int f(int x, int y, int z) {
	return (x < 0 || y < 0 || z < 0 || x >= RANGE || y >= RANGE || z >= RANGE ? 0 : ps[x][y][z]);
}

int sum(int x1, int y1, int z1, int l) {
	int x2 = min(RANGE - 1, x1 + l), y2 = min(RANGE - 1, y1 + l), z2 = min(RANGE - 1, z1 + l);
	--x1, --y1, --z1;
	return
		f(x2, y2, z2)
		- f(x1, y2, z2) - f(x2, y1, z2) - f(x2, y2, z1)
		+ f(x1, y1, z2) + f(x1, y2, z1) + f(x2, y1, z1)
		- f(x1, y1, z1);
}

void init() {
	FOR(x, 0, RANGE) {
		FOR(y, 0, RANGE) {
			FOR(z, 0, RANGE) {
				ps[x][y][z] +=
					f(x - 1, y, z) + f(x, y - 1, z) + f(x, y, z - 1)
					- f(x - 1, y - 1, z) - f(x - 1, y, z - 1) - f(x, y - 1, z - 1)
					+ f(x - 1, y - 1, z - 1);
			}
		}
	}
}