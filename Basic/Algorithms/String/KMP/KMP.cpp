/************
< �ּ� >      : https://www.acmicpc.net/problem/6042
*************
< �ذ��� >   :
1. O(n^3) �ذ��
   ��� ������ ������ �� [sa, sb]���� ������ ���� �� ���� ���̸� �����ϸ� ��.

2. O(n^2) �ذ��
   dp[i][j] = dp[i-1][j-1]: i, j�ֿ��� ������ ���� �� ����

3. O(n^2) �ذ��2
   KMP ����

*************
< �����Ʈ >   :

KMP�� O(n)�� �� �� ���� �� �˾���
--> KMP�� ã��(�ٴ�) ���ڿ��� ó���������͸� ��ġ�ϴ� ������ ã�� �� ���� (��, �ٴ� ���ڿ��� ���λ�� ¤ ���ڿ��� ��ġ ���踸�� Ȯ�� ����)
	���� KMP�� ����Ϸ��� ������ �ٴ� ���ڿ��� [0..], [1..] [2..] ... ���θ� �õ��غ��� ��.

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

const int MAXN = 180;
int n, m;
vi a, b;
void input() {
	cin >> n >> m;
	a = vi(n), b = vi(m);
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, m) cin >> b[i];
}

vi getpi(const vi& b) {
	int cnt = 0;
	vi pi(b.size());
	FOR(i, 1, b.size()) {
		while(cnt && b[i] != b[cnt]) cnt = pi[cnt-1];
		if(b[i] == b[cnt]) {
			pi[i] = ++cnt;
		}
	}
	return pi;
}

int lcs(const vi& a, const vi& b) {
	vi pi = getpi(b);
	int ret = -1, cnt = 0;
	FOR(i, 0, a.size()) {
		while(cnt && a[i] != b[cnt]) cnt = pi[cnt-1];
		if(a[i] == b[cnt]) {
			if(cnt == m-1 || cnt == n-1) {
				ret = cnt+1;
				cnt = pi[cnt];
				break;
			} else {
				ret = max(ret, ++cnt);
			}
		}
	}
	return ret;
}

int solve() {
	int ret = 0;
	FOR(i, 0, n) {
		ret = max(ret, lcs(a, vi(b.begin() + i, b.end())));
	}
	cout << ret << ENDL;
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