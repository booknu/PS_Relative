namespace miller_rabin{ // O(log P), prime list can be { 2, 7, 61 }
	i64 mul(i64 x, i64 y, i64 mod){ return (__int128) x * y % mod; }
	i64 ipow(i64 x, i64 y, i64 p){
		i64 ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(i64 x, i64 a){
		if(x % a == 0) return 0;
		i64 d = x - 1;
		while(1){
			i64 tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(i64 x){ // to use another prime list, erase limit for 40
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
}