// f(p) = s[0] + s[1] * p + s[2] * p^2 + ... + s[n-1] * p^{n-1)
// h[i+1] = p * (h[i] - s[i] * s^(m-1)) + s[i+m]
// --> sub first character from hash > hash degree up > add last character to hash
const i64 MUL = 232153, MD = 1012924417; // be careful for MD not MOD
void mod(i64& x) { x %= MD; if(x < 0) x += MD; }
vi rabin(string& s, string& t) { // return start indexs
	vi ret;
	i64 ht = 0, hs = 0, mul = 1;
	RFOR(i, sz(t)-1, 0) { // get t's hash
		mod(ht += mul * t[i] % MD);
		mod(mul = mul * MUL);
	}
	mul = 1;
	RFOR(i, sz(t)-1, 0) { // get s's hash for first sz(t) string
		mod(hs += mul * s[i] % MD);
		if(i != 0) mod(mul = mul * MUL); // mul must be p^{m-1)
	}
	if(hs == ht) ret.pb(0);
	FOR(i, sz(t), sz(s)) {
		mod(hs -= mul*s[i-sz(t)]%MD);
		mod(hs *= MUL);
		mod(hs += s[i]);
		if(hs == ht) ret.pb(i-sz(t)+1);
	}
	return ret;
}