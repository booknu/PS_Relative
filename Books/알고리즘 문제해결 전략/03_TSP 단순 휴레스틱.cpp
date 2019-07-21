/************
<�ּ�>		: p408
**********
<�ذ���>	:

[[ �⺻ ���� ]]
currLength + heuristic(remain) > bestLength �̸� �Ÿ��� ������ �ذ�
��, heuristic(remain)�� �����غ��� ū ���̸� �����ظ� �ɷ������� ���� �߻�.
����, "heuristic(remain) < ������"�� �������Ѿ� �̷� ��츦 ������ �� ���� (Optimistic Heuristic)
����, �� ���ǿ� �´� �� �� ������ ū ���� ã�� �� �־�� ���� ��츦 �Ÿ� �� ����

[[ Heuristic ��� ]]
1. "���� ���� �� ���� �ָ� �ִ� ���� + ������" ���� ���ص� ��
2. ���� ���õ��� �湮�ϴ� ����� �Ϸķ� ����� ���°� �ƴϾ ��

[[ ������ Heuristic ]]
���� �湮�������� Vr �̶�� �ϸ�,
Vr�� ����� ���� ª�� �������� ���� ���ϸ�,
�����غ��ٴ� ������ �۰�, �׷����� ū ���� ���� �� ����!

[[ �� �� ]]
Heuristic:	���迡 �ǰ��� ����Ǯ�� (����� ����۰� ���)
			���� �׻� �����ظ� �������� ��������, ������� ���ǿ� ����� ���� ã�� �� ����

Optimistic Heuristic:	�����غ��� "������"�ؼ� ���� ����

**********
<�����Ʈ>	:

1. ������ ����ġ�� ���Ī�� �ڷḦ ����� �׽�Ʈ �ߴµ�,
   minEdge���� �ʱ�ȭ �� �� map[i][j]���� �� �� �ƴ϶�
   map[j][i]���� �񱳵� �߰��ؾ� ���Ī �׷����� ���� ó���� �� �ִ�.


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

// �޸������̼�
double best;
double minEdge[MAX]; // minEdge[i]: i�� ������ ���� �� ���� ª�� ��

// �Լ�
/*
	���� �ܼ��� �޷���ƽ

	���� �湮�������� Vr �̶�� �ϸ�,
	Vr�� ����� ���� ª�� �������� ���� ���ϸ�,
	�����غ��ٴ� ������ �۰�, �׷����� ū ���� ���� �� ����!

	@param visited �ش� ������ �湮�ߴ���?
*/
double simpleHeuristic(vector<bool> &visited) {
	double ret = minEdge[0]; // �������� ���������� ���ư� �� ����� ����
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ret += minEdge[i];
		}
	}
	return ret;
}

/*
	���ǿ� ��ȸ ���� Ž��
	����� best�� �����

	@param path ������� ���� ���
	@param visited �ش� ������ �湮�ߴ���?
	@param currLength ������� ������� ����� ����ġ ��
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
	// search �Լ��� ���� �ʱ�ȭ
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	
	// simpleHeuristic �Լ��� ���� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		// i�� ����� ���� �� ���� ª�� ���� ���س���
		minEdge[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				minEdge[i] = min(minEdge[i], dist[i][j]);
				minEdge[i] = min(minEdge[i], dist[j][i]); // ���Ī �׷����� ó���ϱ� ����
			}
		}
	}

	// search ����
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