/************
< �ּ� >      : https://www.acmicpc.net/problem/9250
*************
< �ذ��� >   :
�迭�� ������ Aho-Corasick

[ ���� ]
- ���� c ������ �ִ��� ���� �� �� ���� (������ 0���� �ʱ�ȭ�� ���� �״�δϱ�)
- ������ ��ȣ�� �Ű����־� dp�� �����ϱ� ����.
- ���� c ������ ������ �̰Ϳ� ���� ó���� ���� �ʰ� �׳� t[u][c]�� ���� �� (������ root = 0���� ���ϱ�)

[ fail link ]
���� ���ڿ����� prefix = suffix�� trie���� �����ϴ� �ִ� prefix
���� u�� fail link�� ã������, par[u]�� fail link�� t[x][i]�� ������ ������ �Ž��� �ö󰣴�. (��ġ kmp�� pi�� ���� ��ó��)
fail[u] = t[x][i]�� �ȴ�. (�� ��, �迭�� ������ �߱� ������ t[x][i]�� ������ ��Ʈ�� �ڵ����� ������ ������ ���� ó���� �ʿ䰡 ����.)

OOOOOOOX ���⼭ OOOO �κп��� fail��ũ�� ��� Ÿ�� ���� �Ͱ� ����.
�̰��� �����Ϸ��� par[u]�κ��� �̹� fail ��ũ�� ã������ �ϱ� ������, bfs�� �����Ѵ�.

[ output check ]
Aho-Corasick�� �⺻������ Trie���� �ִ� ������ ��ġ ���¸� �����ϱ� ������, �ش� node������ output �Ӹ��� �ƴ� �װ��� suffix�鿡 ���� output�� ����ؾ� �Ѵ�.
�̰��� ���� u���� fail link�� ������ �Ž��� �ö󰡸� Ȯ���� ���� ������, ��ó���� ���� �� ����ϰ� �� �� �ִ�.

trie�� Ʈ�� ���������, fail link ���� �� ���� tree ���¶�� ���� �� �� �ִ�. (�ᱹ root�� ���� �ǰ�, ���̰� �� node -> ª�� node�� ����Ǳ� ����.)
����, output check�� bfs�� ���� �ѷ��� �� �ִ�.


������ ���� output�� ������ �˾ƾ� �ϴ� ������, ���� ���θ� �˾ƾ� �ϴ� ������ �ִµ�, �� ���� �ٷ� ���� fail link�� output check�� ����ϸ� ���� ���� �����ϴ�.

������, ������ �����ϴ� ���ڿ� list�� �˷��� �� u���� vi�� �����ؾ� �ϴµ�, �̷��� �ϸ� �޸� ���� ���ϴ�.
���� ������ output�� �����ϴ� suffix�� node�� ����Ű�� output-link�� ������ָ� vi�� ������� �ʰ� �����ϴ�.
--> ���߿� output-link�� ���󰡸� ���� �����ϴ� ���ϵ��� ��� �� �� �ִ�.

��, output link�� ���� u���� pre = suf�� pre �� ���Ͽ� �ش�Ǵ� �� �� ���� �� ���� ����Ű�� �ȴ�.

�̰��� ������ �ϴ� ���� fail[u]���� �߻��� ������ �ִٸ� outlink[u] = fail[u] �̰�, ���ٸ� outlink[u] = outlink[fail[u]]�̴�.

*************
< �����Ʈ >   :
precalc���� u = t[u][i]�� ��, u�� �ٱ����� ����Ǿ� ������ �����ؾ� ��. (���ο� ������ ���� �װſ� ���ؼ��� �ؾ� ��.)

precalc �� �ϴ� �Ǽ�

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
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // ������ �� �̻��ϰ� �۵��� �� ����.
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

const int MAXNODE = 1e5+10, MAXC = 26, INITCHAR = 'a';
struct ahocorasick {
	int ncnt, t[MAXNODE][MAXC], f[MAXNODE], chk[MAXNODE];
	ahocorasick() : ncnt(0) { memset(t, 0, sizeof(t)), memset(f, 0, sizeof(f)), memset(chk, 0, sizeof(chk)); }
	void insert(const string& s) {
		int u = 0;
		for(auto i : s) {
			i -= INITCHAR;
			if(!t[u][i]) t[u][i] = ++ncnt;
			u = t[u][i];
		}
		chk[u] = 1; // ���ڿ��� ��
	}
	void precalc() {
		queue<int> q;
		FOR(i, 0, MAXC) if(t[0][i]) q.push(t[0][i]);
		// bfs�� Ž���ϸ� fail, chk ���
		while(q.size()) {
			int x = q.front(); q.pop();
			FOR(i, 0, MAXC) {
				if(t[x][i]) {
					int u = x, p = f[u];
					while(p && !t[p][i]) p = f[p]; // fail link ã��
					u = t[u][i], p = t[p][i]; // ���� ��ǥ�� �������� �̵��Ѵ�.
					f[u] = p;
					if(chk[p]) chk[u] = 1;
					q.push(u);
				}
			}
		}
	}
	bool query(const string& s) {
		int u = 0;
		for(auto i : s) {
			i -= INITCHAR;
			while(u && !t[u][i]) u = f[u];
			if(chk[u = t[u][i]]) return true;
		}
		return false;
	}
};

const int MAXN = 1e3;
int n, q;
ahocorasick aho;
void input() {
	cin >> n;
	while(n--) {
		string s; cin >> s;
		aho.insert(s);
	}
	aho.precalc();
}

int solve() {
	cin >> q;
	while(q--) {
		string s; cin >> s;
		if(aho.query(s)) cout << "YES" << ENDL;
		else cout << "NO" << ENDL;
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