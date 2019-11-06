/*
sa[i] = ordered suffix (suffix's start position)
ord[i] = [i:]'s index in sa  (ord[sa[i]] = i)
lcp[i] = longest common prefix length of two suffix [i-1:], [i:]

LCP's Lemma
1.	Two adjacent in SA suffixes' LCP is always bigger than which of non-adjacents
2.	lcp(sa[i-1], sa[i]) = h, h >= 1 then
lcp(sa[i-1]+1, sa[i]+1) = h-1

So that lcp[sa[i]+1] >= h-1 because it is always bigger than lcp(sa[i-1]+1, sa[i]+1) by Lemma 1
and by Lemma 2, lcp(sa[i-1]+1, sa[i]+1) = h-1
*/
struct sfxarray {
	int n;
	string& str;
	vi sa, lcp, ord;
	sfxarray(string& str) : str(str), n(str.size()) { }
	void getsa() {
		sa = ord = vi(n+1);
		FOR(i, 0, n) sa[i] = i, ord[i] = str[i]; ord[n] = 0;
		for(int t = 1; t <= n; t *= 2) {
			int sz = max(257, n+1);
			vi cnt, tmp;
			cnt = tmp = vi(sz, 0);
			FOR(i, 0, n) ++cnt[ord[min(n, i+t)]];
			FOR(i, 1, sz) cnt[i] += cnt[i-1];
			FOR(i, 0, n) tmp[--cnt[ord[min(n, i+t)]]] = i;
			cnt = vi(sz, 0);
			FOR(i, 0, n) ++cnt[ord[i]];
			FOR(i, 1, sz) cnt[i] += cnt[i-1];
			RFOR(i, n-1, 0) sa[--cnt[ord[tmp[i]]]] = tmp[i];
			tmp[sa[0]] = 1;
			FOR(i, 1, n) {
				int u = sa[i-1], v = sa[i];
				tmp[v] = tmp[u] + (ord[u] < ord[v] || ord[u+t] < ord[v+t]);
			}
			ord = tmp;
			if(ord[sa[n-1]] == n) break;
		}
		FOR(i, 0, n) --ord[i];
	}
	void getlcp() {
		lcp = vi(n, 0);
		for(int i = 0, len = 0; i < n; ++i, len = max(0, len-1)) {
			if(ord[i]) {
				for(int j = sa[ord[i]-1]; str[i+len] == str[j+len]; ++len);
				lcp[ord[i]] = len;
			}
		}
	}
	tuple<vi, vi, vi> build() { getsa(), getlcp(); return { sa, lcp, ord }; }
};