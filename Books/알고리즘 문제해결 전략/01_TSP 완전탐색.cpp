/************
<�ּ�>		: p403
**********
<�ذ���>	:

����Ž��

**********
<�����Ʈ>	:

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

// ���α׷� �Է� ����
int n; // ���� ��
double dist[MAX][MAX];
double best;

// �Լ�
/*
	���ǿ� ��ȸ ���� Ž��
	����� best�� �����

	@param path ������� ���� ���
	@param visited �ش� ������ �湮�ߴ���?
	@param currLength ������� ������� ����� ����ġ ��
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
	// false�� ���� ������ n���� ���Ҹ� ���� vector ����
	vector<bool> visited(n, false);
	// 0�� ���� ������ 1���� ���Ҹ� ���� vector ����
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}

// main �Լ�
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	cout << solve() << endl;
}