// 출처: http://junis3.tistory.com/8
//maxn은 쿼리가 들어갈 직사각형의 너비 = 높이이다. 다르게 하고 싶다면 노드들의 개수를 max−width∗log(max−height)로 해 주어야 할 것이다.
const int maxn = 1<<17;
int root[maxn];
struct pst {
	int v[maxn*17], l[maxn*17], r[maxn*17], t;
	// 0번 트리를 만든다.
	int base(int s, int e) {
		int k = t++;
		if(s<e) {
			int m = (s+e)/2;
			l[k] = base(s, m);
			r[k] = base(m+1, e);
		}
		return k;
	}
	// bef가 루트인 트리를 기반으로 pos에 val을 더함
	int make(int bef, int s, int e, int pos, int val) {
		if(pos<s or e<pos) return bef;
		int k = t++;
		if(s==e) {
			v[k] = v[bef] + val;
		} else {
			int m = (s+e)/2;
			l[k] = make(l[bef], s, m, pos, val);
			r[k] = make(r[bef], m+1, e, pos, val);
			v[k] = v[l[k]] + v[r[k]];
		} return k;
	}
	// k를 루트로 한 트리에서 [x, y] 쿼리 결과를 반환 (여기서는 합) 
	int query(int k, int s, int e, int x, int y) {
		if(x<=s and e<=y) return v[k];
		else if(e<x or y<s) return 0;
		else {
			int m = (s+e)/2;
			return query(l[k], s, m, x, y) + query(r[k], m+1, e, x, y);
		}
	}
} t;