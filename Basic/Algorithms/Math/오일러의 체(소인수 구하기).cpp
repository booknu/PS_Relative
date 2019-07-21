/************
< �ּ� >      : https://cp-algorithms.com/algebra/prime-sieve-linear.html
*************
< �ذ��� >   :
1. �����佺�׳׽��� ü�� O(n)�� ���� �� �ְ� �Ѵ�.
2. ���� ���� ���鿡 ���� spf[x] = x�� ���� ���� ���μ��� �����Ͽ� ���μ����ظ� O(logn)�� �� �� �ְ� ���ش�.


�Ϲ����� ������� ���μ����ظ� �Ϸ���, sqrt(x)������ ��� �Ҽ��� ���� ������ ���� �õ��� ��, ���� x�� ���μ��� �����ϴ� ����� ���ϴµ�,
���Ϸ��� ü�� ���ʿ� ����� ���� �ʴ� �Ҽ��� �õ��� ���� �ʾ� ȿ�����̴�.

���Ϸ��� ü�� ���ϴ� ����� �����佺�׳׽��� ü�� ���ϴ� ����� ����ϴ�.
x = [2..RANGE]���� ���� ���� �������� �װ��� ����� üũ�ϴ� ����ε�,

�����佺�׳׽��� ü ���� ���� ���� ���� ������ �湮�ϸ� isprime�� üũ�ϱ� ������ �ð����⵵�� O(nloglogn)�̴�.


������, ���Ϸ��� ü�� ���� ���� �����ϰ� �湮�Ѵ�.

�� ����� ���� x�� prime ��� ��, pr <= spf[x]�� pr�鸸 �湮�ϴ� ���̴�.
�� ���п� �翬�� spf[x*pr] = pr�̰�, ��� ���� 1������ �湮�� �� �ִ�.

��� ���� �� 1���� �湮�Ѵٴ� ������,
�ڿ��� i > 1�� ���Ͽ�
i = spf[i] * x�� ǥ�� �����ϱ� ����.
(�� ��, spf[x] <= spf[i] �̱� ������, ���� ���� ǥ������ i�� �� 1���ۿ� ������ �� ����.)

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

// --> x*pr[j]���� overflow �߻��� �� ����! �׷��� ������ ���� RANGE������ �Ҽ� ������ �����ϱ� ������ �߻����� ����.
// --> RANGE ���� �Ҽ� ���� = RANGE/ln(RANGE) --> 2e7���� ���� �Ҽ� �ִ� ���� = 180, 4e6 = 140
const int RANGE = 2e7;
int pn, spf[RANGE], pr[RANGE]; // pr�� vi�� �����ص� ��. --> but ���� �ð� ���� �þ.
void eulerSieve() {
	FOR(x, 2, RANGE) {
		if(!spf[x]) spf[x] = pr[pn++] = x; // x ��ü�� �Ҽ��̸� spf[x] = x�̴�.
		for(int j = 0; x*pr[j] < RANGE; ++j) { // x�� �Ҽ���鿡 spf[x*pr] = pr�� ĥ���ش�. (��, pr <= spf[x])
			spf[x*pr[j]] = pr[j];
			if(x % pr[j] == 0) break; // �� �� ���������� if(spf[x] == pr[j])�� �����ص� ������, �Ȱ��� ȿ���� ���� �ڵ��̴�.
		}
	}
}

// �� �� ���������� �����ϸ� ������ ����.
// but, ���� ���� �迭�� �̿��� ����� 2e7 �������� 180ms, �� ����� 3500ms --> ���� �迭�� �Ѱ��ε� --> �ٵ� ������ �����غ��� �Ȱ���
int spf[RANGE];
vi pr;
void eulerSieve() {
	FOR(x, 2, RANGE) {
		if(!spf[x]) spf[x] = x, pr.pb(x);
		for(int y : pr) {
			if(spf[x] < y || RANGE <= x*y) break;
			spf[x*y] = y;
		}
	}
}


vi getPrimeFactor(int x) {
	vi ret;
	while(x > 1) {
		int p = spf[x];
		ret.pb(p);
		while(x % p == 0) x /= p;
	}
	return ret;
}