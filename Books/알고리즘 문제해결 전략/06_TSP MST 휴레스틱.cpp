/************
<�ּ�>		: p414
**********
<�ذ���>	:


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
vector<pair<double, pair<int, int>>> edges; // ��� ���� �� edge�� ���� ������ ����

class DisjointSet {
private:
	vector<int> parent; // �� ������ �θ� ��� ��ȣ

public:
	/*
	n���� ���Ұ� ������ ���տ� ���ԵǴ� DisjointSet ����
	@param n �� ���� ����?
	*/
	DisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	/*
	u�� ���� ������ root ��ȯ
	@param u ã�� ����
	@return u�� ���� ������ root
	*/
	int find(int u) const {
		// base case: root�� ã��
		// (root�� root�� parent�� ����!)
		if (u == parent[u]) {
			return u;
		}
		// recursive search
		return find(parent[u]);
	}

	/*
	u�� ���� ���տ� v�� ���� ������ ��ģ��.
	@param u ����
	@param v ����
	@return u, v�� root�� �޶� ��ġ�µ� �����ߴ���?
	*/
	bool merge(int u, int v) {
		// ������ root�� ã��
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
	path�� ������ �� �� ���� �� ��� �ִ� �� ������ ������ �ٲ��� ��
	��ΰ� �� ª��������?
	ex) ��� ... p a b q �� ���� �� ... p b a q ���� �ٲ��� �� ��������� ��ΰ� �� ª��������?

	@param path ������� ���
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
	here, ������, �湮���� ���� ���õ��� ��� �����ϴ� MST ã��
	(DisjointSet�� Ȱ���� ũ�罺Į �˰���)

	@param here ���� ����
	@param visited �湮�� ����
*/
double mstHeuristic(int here, const vector<bool>& visited) {
	DisjointSet sets(n);
	double taken = 0;
	// ����ġ�� ���� �� ���� �����غ�
	for (int i = 0; i < edges.size(); i++) {
		// ����� ����
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

	// edges �ʱ�ȭ, ����
	edges.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int weight = min(dist[i][j], dist[j][i]);
			edges.push_back(make_pair(weight, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());

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