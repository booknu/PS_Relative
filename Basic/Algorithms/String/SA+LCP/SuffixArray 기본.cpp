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
inline i64 GCD(i64 a, i64 b) { i64 n; if(a<b) swap(a, b); while(b!=0) { n = a%b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
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

const int MAXN = 1e3+10;
int n, pos[MAXN], sa[MAXN], tmp[MAXN]; // pos[i] = 현재 s[i..]이 어느 그룹에 속하는지?, sa[i] = suffix의 시작점들을 정렬된 순서로 저장, tmp = pos 갱신을 위한 임시 변수
string s;
void input() {
	cin >> s; n = s.size();
}

struct comp {
	int d;
	comp(int d) : d(d) {  }
	bool operator()(int u, int v) {
		if(pos[u] < pos[v]) return true;
		else if(pos[u] == pos[v] && pos[u+d] < pos[v+d]) return true;
		return false;
	}
};

void getSA() {
	FOR(i, 0, n) pos[i] = s[i], sa[i] = i; pos[n] = 0, sa[n] = n;
	for(int gap = 1; gap < n; gap *= 2) {
		comp cp(gap);
		sort(sa, sa+n+1, cp); // 일단 2*d로 정렬해주고
		tmp[sa[0]] = 0;
		for(int i = 1; i <= n; ++i) tmp[sa[i]] = tmp[sa[i-1]] + cp(sa[i-1], sa[i]); // 그룹들을 정렬된 결과로 재그룹핑
		for(int i = 0; i <= n; ++i) pos[sa[i]] = tmp[sa[i]];
	}
}

int solve() {
	getSA();
	FOR(i, 1, n+1) cout << s.substr(sa[i], n) << ENDL;
	return 0;
}

// ................. main .................. //
void execute() {
	input(), solve();
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	cin.tie(0); ios_base::sync_with_stdio(false);
	execute();
	return 0;
}
// ......................................... //