/************
< 주소 >      : http://codeforces.com/contest/1000/problem/E
*************
< 해결방안 >   :
문제는 즉, 임의의 시작, 끝 점 s, t를 고르고 해당 s, t 사이의 모든 경로 중 빈드시 지나갈 수 밖에 없는 간선들만 고른다.
이 때 간선들의 개수를 최대화 시키는 문제이다.

따라서 선택되는 간선들은 bridge일 수밖에 없다.

dfs spanning tree를 만들어 각 간선들에 대해 bridge인지 정보를 저장한다.
(이 때, 역간선과 순간선은 절때 bridge가 되지 못한다! 트리간선만 가능성 있음)

그 후 다시 dfs하면서 트리dp 형식으로 dp[u] = u에서 하위로 일직선으로 갈 때 만날 수 있는 최대 bridge 수 로 정해놓고,
dp[u] = max(dp[v] + u->v is bridge? 1 : 0) 으로 구할 수 있다.

또한 각 u에서 u를 지나는 최대 s->t를 구하려면 dp[u->v] 중 가장 큰 것 2개를 골라 더하면 된다.

*************
< 오답노트 >   :

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