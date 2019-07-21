/************
< �ּ� >      : https://www.acmicpc.net/problem/9359
*************
< �ذ��� >   :
[s..e] ������ n�� ���μ��� ������ �� �� �ִ��� ���� �����̴�.

�̰��� �� s - e + 1 - n�� ���μ��� ���  �� ���� �� �ִ�.

���� ������ �� �����ε�,
1. 100���� TC���� 1e9 ������ n�� ���μ����� ��� ���� ������?
2. ���μ��� ����� ��ġ�� ���� ��� ó���� ������?

1������ �ذ����ڸ�,
���μ��� �Ҽ���� �̷�����ִ�.
���� 1e9 ���� ���� �Ҽ��� ������ ����.

���� �����佺�׳׽��� ü�� �Ҽ��� ������ ��ó���� ���� ��, �Ҽ��鿡 ���� n�� ������ �������� �� �Ҽ��� n�� ���μ��̴�.

������ 1e9 ������ �Ҽ��� ��� ���Ϸ��� �޸𸮰� �����ϴٴ� ���ε�, sqrt(n)������ ���Ѵٰ� �����غ���
�켱 sqrt(n)���� �۰ų� ���� �Ҽ��� �� ������� ��� ���� �� �ִ�.
ū ���μ��� ��� ���ؾ� �ұ�?

sqrt(n)���� ū ���μ��� �ִ� 1���̸�, �׸����� ����� 1�̶�� ����� ���� �� �� �ִ�.
n = a^i * b^j * ... �̷� ������ �̷�� ���µ�, ���⿡ sqrt(n)���� ū ���� �� �� �̻� �� ���� ����.

���� sqrt(n)���� ���� ���μ��� ��� ���ϰ�, �װ͵�� n�� �ִ��� �����ְ� ���� ���� sqrt(n)���� ū ���μ��̴�. (���� ���� ���� �ִ�.)


2���� ����-������ ���� �ذ� �� �� �ִ�.
��������� �����ϴ� ����� �ִ�.
����-���� ���� �� �����ϸ� ������ ���� ��� ���� ���� �� �ִ�.
union(A[1..n]) = A[1] + union(A[2..n]) - intersection(A[1], union(A[2..i]))
�� ��, union(A[2..n])�� �׳� i�� �ϳ� �÷��ָ� ������,
	  intersection(A[1], union(A[2..i]))�� A[1]���� �����տ� ���� ó������� �Ѵٴ� ���� ����ؾ� �Ѵ�.

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

const int RANGE = 1e5;
i64 a, b, n, nn;
bool np[RANGE];
vi pr;
vector<i64> d;
void input() {
	cin >> a >> b >> n;
}

void init() {
	for(int i = 2; i*i < RANGE; ++i) {
		if(np[i]) continue;
		for(int j = i*i; j < RANGE; j += i) {
			np[j] = 1;
		}
	}
	FOR(i, 2, RANGE) if(!np[i]) pr.pb(i);
}

// union(A[1..n]) = A[1] + union(A[2..n]) - intersection(A[1], union(A[2..i]))
// ���� �� ���� ��������� Ž��
i64 f(int i, i64 m, i64 e) {
	if(i == d.size()) return 0;
	i64 ret = e / (d[i] * m);
	ret += f(i+1, m, e);
	ret -= f(i+1, d[i] * m, e);
	return ret;
}

int solve() {
	d.clear();
	for(int i = 0; i < pr.size() && pr[i] <= n; ++i) {
		if(n % pr[i] == 0) {
			d.pb(pr[i]);
			while(n % pr[i] == 0) n /= pr[i];
		}
	}
	if(n != 1) d.pb(n);
	cout << (b - a + 1) - f(0, 1, b) + f(0, 1, a-1) << ENDL;
	return 0;
}

// ................. main .................. //
void execute() {
	int TTTT; cin >> TTTT;
	init();
	FOR(tttt, 0, TTTT) {
		cout << "Case #" << tttt +1 << ": ";
		input(), solve();
	}
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