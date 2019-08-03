/************
< �ּ� >      : 1633 �ְ��� �� �����
*************
< �ذ��� >   :

S->�����: cap = 1, cost = 0
�����->��, ��: cap = 1, cost = �Ƿ�(minus)
��, ��->T: cap = 15, cost = 0

*************
< �����Ʈ >   :
�̰� MCMF �������� ��� �˾������� �ұ�?
�Ǽ��� �������� cost�� �� ����. �� q�� S �� �������.
V�� ������������ �����س��� �Է� �� �� ���������� �ؼ� V�� �Է��� �� ��

*************/

#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;

// ........................macro.......................... //
// pair, vector ������ �� {} �ᵵ ��
// [i, n)
#define FOR(i, f, n) for(int (i) = (f); (i) < (n); ++(i))
// [i, n]
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (n); --(i))
#define pb push_back
#define fi first
#define se second
#define ENDL '\n'
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;
// ....................................................... //

const int S = 0, T = 1, W = 2, B = 3;
const int MAXV = 1004;
int N, V;
int cap[MAXV][MAXV], flow[MAXV][MAXV], cost[MAXV][MAXV];
int person(int i) { return 4 + i; }
void input() {
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	memset(cost, 0, sizeof(cost));
	N = 0;
	cap[W][T] = cap[B][T] = 15;
	int w, b;
	while (scanf("%d %d", &w, &b) != EOF) {
		cap[S][person(N)] = cap[person(N)][W] = cap[person(N)][B] = 1;
		cost[person(N)][W] = -w;
		cost[W][person(N)] = w;
		cost[person(N)][B] = -b;
		cost[B][person(N)] = b;
		++N;
	}
	V = N + 4;
}

const int INF = 987654321;
int MCMF() {
	int ret = 0;
	while (true) {
		queue<int> q;
		int dist[MAXV], parent[MAXV];
		fill(dist, dist + MAXV, INF);
		fill(parent, parent + MAXV, -1);
		bool inQ[MAXV] = { 0 };
		q.push(S);
		dist[S] = 0;
		parent[S] = S;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			inQ[u] = false;
			FOR(v, 0, V) {
				if (cap[u][v] - flow[u][v] > 0 && dist[u] + cost[u][v] < dist[v]) {
					dist[v] = dist[u] + cost[u][v];
					parent[v] = u;
					if (!inQ[v]) {
						inQ[v] = true;
						q.push(v);
					}
				}
			}
		}
		if (parent[T] == -1) break;
		int maxFlow = INF;
		for (int u = T; u != S; u = parent[u]) {
			maxFlow = min(maxFlow, cap[parent[u]][u] - flow[parent[u]][u]);
		}
		for (int u = T; u != S; u = parent[u]) {
			flow[parent[u]][u] += maxFlow;
			flow[u][parent[u]] -= maxFlow;
			ret += maxFlow * cost[parent[u]][u];
		}
	}
	return ret;
}

void solve() {
	cout << -MCMF() << ENDL;
}

// ................. main .................. //
void execute() {
	input(); solve();
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	while (!cin.eof()) {
		execute();
	}
#else
	execute();
#endif
}
// ......................................... //