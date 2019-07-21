// ***** matrix class ***** //
// �� mat�� const�� ��� �� �̻��ϰ� �۵� �� �� ����. --> �� const ������� ���� ��
typedef i64 ELEM;
const ELEM MOD = 1e9+7; // MOD ��� �� �ҰŸ� 0x7fffffffffffffff ���!
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
	// ���� state = state * dp ���·� ���� �ʹٸ� dpmat�� rotate �ؼ� �� ��! (���� ���)
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
	// dp[i] = ar[0] * dp[i-n] + ar[1] * dp[i-n+1] + ... + ar[n-1] * dp[i-1] �� �ش��ϴ� dp ��� ��ȯ
	// �� ��İ� �������� ������ ��� br�� br[0] = dp[i], br[1] = dp[i-1] ... (state�� �������)
	// dp �Ŀ� ����� ���� ���� Ʈ������ ������ �迭�� �� ���Ҵ� ��� ������Ű�� �װ� ����� ����ϸ� ��.
	static mat dpmat(const vector<ELEM>& ar) {
		int n = ar.size();
		mat ret(n, n);
		FOR(i, 0, n-1) ret[i][i+1] = 1; // ���� dp�� �ű��
		FOR(i, 0, n) ret[n-1][i] = ar[i]; // ���� dp[i]�� ���� �� ����
		return ret;
	}
};
ostream& operator<<(ostream& os, const mat& v) { for(auto vv : (vector<vector<ELEM> >)v) os << vv << ENDL; return os; }
// ********** //