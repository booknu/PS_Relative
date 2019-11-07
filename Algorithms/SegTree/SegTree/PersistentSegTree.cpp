/************
< �ּ� >      : http://codeforces.com/contest/813/problem/E
*************
< �ذ��� >   :
�迭�� index���� type�� �ְ�, ���� type�� �ִ� k�� �ۿ� ���� ���� ��
[s..e] �������� �� �� �ִ� �ִ� ���� �� ���ϱ�.

�� type�� [s..e] �������� �ִ� �� ������ ���� �� �� �ִ��� �˾ƺ���.

p(idx, 1) = ar[idx]�� ���� Ÿ���� �� �� idx �ٷ� ���� idx
p(idx, x) = p(p(idx, 1), x-1) ���� ��������� idx���� x��ŭ ���� idx�� ���� �� �ִ�.

�̰��� �����ϸ�, p(idx, k) < s && idx <= e �̸�, ���� idx�� [s..e] �������� ���� k�� �̸����� ���õ� ���̴�, ������ �� �ִٴ� ���� �� �� �ִ�.

����, b[idx] = p(idx, k)�� �̸� ������ְ�,
b�� ���� segment tree�� ����� [s..e] �������� �� idx�� �� ���̳� ���õǴ����� ���� �� �ִ�.

�� ��, seg leaf�� ���� b[idx] < s���� ���θ� �����ϰ� ������ node�� ���� b[ns..ne] < s�� ������ �����ϰ� �ִ�..

�׷���, s�� ���������� ���� �� �ְ�, s�� �۾����� ���� �� ���� �þ��.

���� �� s�� ���� ���� ������ segment tree�� �����ϰ� ������, [s..e] ������ ó���� �� �ִ�.
�� �� �� segment tree�� s�� ū ������ ���� ���ŵǾ�� �Ѵ�. (s�� ������ s�� ū ���� �����ϴϱ�.)

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

const int MAXN = 1e5, LOGN = 18, INF = MAXN + 10;
struct node {
	int x;
	node *l, *r;
	node(int _x = 0, node* l = 0, node* r = 0) : x(_x), l(l), r(r) {  }
	node* addtree(int u, int c, int ns = 0, int ne = MAXN-1) {
		if(ns <= u && u <= ne) {
			if(ns == ne) return new node(x + c, 0, 0);
			int mid = (ns+ne)/2;
			return new node(x + c, l->addtree(u, c, ns, mid), r->addtree(u, c, mid+1, ne));
		}
		return this;
	}
	int query(int s, int e, int ns = 0, int ne = MAXN-1) {
		if(s <= ns && ne <= e) return x;
		if(ne < s || e < ns) return 0;
		int mid = (ns+ne)/2;
		return l->query(s, e, ns, mid) + r->query(s, e, mid+1, ne);
	}
} *root[MAXN+1];

int n, k, q, ar[MAXN], par[MAXN][LOGN], posx[MAXN], b[MAXN], vals[MAXN];
void input() {
	cin >> n >> k;
	FOR(i, 0, n) cin >> ar[i], --ar[i];
}

int solve() {
	fill(posx, posx + MAXN, INF);
	FOR(i, 0, n) {
		par[i][0] = posx[ar[i]];
		posx[ar[i]] = i;
	}
	FOR(j, 1, LOGN) {
		FOR(i, 0, n) {
			par[i][j] = (par[i][j-1] != INF ? par[par[i][j-1]][j-1] : INF);
		}
	}
	FOR(i, 0, n) {
		int d = k;
		b[i] = i;
		FOR(j, 0, LOGN) {
			if(d & (1 << j) && b[i] != INF) b[i] = par[b[i]][j];
		}
	}
	root[n] = new node();
	root[n]->l = root[n]->r = root[n];
	memset(vals, -1, sizeof(vals));
	FOR(i, 0, n) {
		if(b[i] != INF) vals[b[i]] = i; // ��� i�� ���� b[i]�� ���� �����ϴ�. (p(i, k)�� �����ϴϱ�)
	}
	RFOR(i, n-1, 0) {
		if(vals[i] != -1) root[i] = root[i+1]->addtree(vals[i], 1);
		else root[i] = root[i+1];
	}
	cin >> q;
	int pr = 0;
	while(q--) {
		int x, y; cin >> x >> y;
		int s = ((x + pr) % n), e = ((y + pr) % n);
		if(s > e) swap(s, e);
		int ans = e - s + 1 - root[s]->query(s, e);
		cout << ans << ENDL;
		pr = ans;
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