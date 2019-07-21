/************
< 주소 >      : https://www.acmicpc.net/problem/9359
*************
< 해결방안 >   :
[s..e] 범위에 n과 서로소인 정수가 몇 개 있는지 세는 문제이다.

이것은 곧 s - e + 1 - n의 소인수의 배수  로 구할 수 있다.

이제 문제는 두 가지인데,
1. 100개의 TC에서 1e9 범위인 n의 소인수들을 어떻게 구할 것인지?
2. 소인수의 배수가 겹치는 경우는 어떻게 처리할 것인지?

1번부터 해결하자면,
소인수는 소수들로 이루어져있다.
또한 1e9 범위 내의 소수는 굉장히 적다.

따라서 에라토스테네스의 체로 소수인 수들을 전처리로 구한 후, 소수들에 대해 n에 나누어 떨어지면 그 소수는 n의 소인수이다.

문제는 1e9 범위의 소수를 모두 구하려면 메모리가 부족하다는 것인데, sqrt(n)까지만 구한다고 생각해보자
우선 sqrt(n)보다 작거나 같은 소수는 위 방법으로 모두 구할 수 있다.
큰 소인수는 어떻게 구해야 할까?

sqrt(n)보다 큰 소인수는 최대 1개이며, 그마저도 계승이 1이라는 사실을 쉽게 알 수 있다.
n = a^i * b^j * ... 이런 식으로 이루어 지는데, 여기에 sqrt(n)보다 큰 것이 두 개 이상 들어갈 리가 없다.

따라서 sqrt(n)보다 작은 소인수를 모두 구하고, 그것들로 n을 최대한 나눠주고 남는 것이 sqrt(n)보다 큰 소인수이다. (물론 없을 수도 있다.)


2번은 포함-배제로 쉽게 해결 할 수 있다.
재귀적으로 구현하는 방법도 있다.
포함-배제 식을 잘 정리하면 다음과 같은 재귀 식을 얻을 수 있다.
union(A[1..n]) = A[1] + union(A[2..n]) - intersection(A[1], union(A[2..i]))
이 때, union(A[2..n])는 그냥 i를 하나 늘려주면 되지만,
	  intersection(A[1], union(A[2..i]))은 A[1]과의 교집합에 대해 처리해줘야 한다는 것을 기억해야 한다.

*************
< 오답노트 >   :

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
// 위의 두 개를 재귀적으로 탐색
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