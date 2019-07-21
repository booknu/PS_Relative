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
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //

template<class T, class C>
struct segtree {
	int n;
	vector<T> t;
	void build(const vector<T>& ar) {
		n = ar.size();
		t.assign(n*2, 0); // n*2 ��ŭ�� ������ ����ϴ�!
		FOR(i, 0, n) t[n+i] = ar[i];
		RFOR(i, n-1, 1) t[i] = C()(t[i*2], t[i*2+1]);
	}
	void mod(int u, T k) {
		// leaf�� �ٲ����, �θ�� �ö󰡸� node ���� �����Ѵ�.
		for(t[u += n] = k; u > 1; u /= 2) t[u/2] = C()(t[u], t[u^1]);
	}
	T query(int s, int e) {
		T ret = 0;
		for(s += n, e += n; s < e; s /= 2, e /= 2) {
			// s�� ������ child�� ������ �� ���� ���ԵǾ� ��! ���� Ž�� ���� �� �����ʺ���
			if(s & 1) ret = C()(ret, t[s++]);
			// e�� ���� child�� ������ �� ���� ���ԵǾ� ��! e�� ���������̹Ƿ�, ������ child�� ��� ���� node�� ���ϴ� ���
			if(e & 1) ret = C()(ret, t[--e]);
		}
		return ret;
	}
};