/************
< 주소 >      : https://www.acmicpc.net/problem/9250
*************
< 해결방안 >   :
배열로 구현한 Aho-Corasick

[ 장점 ]
- 현재 c 간선이 있는지 쉽게 알 수 있음 (없으면 0으로 초기화된 상태 그대로니까)
- 정점에 번호가 매겨져있어 dp를 적용하기 쉬움.
- 현재 c 간선이 없더라도 이것에 대한 처리를 하지 않고 그냥 t[u][c]로 가도 됨 (어차피 root = 0으로 가니까)

[ fail link ]
현재 문자열에서 prefix = suffix인 trie에서 존재하는 최대 prefix
현재 u의 fail link를 찾으려면, par[u]의 fail link를 t[x][i]가 존재할 때까지 거슬러 올라간다. (마치 kmp의 pi를 구할 때처럼)
fail[u] = t[x][i]가 된다. (이 때, 배열로 구현을 했기 때문에 t[x][i]가 없더라도 루트로 자동으로 가지기 때문에 따로 처리할 필요가 없다.)

OOOOOOOX 여기서 OOOO 부분에서 fail링크를 계속 타고 가는 것과 같음.
이것이 가능하려면 par[u]부분은 이미 fail 링크가 찾아져야 하기 때문에, bfs로 구현한다.

[ output check ]
Aho-Corasick은 기본적으로 Trie에서 최대 길이의 일치 상태를 유지하기 때문에, 해당 node에서의 output 뿐만이 아닌 그것의 suffix들에 대한 output도 고려해야 한다.
이것은 현재 u에서 fail link를 일일이 거슬러 올라가며 확인할 수도 있지만, 전처리를 통해 더 깔끔하게 할 수 있다.

trie는 트리 모양이지만, fail link 역시 잘 보면 tree 형태라는 것을 알 수 있다. (결국 root로 오게 되고, 길이가 긴 node -> 짧은 node로 연결되기 때문.)
따라서, output check도 bfs를 통해 뿌려줄 수 있다.


문제에 따라서 output의 개수를 알아야 하는 문제나, 존재 여부를 알아야 하는 문제가 있는데, 이 경우는 바로 상위 fail link의 output check를 계승하면 쉽게 구현 가능하다.

하지만, 실제로 등장하는 문자열 list를 알려면 각 u마다 vi를 저장해야 하는데, 이렇게 하면 메모리 낭비가 심하다.
따라서 실제로 output이 존재하는 suffix의 node를 가리키는 output-link를 만들어주면 vi를 사용하지 않고도 가능하다.
--> 나중에 output-link를 따라가면 실제 등장하는 패턴들을 모두 알 수 있다.

즉, output link란 현재 u에서 pre = suf인 pre 중 패턴에 해당되는 것 중 가장 긴 것을 가리키면 된다.

이것의 구현은 일단 현재 fail[u]에서 발생한 패턴이 있다면 outlink[u] = fail[u] 이고, 없다면 outlink[u] = outlink[fail[u]]이다.

*************
< 오답노트 >   :
precalc에서 u = t[u][i]할 때, u는 바깥에서 선언되어 있음에 조심해야 함. (새로운 변수를 만들어서 그거에 대해서만 해야 함.)

precalc 안 하는 실수

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
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // 음수일 때 이상하게 작동할 수 있음.
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
		chk[u] = 1; // 문자열의 끝
	}
	void precalc() {
		queue<int> q;
		FOR(i, 0, MAXC) if(t[0][i]) q.push(t[0][i]);
		// bfs로 탐색하며 fail, chk 계산
		while(q.size()) {
			int x = q.front(); q.pop();
			FOR(i, 0, MAXC) {
				if(t[x][i]) {
					int u = x, p = f[u];
					while(p && !t[p][i]) p = f[p]; // fail link 찾기
					u = t[u][i], p = t[p][i]; // 원래 목표인 정점으로 이동한다.
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