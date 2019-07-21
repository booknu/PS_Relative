/************
<주소>		: p403
**********
<해결방안>	:

완전탐색

**********
<오답노트>	:

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
double best;

// 함수
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
	best = INF;
	// false의 값을 가지는 n개의 원소를 가진 vector 생성
	vector<bool> visited(n, false);
	// 0의 값을 가지는 1개의 원소를 가진 vector 생성
	vector<int> path(1, 0);
	visited[0] = true;
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