/************
<주소>		: p410
**********
<해결방안>	:
값이 작은 best를 빨리 찾으면 찾을수록 Heuristic을 통해 가지치기가 더 많이 된다.
따라서, 단순히 순서대로 다음 정점을 선택하는 것이 아닌, 가까운 정점을 먼저 방문하는 식으로 찾으면
어느정도 좋은 답을 빨리 찾을 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
using namespace std;

const double INF = 1e200;
const int MAX = 30;

// 프로그램 입력 변수
int n; // 도시 수
double dist[MAX][MAX];

// 메모이제이션
double best;
double minEdge[MAX]; // minEdge[i]: i의 인접한 간선 중 가장 짧은 것
vector<int> nearest[MAX];

// 함수
/*
	가장 단순한 휴레스틱

	남은 방문지점들을 Vr 이라고 하면,
	Vr에 연결된 가장 짧은 간선들의 합을 구하면,
	최적해보다는 무조건 작고, 그럭저럭 큰 값을 구할 수 있음!

	@param visited 해당 지점을 방문했는지?
*/
double simpleHeuristic(vector<bool> &visited) {
	double ret = minEdge[0]; // 마지막에 시작점으로 돌아갈 때 사용할 간선
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ret += minEdge[i];
		}
	}
	return ret;
}

/*
외판원 순회 완전 탐색
결과는 best에 저장됨

@param path 현재까지 만든 경로
@param visited 해당 지점을 방문했는지?
@param currLength 현재까지 만들어진 경로의 가중치 합
*/
void search(vector<int> &path, vector<bool> &visited, double currLength) {
	int here = path.back();

	// base case: currLength + heuristic >= best
	if (currLength + simpleHeuristic(visited) >= best) {
		return;
	}

	// base case: all visited
	if (path.size() == n) {
		// return to start city
		best = min(best, currLength + dist[here][0]);
		return;
	}

	// try all combination
	for (int i = 0; i < nearest[here].size(); i++) {
		int next = nearest[here][i]; // 가까운 정점부터 방문
		if (!visited[next]) {
			path.push_back(next);
			visited[next] = true;
			search(path, visited, currLength + dist[here][next]);
			path.pop_back();
			visited[next] = false;
		}
	}
}

double solve() {
	// search 함수를 위한 초기화
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;

	// simpleHeuristic 함수를 위한 초기화
	for (int i = 0; i < n; i++) {
		// i에 연결된 간선 중 가장 짧은 것을 구해놓음
		minEdge[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				minEdge[i] = min(minEdge[i], dist[i][j]);
				minEdge[i] = min(minEdge[i], dist[j][i]); // 비대칭 그래프를 처리하기 위함
			}
		}
	}

	// nearest 초기화
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> order; // i에 연결된 모든 간선 (가중치, 정점)
		for (int j = 0; j < n; j++) {
			if (i != j) {
				order.push_back(make_pair(dist[i][j], j));
			}
		}
		sort(order.begin(), order.end()); // 가중치를 기준으로 sort
		nearest[i].clear();
		for (int j = 0; j < order.size(); j++) {
			nearest[i].push_back(order[j].second); // i에 연결된 모든 간선이 가까운 순으로 들어감
		}
	}
	// search 실행
	search(path, visited, 0);

	return best;
}

// main 함수
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	cout << solve() << endl;
}