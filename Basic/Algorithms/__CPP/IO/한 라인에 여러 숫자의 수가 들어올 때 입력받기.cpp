/************
< 주소 >      :
*************
< 해결방안 >   :

하나의 라인에 정해지지 않은 숫자만큼의 입력이 들어올 때 받는 법

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

int n, m;
vi ar;
void input() {
	scanf("%d", &n);
	ar.resize(n);
	FOR(i, 0, n) scanf("%d", &ar[i]);
	scanf("%d", &m);
}

int solve() {
	while(m--) {
		int s, e;
		char c;
		// 한 라인에 2개 || 3개의 입력이 들어옴
		scanf("%d%d%c", &s, &e, &c);
		cin >> s >> e >> c;
		if(c == '\n') {
			cout << s << ' ' << e << ENDL;
		} else {
			int x; scanf("%d", &x);
			cout << s << ' ' << e << ' ' << x << ENDL;
		}
	}
}

// ................. main .................. //
void execute() {
	input(), solve();
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin.tie(0); ios_base::sync_with_stdio(false);
	execute();
}
// ......................................... //