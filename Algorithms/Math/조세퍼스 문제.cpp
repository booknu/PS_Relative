/************
< �ּ� >      :
https://ko.wikipedia.org/wiki/%EC%9A%94%EC%84%B8%ED%91%B8%EC%8A%A4_%EB%AC%B8%EC%A0%9C	 (O(n))
https://en.wikipedia.org/wiki/Josephus_problem#Solution
https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/						 (O(n))
https://stackoverflow.com/questions/4845260/josephus-for-large-n-facebook-hacker-cup     (O(klogn))

[ ������ ]
http://codersbrunch.blogspot.com/2016/06/11025-3.html
https://lyzqm.blogspot.com/2017/06/1242.html
*************
< �ذ��� >   :
[ ���� ���� ]
n���� circular ���·� �ɾ��ְ�, 1��° ������� �����Ͽ� k��° ����� �����س����� ���� �ݺ��� �� ���� �������� ���� ����� ���ϴ� ����.

[ naive solution ]
linked list, queue�� ����Ͽ� ������ �ùķ��̼� �ϸ� O(nk)�� ������ �ذ��� �� �ִ�.
queue���� ���� k���� q.push(q.front()); q.pop();�� �ݺ��ϰ� ���� top�� ���ϴ� ���� �ݺ��ϸ� ���� �ذ��� �� �ִ�.

[ O(n) solution ]
f(n, k) = n, k�� �� �������� ���� ����� ��ȣ

��ȣ�� 1-idx�� �ٿ��� �� ������ ���� ��ȭ���� ���� �� �ִ�.
f(1, k) = 1
f(n, k) = ((f(n-1, k) + k-1) % n) + 1

��ȣ�� 0-idx�� ���̸� ��ȭ���� ���� �� ����������.
f(1, k) = 0;
f(n, k) = ((f(n-1, k) + k) % n)


f(n, k)���� ù ��° ����� ���� ��, n-1���� ���´�.
���� f(n-1, k)�� ȣ���ϸ� �������� �״� ����� �������� �� �� �ִ�.
������, f(n-1, k)�� idx�� �װ��� �������� �����ϱ�, f(n, k) ������ idx�� �ʿ��ϴ�, ���� k��°�� ���̰� �� �ڸ� �������� ��´�. (k + idx) % n�� ������� �Ѵ�.   (0-idx ��������)
--> ��, ���� �׾�� �� ����� k-1, ���� f(n-1, k)�� idx 0�� ������ k-1�� ������ k�� �ȴ�. ���� �������� �״� ����� (k + idx) % n�̴�.

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