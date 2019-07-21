// ***** matrix class ***** //
// 이 mat은 const로 사용 시 이상하게 작동 할 수 있음. --> 걍 const 사용하지 말고 ㄱ
typedef i64 ELEM;
const ELEM MOD = 1e9+7; // MOD 사용 안 할거면 0x7fffffffffffffff 사용!
struct mat {
	int n, m;
	vector<vector<ELEM> > ar;
	// ----- constructor, assignment  ----- //
	mat(int n, int m, ELEM x = 0) : n(n), m(m), ar(n, vector<ELEM>(m, x)) {  }
	mat(int n = 0) : mat(n, n) {  }
	mat(const mat& o) { n = o.n, m = o.m, ar = o.ar; }
	mat(const vector<vector<ELEM>>& ar) : n(ar.size()), m(ar.size() ? ar[0].size() : 0), ar(ar) { }
	// ----- get field ----- //
	operator const vector<vector<ELEM> >& () const { return ar; }
	vector<ELEM>& operator[](int i) { return ar[i]; }
	const vector<ELEM>& operator[](int i) const { return ar[i]; }
	// ----- calculate ----- //
	mat pow(i64 x) const {
		assert(n == m && 0 <= x);
		mat a(*this), ret = eye(n);
		while(x) {
			if(x%2) ret = ret * a;
			a = a * a;
			x /= 2;
		}
		return ret;
	}
	mat operator * (const mat& o) const {
		assert(m == o.n);
		mat ret(n, o.m);
		FOR(i, 0, n) {
			FOR(j, 0, o.m) {
				FOR(k, 0, m) {
					ret[i][j] += ar[i][k] * o[k][j] % MOD;
					ret[i][j] %= MOD;
				}
			}
		}
		return ret;
	}
	mat operator + (const mat& o) const {
		assert(n == o.n && m == o.m);
		mat ret(n, m);
		FOR(i, 0, n) FOR(j, 0, n) ret[i][j] = (ar[i][j] + o[i][j]) % MOD;
		return ret;
	}
	mat operator - (const mat& o) const {
		assert(n == o.n && m == o.m);
		mat ret(n, m);
		FOR(i, 0, n) FOR(j, 0, n) ret[i][j] = (ar[i][j] - o[i][j]) % MOD;
		return ret;
	}
	mat operator * (const ELEM x) const {
		mat ret = ar;
		FOR(i, 0, n) FOR(j, 0, m) ret[i][j] = ret[i][j] * x % MOD;
		return ret;
	}
	mat operator / (const ELEM x) const {
		mat ret = ar;
		FOR(i, 0, n) FOR(j, 0, m) ret[i][j] = ret[i][j] / x % MOD;
		return ret;
	}
	const mat& operator - () {
		FOR(i, 0, n) FOR(j, 0, m) ar[i][j] = -ar[i][j];
		return *this;
	}
	// 만약 state = state * dp 형태로 쓰고 싶다면 dpmat을 rotate 해서 쓸 것! (가로 행렬)
	mat rotate() const {
		mat ret(m, n);
		FOR(i, 0, n) FOR(j, 0, m) ret[j][i] = ar[i][j];
		return ret;
	}
	static mat eye(const int size) {
		mat ret(size);
		FOR(i, 0, size) ret[i][i] = 1;
		return ret;
	}
	// ----- matrix dp ----- //
	// dp[i] = ar[0] * dp[i-n] + ar[1] * dp[i-n+1] + ... + ar[n-1] * dp[i-1] 에 해당하는 dp 행렬 반환
	// 이 행렬과 곱해지는 데이터 행렬 br은 br[0] = dp[i], br[1] = dp[i-1] ... (state의 순서대로)
	// dp 식에 상수가 있을 경우는 트릭으로 데이터 배열의 한 원소는 계속 고정시키고 그걸 상수로 사용하면 됨.
	static mat dpmat(const vector<ELEM>& ar) {
		int n = ar.size();
		mat ret(n, n);
		FOR(i, 0, n-1) ret[i][i+1] = 1; // 이전 dp값 옮기기
		FOR(i, 0, n) ret[n-1][i] = ar[i]; // 현재 dp[i]에 대한 식 대입
		return ret;
	}
};
ostream& operator<<(ostream& os, const mat& v) { for(auto vv : (vector<vector<ELEM> >)v) os << vv << ENDL; return os; }
// ********** //