/************
<주소>		: p414
**********
<해결방안>	:


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
vector<pair<double, pair<int, int>>> edges; // 모든 도시 간 edge를 길이 순으로 정렬

class DisjointSet {
private:
	vector<int> parent; // 각 원소의 부모 노드 번호

public:
	/*
	n개의 원소가 각각의 집합에 포함되는 DisjointSet 생성
	@param n 몇 개의 원소?
	*/
	DisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	/*
	u가 속한 집합의 root 반환
	@param u 찾을 원소
	@return u가 속한 집합의 root
	*/
	int find(int u) const {
		// base case: root를 찾음
		// (root는 root가 parent인 구조!)
		if (u == parent[u]) {
			return u;
		}
		// recursive search
		return find(parent[u]);
	}

	/*
	u가 속한 집합에 v가 속한 집합을 합친다.
	@param u 원소
	@param v 원소
	@return u, v의 root가 달라서 합치는데 성공했는지?
	*/
	bool merge(int u, int v) {
		// 각각의 root를 찾음
		u = find(u);
		v = find(v);

		if (u == v) {
			return false;
		} else {
			parent[v] = u;
			return true;
		}
	}

	int size() const {
		return parent.size();
	}
};

/*
	path의 마지막 네 개 도시 중 가운데 있는 두 도시의 순서를 바꿨을 때
	경로가 더 짧아지는지?
	ex) 경로 ... p a b q 이 있을 때 ... p b a q 으로 바꿨을 때 현재까지의 경로가 더 짧아지는지?

	@param path 현재까지 경로
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
	here, 시작점, 방문하지 않은 도시들을 모두 연결하는 MST 찾음
	(DisjointSet을 활용한 크루스칼 알고리즘)

	@param here 현재 정점
	@param visited 방문한 정점
*/
double mstHeuristic(int here, const vector<bool>& visited) {
	DisjointSet sets(n);
	double taken = 0;
	// 가중치가 작은 것 부터 연결해봄
	for (int i = 0; i < edges.size(); i++) {
		// 연결된 정점
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && visited[a]) continue;
		if (b != 0 && b != here && visited[b]) continue;
		if (sets.merge(a, b)) {
			taken += edges[i].first;
		}
	}
	return taken;
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

	// base case: all visited
	if (path.size() == n) {
		// return to start city
		best = min(best, currLength + dist[here][0]);
		return;
	}

	// base case: short path exist
	if (pathReversePruning(path)) {
		return;
	}

	// base case: currLength + heuristic >= best
	if (currLength + mstHeuristic(here, visited) >= best) {
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

	// edges 초기화, 정렬
	edges.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int weight = min(dist[i][j], dist[j][i]);
			edges.push_back(make_pair(weight, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());

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