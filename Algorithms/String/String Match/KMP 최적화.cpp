/************
< 주소 >      :
*************
< 해결방안 >   :
std::boyer_moore_horspool_searcher 로도 가능

n - pi[n-1] = 문자열에서 반복되는 부분 문자열의 최소 길이 (이 때, 마지막에는 부분 문자열의 뒷 부분이 짤릴 수도 있음!)
--> https://www.acmicpc.net/problem/4354, https://www.acmicpc.net/problem/1305
--> 직접 경우에 따라서 그려보면 이해 가능

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
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
	os << "[";
	int cnt = 0;
	for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
	return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
	return os << "(" << p.fi << "," << p.se << ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ....................................................... //

string s, t;
void input() {
	getline(cin, s);
	getline(cin, t);
}

vi getpi(const string& str) {
	int n = str.size(), len = 0;
	vi pi(n, 0);
	FOR(i, 1, n) {
		while(len && str[len] != str[i]) len = pi[len-1];
		if(str[len] == str[i]) pi[i] = ++len;
	}
	return pi;
}

vi kmp() {
	int n = s.size(), m = t.size(), len = 0;
	vi ret, pi = getpi(t);
	FOR(i, 0, n) {
		while(len && s[i] != t[len]) len = pi[len-1];
		if(s[i] == t[len] && ++len == m) ret.pb(i-len+1), len = pi[len-1];
	}
	return ret;
}

int solve() {
	vi ans = kmp();
	cout << ans.size() << ENDL;
	FOR(i, 0, ans.size()) cout << ans[i]+1 << ' '; cout << ENDL;
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