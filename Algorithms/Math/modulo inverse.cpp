typedef long long i64;
const i64 MOD = 1e9+7;
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2ll) ret *= a, ret %= MOD; a = a * a, a %= MOD; n /= 2ll; }
	return ret;
}

// a^-1 % MOD
inline i64 RMOD(i64 a) {
	return POW(a, MOD-2);
}

// a*b^-1 % MOD = x
// x*b % MOD = a % MOD
inline i64 FMOD(i64 a, i64 b) {
	return a * RMOD(b) % MOD;
}