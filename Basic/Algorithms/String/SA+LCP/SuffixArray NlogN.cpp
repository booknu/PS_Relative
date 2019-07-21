/************
< �ּ� >      :
*************
< �ذ��� >   :
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

const int MAXN = 1e3+10;
int n;
string s;
vi ord, sfx, cnt, tmp;
void input() {
	cin >> s; n = s.size();
}

int solve() {
	ord = sfx = vi(n+1);
	FOR(i, 0, n) sfx[i] = i, ord[i] = s[i]; ord[n] = 0;
	for(int t = 1; t <= n; t *= 2) {
		// radix sort = 2�� counting sort
		int sz = max(257, n+1); // ord �ʱ�ȭ �� s[i]�� �״�� �־��� ������ 257�� max���� ������� ��.
		// (i+t)�� ���� counting sort
		cnt = vi(sz, 0); tmp = vi(n);
		FOR(i, 0, n) ++cnt[ord[min(i+t, n)]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		FOR(i, 0, n) tmp[--cnt[ord[min(i+t, n)]]] = i;
		// (i)�� ���� counting sort (�� ��, i+t ����� �����ϱ� ���� stable sort�� �ؾ���!)
		cnt = vi(sz, 0);
		FOR(i, 0, n) ++cnt[ord[i]];
		FOR(i, 1, sz) cnt[i] += cnt[i-1];
		RFOR(i, n-1, 0) sfx[--cnt[ord[tmp[i]]]] = tmp[i]; // ���⼭�� ù��° ���� ����� �����ϱ� ���� stable sort�� �ؾ���!
		// sort ��� �̿��ؼ� ��׷���
		tmp = vi(n);
		auto cmp = [&](int i, int j) {
			if(ord[i] == ord[j]) return ord[i+t] < ord[j+t];
			else return ord[i] < ord[j];
		};
		FOR(i, 1, n) tmp[sfx[i]] = tmp[sfx[i-1]] + cmp(sfx[i-1], sfx[i]);
		ord = tmp;
	}
	FOR(i, 0, n) {
		cout << s.substr(sfx[i], n) << ENDL;
	}
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