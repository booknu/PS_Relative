const int ST_MAX = 1<<21;
// ���׸�Ʈ Ʈ�� ����ü
struct SegTree{
	int start;
	long long arr[ST_MAX], lazy[ST_MAX];

	// ������
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}

	// ���� ������ ���� ���� �Է��� �� ��ü ���׸�Ʈ Ʈ�� ����
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}

	// ���� [ns, ne)�� node�� lazy ���� propagate
	void propagate(int node, int ns, int ne){
		// lazy ���� �����ϸ� ����
		if(lazy[node] != 0){
			// ���� ��尡 �ƴϸ� �ڽĵ鿡�� lazy �̷�
			if(node < start){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			// �ڽſ� �ش��ϴ� ��ŭ�� ���� ����
			arr[node] += lazy[node] * (ne-ns);
			lazy[node] = 0;
		}
	}

	// ���� [s, e)�� k�� ���϶�
	void add(int s, int e, int k){ add(s, e, k, 1, 0, start); }
	void add(int s, int e, int k, int node, int ns, int ne){
		// �ϴ� propagate
		propagate(node, ns, ne);

		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			// �� ��尡 ������ ������ ���ԵǸ� lazy �ο� �� propagate
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(s, e, k, node*2, ns, mid);
		add(s, e, k, node*2+1, mid, ne);
		// �������� �ڽĵ��� ���� ����� �ٽ� �ڽ��� �� ����
		arr[node] = arr[node*2] + arr[node*2+1];
	}

	// ���� [s, e)�� ���� ���϶�
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		// �ϴ� propagate
		propagate(node, ns, ne);

		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

[��ó] ������ �����۰��̼�(Lazy Propagation) (����: 2019-07-06)|�ۼ��� ����