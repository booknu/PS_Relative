/************
< 주소 >      :
https://ko.wikipedia.org/wiki/%EC%9A%94%EC%84%B8%ED%91%B8%EC%8A%A4_%EB%AC%B8%EC%A0%9C	 (O(n))
https://en.wikipedia.org/wiki/Josephus_problem#Solution
https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/						 (O(n))
https://stackoverflow.com/questions/4845260/josephus-for-large-n-facebook-hacker-cup     (O(klogn))

[ 문제들 ]
http://codersbrunch.blogspot.com/2016/06/11025-3.html
https://lyzqm.blogspot.com/2017/06/1242.html
*************
< 해결방안 >   :
[ 문제 정의 ]
n명이 circular 형태로 앉아있고, 1번째 사람부터 시작하여 k번째 사람을 제거해나가는 것을 반복할 때 가장 마지막에 남는 사람을 구하는 문제.

[ naive solution ]
linked list, queue를 사용하여 일일이 시뮬레이션 하면 O(nk)에 문제를 해결할 수 있다.
queue같은 경우는 k번의 q.push(q.front()); q.pop();을 반복하고 현재 top을 구하는 것을 반복하면 쉽게 해결할 수 있다.

[ O(n) solution ]
f(n, k) = n, k일 때 마지막에 남는 사람의 번호

번호를 1-idx로 붙였을 때 다음과 같은 점화식을 얻을 수 있다.
f(1, k) = 1
f(n, k) = ((f(n-1, k) + k-1) % n) + 1

번호를 0-idx로 붙이면 점화식이 조금 더 간결해진다.
f(1, k) = 0;
f(n, k) = ((f(n-1, k) + k) % n)


f(n, k)에서 첫 번째 사람이 죽은 뒤, n-1명이 남는다.
따라서 f(n-1, k)를 호출하면 마지막에 죽는 사람이 누구인지 알 수 있다.
하지만, f(n-1, k)는 idx가 그것을 기준으로 나오니까, f(n, k) 기준의 idx가 필요하니, 현재 k번째를 죽이고 난 뒤를 기준으로 삼는다. (k + idx) % n을 취해줘야 한다.   (0-idx 기준으로)
--> 즉, 현재 죽어야 할 사람은 k-1, 따라서 f(n-1, k)의 idx 0의 기준은 k-1의 다음인 k가 된다. 따라서 마지막에 죽는 사람은 (k + idx) % n이다.

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

// O(KlogN) algorithm 
long long joseph (long long n,long long k) {
	if (n==1LL) return 0LL;
	if (k==1LL) return n-1LL;
	if (k>n) return (joseph(n-1LL,k)+k)%n;
	long long cnt=n/k;
	long long res=joseph(n-cnt,k);
	res-=n%k;
	if (res<0LL) res+=n;
	else res+=res/(k-1LL);
	return res;
}

void input() {

}

int solve() {

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