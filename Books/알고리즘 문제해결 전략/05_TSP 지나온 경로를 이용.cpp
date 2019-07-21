/************
<�ּ�>		: p412
**********
<�ذ���>	:

[[ �� �� ]]
���� ��ġ, �����ִ� ���õ��� ���� �� ��������� ��δ� �پ��� �� �ִµ�,
�� �� ��������� ����� ���̰� �� ª���� �ִٸ�, �װͺ��� �� ���� �� �̻� Ž������ �ʾƵ� �ȴ�.
==> ������ ��θ� �̿�!
==> �ٲ�� ���ô� a, b

[[ pathSwapPruning ]]
��� (... p a b q)�� (... p b a q)�� ������� �� ª�������� Ȯ��
==> �� ������ ���� 4������ Ȯ��
==> �� ���ø� ��ο� �߰��� ������ ����ǹǷ�
	�� ������ ���� 4���� ���ؼ��� �����ص� �ȴ�.

[[ pathReversePruning ]]
pathSwapPruning�� Ȯ�� ��������, ��� �� ������ ���� 4�� �� �ƴ϶�
������ ��쵵 ��� Ȯ�� �� �� �ִ�.

��� (... p a ... b q)�� (... p b ... a q)�� ������� �� ª�������� Ȯ��
==> pathSwapPruning�� �����Ѵ�.
==> �� ���ø� ��ο� �߰��� ������ ����ǹǷ�
	b q�� ������ ���� 2���� �ص� �ȴ�. 

[[ ȿ �� ]]
pathSwapPruning�� �����ϴ� ��θ� ������ �ʰ� ���ش�.
2���� TSP���� �����ϴ� ��θ� �����ϸ� ������ �ƴϴ�.
��, �����ϴ� ���� �ִ����� ��ȯ�ϴ� �Ͱ� ����.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
using namespace std;

const double INF = 1e200;
const int MAX = 30;

// ���α׷� �Է� ����
int n; // ���� ��
double dist[MAX][MAX];

// �޸������̼�
double best;
double minEdge[MAX]; // minEdge[i]: i�� ������ ���� �� ���� ª�� ��
vector<int> nearest[MAX];

// �Լ�
/*
	path�� ������ �� �� ���� �� ��� �ִ� �� ������ ������ �ٲ��� ��
	��ΰ� �� ª��������?
	ex) ��� ... p a b q �� ���� �� ... p b a q ���� �ٲ��� �� ��������� ��ΰ� �� ª��������?  

	@param path ������� ���	
	@return �� ª�� ��ΰ� �ִ���?
*/
bool pathSwapPruning(const vector<int> &path) {
	if (path.size() < 4) {
		return false;
	}
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	// ���Ī �׷����� ó���ϱ� ���ؼ��� map[a][b], map[b][a]�� ó������� ��!
	return dist[p][a] + dist[a][b] + dist[b][q] > dist[p][b] + dist[b][a] + dist[a][q];
}

/*
	���� ���ÿ� ���� ���ø� ������ path�� �κ� ��θ�
	������� �� ª�������� Ȯ��
	(pathSwapPruning Ȯ��)

	��� [... p a ... b q]�� [... p b ... a q]�� ������ �� 

	@param path ��������� ���
	@return �� ª�� ��ΰ� �ִ���?
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

		// ���Ī �׷��� ó����
		int beforeSwapBetween = 0;
		int afterSwapBetween = 0;
		if (afterA != b && beforeB != a) {
			beforeSwapBetween += dist[a][afterA] + dist[beforeB][b];
			afterSwapBetween += dist[b][afterA] + dist[beforeB][a];
		} else {
			beforeSwapBetween = dist[a][b];
			afterSwapBetween = dist[b][a];
		}

		// ��ΰ� ª�������� Ȯ��
		if (dist[p][a] + beforeSwapBetween + dist[b][q]
				> dist[p][b] + afterSwapBetween + dist[a][q]) {
			return true;
		}
	}
	return false;
}

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
		int next = nearest[here][i]; // ����� �������� �湮
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

	// nearest �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> order; // i�� ����� ��� ���� (����ġ, ����)
		for (int j = 0; j < n; j++) {
			if (i != j) {
				order.push_back(make_pair(dist[i][j], j));
			}
		}
		sort(order.begin(), order.end()); // ����ġ�� �������� sort
		nearest[i].clear();
		for (int j = 0; j < order.size(); j++) {
			nearest[i].push_back(order[j].second); // i�� ����� ��� ������ ����� ������ ��
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