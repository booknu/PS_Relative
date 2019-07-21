/************
< 주소 >      :
*************
< 해결방안 >   :


*************
< 오답노트 >   :

*************/

#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <bitset>
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
inline i64 GCD(i64 a, i64 b) { while (b != 0) { int t = a; a = b; b = t % b; } return a; }
inline i64 LCM(i64 a, i64 b) { if (a == 0 || b == 0) return GCD(a, b); return a * b / GCD(a, b); }
inline i64 CEIL(i64 n, i64 d) { return n / d + n % d != 0; }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d) * 2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if (n < 0) return 0;
	i64 ret = 1;
	while (n) { if (n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //


void input() {

}

int solve() {

	return 0;
}

// ................. main .................. //
void execute() {
	int TTTT; cin >> TTTT;
	FOR(tttt, 0, TTTT) {
		cout << "Case #" << tttt + 1 << ENDL;
		input(), solve();
	}
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	cin.tie(0); ios_base::sync_with_stdio(false);
	execute();
	return 0;
}
// ......................................... //