/************
<주소>		: p402 내 방식의 TSP
**********
<해결방안>	:

**********
<오답노트>	:

1. 길이 없는 경우 예외 처리를 까먹음

2. 시작한 곳으로 돌아와야 하는 것을 까먹음
   (allVisited -> 0 으로 돌아오는데 걸리는 비용 빼먹음)

3. memo 초기화 안 함
   allVisited 초기화 실수

*/

#include <iostream>
using namespace std;

int N;
int graph[20][20];
int memo[1 << 20][20];
int allVisited;
const int INF = 17000000;

/**
* set mask bit to value (true = 1, false = 0)
*
* @param n n bit
* @param value true = 1, false = 0
* @param mask mask
* @return changed mask
*/
int setBit(int n, bool value, int mask) {
	if (value) {
		return mask | (1 << n);
	} else {
		return mask & (~(1 << n));
	}
}

/**
* get mask bit
*
* @param n n bit
* @param mask mask
* @return true / false
*/
int getBit(int n, int mask) {
	return mask & (1 << n);
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

int TSP(int visited, int curr) {
	// Base Case: All visited
	if (visited == allVisited) {
		if (graph[curr][0] == 0) {
			return INF;
		} else {
			return graph[curr][0]; // go to first node
		}
	}
	// memoization
	int &ret = memo[visited][curr];
	if (ret != -1) {
		return ret;
	}

	ret = INF;

	for (int i = 0; i < N; i++) {
		// visit only unvisited & has a path node
		if (!getBit(i, visited) && graph[curr][i] != 0) {
			ret = min(ret, TSP(setBit(i, true, visited), i) + graph[curr][i]);
		}
	}

	return ret;
}

int main() {
	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	// initialize
	allVisited = (1 << N) - 1;
	for (int i = 0; i <= allVisited; i++) {
		for (int j = 0; j < N; j++) {
			memo[i][j] = -1;
		}
	}

	// do
	cout << TSP(setBit(0, true, 0), 0) << endl;

	return 0;
}