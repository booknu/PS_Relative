/************
<주소>		: p412
**********
<해결방안>	:

[[ 원 리 ]]
현재 위치, 남아있는 도시들이 같을 때 현재까지의 경로는 다양할 수 있는데,
이 때 현재까지의 경로의 길이가 더 짧은게 있다면, 그것보다 긴 경우는 더 이상 탐색하지 않아도 된다.
==> 지나온 경로를 이용!
==> 바뀌는 도시는 a, b

[[ pathSwapPruning ]]
경로 (... p a b q)를 (... p b a q)로 뒤집어보고 더 짧아지는지 확인
==> 맨 마지막 도시 4개만을 확인
==> 한 도시를 경로에 추가할 때마다 실행되므로
	맨 마지막 도시 4개에 대해서만 수행해도 된다.

[[ pathReversePruning ]]
pathSwapPruning의 확장 버전으로, 비단 맨 마지막 도시 4개 뿐 아니라
나머지 경우도 모두 확인 할 수 있다.

경로 (... p a ... b q)를 (... p b ... a q)로 뒤집어보고 더 짧아지는지 확인
==> pathSwapPruning을 포함한다.
==> 한 도시를 경로에 추가할 때마다 실행되므로
	b q는 마지막 도시 2개로 해도 된다. 

[[ 효 과 ]]
pathSwapPruning은 교차하는 경로를 만들지 않게 해준다.
2차원 TSP에서 교차하는 경로를 포함하면 최적이 아니다.
즉, 교차하는 곳이 있는지를 반환하는 것과 같다.

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
	path의 마지막 네 개 도시 중 가운데 있는 두 도시의 순서를 바꿨을 때
	경로가 더 짧아지는지?
	ex) 경로 ... p a b q 이 있을 때 ... p b a q 으로 바꿨을 때 현재까지의 경로가 더 짧아지는지?  

	@param path 현재까지 경로	
	@return 더 짧은 경로가 있는지?
*/
bool pathSwapPruning(const vector<int> &path) {
	if (path.size() < 4) {
		return false;
	}
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	// 비대칭 그래프를 처리하기 위해서는 map[a][b], map[b][a]도 처리해줘야 함!
	return dist[p][a] + dist[a][b] + dist[b][q] > dist[p][b] + dist[b][a] + dist[a][q];
}

/*
	시작 도시와 현재 도시를 제외한 path의 부분 경로를
	뒤집어보고 더 짧아지는지 확인
	(pathSwapPruning 확장)

	경로 [... p a ... b q]를 [... p b ... a q]로 뒤집어 봄 

	@param path 현재까지의 경로
	@return 더 짧은 경로가 있는지?
*/
bool pathReversePruning(const vector<int> &path) {
	if (path.size() < 4) {
		return false;
	}
	int beforeB = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i < path.size() - 3; i++) {
		int p = path[i];
		int a = path[i + 1];
		int afterA = path[i + 2];

		// 비대칭 그래프 처리용
		int beforeSwapBetween = 0;
		int afterSwapBetween = 0;
		if (afterA != b && beforeB != a) {
			beforeSwapBetween += dist[a][afterA] + dist[beforeB][b];
			afterSwapBetween += dist[b][afterA] + dist[beforeB][a];
		} else {
			beforeSwapBetween = dist[a][b];
			afterSwapBetween = dist[b][a];
		}

		// 경로가 짧아졌는지 확인
		if (dist[p][a] + beforeSwapBetween + dist[b][q]
				> dist[p][b] + afterSwapBetween + dist[a][q]) {
			return true;
		}
	}
	return false;
}

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

	// base case: short path exist
	if (pathReversePruning(path)) {
		return;
	}

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