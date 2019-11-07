const int ST_MAX = 1<<21, lf = ST_MAX/2; 
struct segtree{
	i64 t[ST_MAX], d[ST_MAX];
	segtree(){ memset(t, 0, sizeof(t)), memset(d, 0, sizeof(d)); }
	void build(){ RFOR(i, lf-1, 1) t[i] = t[i*2]+ t[i*2+1]; } // !! BUILD !!
	void propagate(int u, int ns, int ne){
		if(!d[u]) return;
		if(u < lf){ // propagate to childs
			d[u*2] += d[u];
			d[u*2+1] += d[u];
		}
		t[u] += d[u] * (ne-ns); // update node
		d[u] = 0;
	}
	void add(int s, int e, int x){ add(s, e, x, 1, 0, lf); } // [s, e)
	void add(int s, int e, int x, int u, int ns, int ne){
		propagate(u, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			d[u] += x;
			propagate(u, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(s, e, x, u*2, ns, mid), add(s, e, x, u*2+1, mid, ne);
		t[u] = t[u*2] + t[u*2+1];
	}
	i64 sum(int s, int e){ return sum(s, e, 1, 0, lf); } // [s, e)
	i64 sum(int s, int e, int u, int ns, int ne){
		propagate(u, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return t[u];
		int mid = (ns+ne)/2;
		return sum(s, e, u*2, ns, mid) + sum(s, e, u*2+1, mid, ne);
	}
};