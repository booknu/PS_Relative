/************
< �ּ� >      : https://www.acmicpc.net/problem/9248
*************
< �ذ��� >   :
<< Suffix Array >>
sfx[i] = i��° suffix
ord[i] = [i..] suffix�� suffix array������ ��ġ (��� ������ ���� �Ŀ���, ���� �������� ���� �� ���� �ߺ��ǰ� ������ �� �־� ��ġ�� ǥ�������� ���ϰ�, ���踦 ǥ���� ���� ����.)

ord[i], ord[i+t]�� [i..] suffix�� ���� ������ ����ġ�� �� �� �ִ� --> �̰��� �񱳸� ���� ������ �ϴ� ����.

��� ������ ���� �Ŀ��� ������ i�� ���� ord[sfx[i]] = i�� �����Ѵ�.
��, �׷��� ������ �� n���� �ǰ�, �� �׷쿡 ���ϴ� sfx�� ��Ȯ�� 1������ �� = ord - sfx�� �ϴ��� ��Ī�� �� ��

[ O(nlogn) ���̵�� ]
���� ���� �ٿ� �� logn���� ������ �ϴµ�, �� �� ������ �ð��� O(n)���� ���̸� �� O(nlogn)���� Suffix Array�� ���� �� �ִ�.
O(n)���� �ð��� ���� ������ counting sort�� �ִ�.
--> �� suffix�� �ִ� max(257, n)���� ���δٸ� ��ġ�� ������ ���� ( = ������ ���� ����ġ)

������ i, i+t�� i�� �켱���� ���� ������ i+t�� ���� sort�� �ؾ��Ѵٴ� ���ε�, �̰��� radix sort�� ����.

���� �켱 i+t�� ���� ������ �س��� ��,
i�� ���� ������ �ϸ�ȴ�. (�� �� ���� ���� ����� ���� ������ �ٲ��� �ʵ��� stable sort�� �ؾ� ��.)

i+t�� ���� ������ ���� i�� ������ ������� ������ �����ϰ� ��� i�� ���� ����


<< LCP >>
LCP Ư��
1. sa �󿡼� ������ �� ���̻��� lcp�� ������ �� ���̻��� lcp���� �׻� ũ�ų� ����.
2. lcp(sa[i-1], sa[i]) = h, h >= 1 �̸�
   lcp(sa[i-1]+1, sa[i]+1) = h-1 �̴�.

LCP Ư�� 2�� 1�� �����ϸ� sa �󿡼� ������ lcp�� ���� ���� lcp �迭�� O(n)�� ���� �� �ִ�.
lcp(sa[i-1], sa[i]) = h, h >= 1 �̸�
lcp(sa[i-1]+1, sa[i]+1) = h-1 �ε�, �� �� sa[i-1]+1, sa[i]+1�� sa �󿡼� �������� ���� �� �ֱ� ������
lcp[sa[i]+1] >= h-1 �̴�. (Ư�� 1�� ����)

�� Ư���� �̿��� ���� �� suffix���� ������ O(n)���� lcp �迭�� ���� �� �ִ�.

*************
< �����Ʈ >   :

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
inline int getidx(const vi& ar, int x) { return lower_bound(ALL(ar), x) - ar.begin(); } // ��ǥ ���࿡ ���: ���ĵ� ar���� x�� idx�� ã��
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

const int MAXN = 2e5;
int n;
string str;
vi sa, lcp, ord;
void input() {
	cin >> n >> str;
}

void getsa() {
	sa = ord = vi(n+1);
	FOR(i, 0, n) sa[i] = i, ord[i] = str[i]; ord[n] = 0;
	for(int t = 1; t <= n; t *= 2) {
		int sz = max(257, n+1);
		vi cnt, tmp;
		cnt = tmp = vi(sz, 0);
		FOR(i, 0, n) ++cnt[ord[min(n, i+t)]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		FOR(i, 0, n) tmp[--cnt[ord[min(n, i+t)]]] = i;
		cnt = vi(sz, 0);
		FOR(i, 0, n) ++cnt[ord[i]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		RFOR(i, n-1, 0) sa[--cnt[ord[tmp[i]]]] = tmp[i];
		tmp[sa[0]] = 1;
		FOR(i, 1, n) {
			int u = sa[i-1], v = sa[i];
			tmp[v] = tmp[u] + (ord[u] < ord[v] || ord[u+t] < ord[v+t]);
		}
		ord = tmp;
		if(ord[sa[n-1]] == n) break;
	}
	FOR(i, 0, n) --ord[i];
}

void getlcp() {
	lcp = vi(n, 0);
	for(int i = 0, len = 0; i < n; ++i, len = max(0, len-1)) {
		if(ord[i]) {
			for(int j = sa[ord[i]-1]; str[i+len] == str[j+len]; ++len);
			lcp[i] = len;
		}
	}
}

int solve() {
	getsa();
	getlcp();
	int ans = 0;
	FOR(i, 0, n) ans = max(ans, lcp[ord[i]]);
	cout << ans << ENDL;
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