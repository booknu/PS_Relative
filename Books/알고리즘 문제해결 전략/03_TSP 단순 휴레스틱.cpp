/************
<주소>		: p408
**********
<해결방안>	:

[[ 기본 조건 ]]
currLength + heuristic(remain) > bestLength 이면 거르는 식으로 해결
단, heuristic(remain)이 최적해보다 큰 값이면 최적해를 걸러버리는 문제 발생.
따라서, "heuristic(remain) < 최적해"를 만족시켜야 이런 경우를 방지할 수 있음 (Optimistic Heuristic)
또한, 위 조건에 맞는 것 중 가능한 큰 값을 찾을 수 있어야 많은 경우를 거를 수 있음

[[ Heuristic 방법 ]]
1. "남은 도시 중 가장 멀리 있는 도시 + 시작점" 으로 평가해도 됨
2. 남은 도시들을 방문하는 방법이 일렬로 연결된 형태가 아니어도 됨

[[ 구현된 Heuristic ]]
남은 방문지점들을 Vr 이라고 하면,
Vr에 연결된 가장 짧은 간선들의 합을 구하면,
최적해보다는 무조건 작고, 그럭저럭 큰 값을 구할 수 있음!

[[ 단 어 ]]
Heuristic:	경험에 의거한 문제풀이 (사람의 어림짐작과 비슷)
			따라서 항상 최적해를 구하지는 못하지만, 어느정도 현실에 가까운 답을 찾을 수 있음

Optimistic Heuristic:	최적해보다 "과소평가"해서 답을 구함

**********
<오답노트>	:

1. 간선의 가중치가 비대칭인 자료를 사용해 테스트 했는데,
   minEdge들을 초기화 할 때 map[i][j]와의 비교 뿐 아니라
   map[j][i]와의 비교도 추가해야 비대칭 그래프에 대해 처리할 수 있다.


*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
inline T min(T a, T b) {
	return a < b ? a : b;
}

const double INF = 1e200;
const int MAX = 30;

// 프로그램 입력 변수
int n; // 도시 수
double dist[MAX][MAX];

// 메모이제이션
double best;
double minEdge[MAX]; // minEdge[i]: i의 인접한 간선 중 가장 짧은 것

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
	for (int next = 0; next < n; next++) {
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