/************
< �ּ� >      : http://codeforces.com/contest/1000/problem/E
*************
< �ذ��� >   :
������ ��, ������ ����, �� �� s, t�� ���� �ش� s, t ������ ��� ��� �� ���� ������ �� �ۿ� ���� �����鸸 ����.
�� �� �������� ������ �ִ�ȭ ��Ű�� �����̴�.

���� ���õǴ� �������� bridge�� ���ۿ� ����.

dfs spanning tree�� ����� �� �����鿡 ���� bridge���� ������ �����Ѵ�.
(�� ��, �������� �������� ���� bridge�� ���� ���Ѵ�! Ʈ�������� ���ɼ� ����)

�� �� �ٽ� dfs�ϸ鼭 Ʈ��dp �������� dp[u] = u���� ������ ���������� �� �� ���� �� �ִ� �ִ� bridge �� �� ���س���,
dp[u] = max(dp[v] + u->v is bridge? 1 : 0) ���� ���� �� �ִ�.

���� �� u���� u�� ������ �ִ� s->t�� ���Ϸ��� dp[u->v] �� ���� ū �� 2���� ��� ���ϸ� �ȴ�.

*************
< �����Ʈ >   :

*************/

// Find Bridge
const int MAXN = 3e5, INF = 0x7fffffff;
int ncnt, vid[MAXN], par[MAXN];
vii g[MAXN]; // (v, bridge flag)
int dfs(int u) {
	int ret = vid[u] = ncnt++;
	for(auto& e : g[u]) {
		int v = e.se, c = INF;
		if(par[u] == v) continue; // Tree edge
		if(vid[v] == -1) { // Tree Edge
			par[v] = u;
			c = min(c, dfs(v));
		} else c = min({ c, vid[v], vid[u] }); // Forward/Backward Edge
		if(c > vid[u]) e.fi = 1; // Bridge
		ret = min(ret, c);
	}
	return ret;
}