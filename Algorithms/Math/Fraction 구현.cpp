/************
< 주소 >      :
*************
< 해결방안 >   :


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
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); }
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

// **** fraction class **** //
// dependency: GCD(i64 a, i64 b)
struct frac {
	i64 a, b;
	frac(i64 a=0, i64 b=1) : a(a), b(b) { relax(); }
	// 필수 fraction끼리의 연산
	void relax() { i64 g = GCD(abs(a), b); a /= g, b /= g; }
	frac operator + (const frac &ot) const { return { a * ot.b + ot.a * b, b * ot.b }; }
	frac operator - (const frac &ot) const { return { a * ot.b - ot.a * b, b * ot.b }; }
	frac operator * (const frac &ot) const { return { a * ot.a, b * ot.b }; }
	frac operator / (const frac &ot) const { return { a * ot.b, b * ot.a }; }
	frac operator - () { return { -a, b }; }
	// fraction 비교연산
	bool operator == (const frac& ot) const { return a * ot.b == ot.a * b; }
	bool operator < (const frac& ot) const { return a * ot.b < ot.a * b; }
	bool operator <= (const frac& ot) const { return a * ot.b <= ot.a * b; }
	bool operator > (const frac& ot) const { return ot <= *this; }
	bool operator >= (const frac& ot) const { return ot < *this; }
	// advanced 연산 (시간 없으면 안 써도 됨.)
	const frac& operator += (const frac &ot) { return *this = *this + ot; }
	const frac& operator -= (const frac &ot) { return *this = *this - ot; }
	const frac& operator *= (const frac &ot) { return *this = *this * ot; }
	const frac& operator /= (const frac &ot) { return *this = *this / ot; }
};
// fraction 입출력
ostream& operator<< (ostream& os, const frac& frac_x) { return os << frac_x.a << "/" << frac_x.b; }
istream& operator>> (istream& os, frac& frac_x) {
	os >> frac_x.a >> frac_x.b;
	frac_x.relax();
	return os;
}
// ******** //

void input() {

}

frac x, y;
int solve() {
	// 생성 관련 가능한 연산
	cout << "---- constuctor, operator= ----" << ENDL;
	debug(x ={ 1, 3 });
	debug(x = 3);
	y ={ 4, 5 };
	debug(x = y);
	debug(frac(y));
	debug(frac(100, 1000));

	// 기본 사칙연산
	cout << "---- basic calculation ----" << ENDL;
	x ={ 2, 5 }, y ={ 4, 5 };
	debug(x + y);
	debug(x - y);
	debug(x * y);
	debug(x / y);

	// 정수와의 사칙연산
	cout << "---- integer calculation ----" << ENDL;
	// debug(3 + x) --> fraction이 항상 앞에 와야 함!
	debug(x + 3);
	debug(x - 3);
	debug(x * 3);
	debug(x / 3);

	// advanced 사칙연산
	cout << "---- advanced calculation ----" << ENDL;
	debug(x += 3);
	debug(x -= 3);
	debug(x *= 3);
	debug(x /= 3);

	// 비교연산
	cout << "---- comparison ----" << ENDL;
	frac a(1, 7), b(3, 7), c(3, 7);
	debug(a, b, a < b, a <= b);
	debug(a, b, a > b, a >= b);
	debug(a, b, a == b);
	debug(b, a, b < a, b <= a);
	debug(b, a, b > a, b >= a);
	debug(b, a, b == a);
	debug(b, c, b < c, b <= c);
	debug(b, c, b > c, b >= c);
	debug(b, c, b == c);

	// sort
	cout << "---- sorting ----" << ENDL;
	vector<frac> ar ={ 4, 2, 3, 1 };
	debug(ar);
	sort(ALL(ar));
	debug(ar);
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