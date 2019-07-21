/************
< �ּ� >      : http://codeforces.com/contest/959/problem/F
*************
< �ذ��� >   :
�켱, ������ �ش� �������� xor sum�� ����� k�� ���� ���� ���� �ƴ�, k�ΰ� �����ϴ��� ���θ� �˾Ƴ��� ������ ��������.

�̰��� ���� i�� ���� ��� ������ xor ����� �����ϸ� x^a[i]�� set�� �߰��س����� ���� ���� �� �ִ�.
(���� set�� 0�� �����ϰ� �־�� ��.)

������, �̰��� O(nA) || O(nAlogA) �ð��� �ɸ��Ƿ� �Ұ����ϴ�.

���⼭ �� ���� ������ ����.
1. x, y�� set�� �����Ѵٸ�, x^y�� set�� �����Ѵ�.
   �̰��� xor Ư���� �����ϸ� ���� �� �� �ִ�.
   x -----
		----- y
	 ---  --- x^y
   �̷� ������ x, y�� ���� ���� a�� i���� ���ҵ� �� �Ϻθ� xor�� ����� ���̰�, �װ��� ai�� ���� x�� ���Եƴ���, �� �ƴ����� ǥ���� �� �ִ�.
   x, y�� �ٿ� ���Ե� ���Ҵ� x^y���� �ɷ��� ���̰�, �ᱹ ���� �͵� a�� �Ϻ� xor ������ٵ�, �̰͵� �翬�� set�� ���� ���̴�.
2. x�� set�� �����ϰ�, y�� set�� �������� �ʴ´ٸ�, x^y�� set�� �������� ���� ���̴�.
   �ͷ������� ���� �����ϴ�.
   x^y�� set�� �����Ѵٰ� �����ϸ�, (x^y)^x�� set�� ������ ���̴�. (1���� ���������� ������)
   (x^y)^x = y�ε�, y�� set�� �������� �ʴ´ٰ� ������ ����̴�.
   ���� x^y�� set�� �������� �ʴ´�.


���� dp ���� ¥����. (���� ���ΰ� �ƴ�, ����� ���� ����.)
dp[i][x] = dp[i-1][x] + dp[i-1][x^a[i]]
�� ��, ��� a[i]�� ����� ���� dp�� ���� �� �ʿ䰡 ����.
1. a[i]�� set�� ���� �� ���: ���� dp[i][x]�� �����ϴ� ��� x�� dp[i-1][x]*2�� �����Ѵ�.
2. a[i]�� set�� �������� ���� ���: set�� a[i]^setx �� �ִ´�. (����� ���� �ٲ��� �ʴ´�.)

���� ���� ������ �� ��, dp�� �����ϸ� ���� ������ �ȴ�.
= O((n + A)log(A))

*************
< �����Ʈ >   :
[ �߰� ���� ]
A = 2^30, online���� ó���ؾ� �Ѵٴ� ������ ������ ���� ������ ���� �ذ��ؾ� �Ѵ�. --> Editorial ����!

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
inline int getidx(const vi& ar, int x) { lower_bound(ALL(ar), x) - ar.begin(); } // ��ǥ ���࿡ ���: ���ĵ� ar���� x�� idx�� ã��
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

const int MAXN = 1e5, RANGE = (1 << 20) + 1;
const i64 MOD = 1e9 + 7;
int n, q, ar[MAXN], l[MAXN], x[MAXN], ord[MAXN], res[MAXN];
set<int> s;
void input() {
	cin >> n >> q;
	FOR(i, 0, n) cin >> ar[i];
	FOR(i, 0, q) cin >> l[i] >> x[i], --l[i];
}

int solve() {
	FOR(i, 0, q) ord[i] = i;
	sort(ord, ord + q, [](int u, int v) { return l[u] < l[v]; });
	int p = 0;
	i64 cnt = 1;
	s.insert(0);
	FOR(i, 0, n) {
		if(s.count(ar[i])) (cnt *= 2) %= MOD;
		else {
			for(auto& u : s) s.insert(u^ar[i]);
		}
		while(p < q && l[ord[p]] == i) {
			debug(l[ord[p]]);
			res[ord[p]] = (s.count(x[ord[p]]) ? cnt : 0);
			++p;
		}
	}
	FOR(i, 0, q) cout << res[i] << ENDL;
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