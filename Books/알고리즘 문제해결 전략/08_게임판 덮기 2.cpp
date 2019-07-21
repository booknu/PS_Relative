/************
<�ּ�>		: p422
**********
<�ذ���>	:

1. ���� ȸ���� �� �ִ� ��츦 rotations�� �־���´�.

2. �� ���ٺ��� �� ĭ�� ã�� ���� ���µ�,
   ���� ĭ�� ���� ���� ���ȣ���� �ϴ� ����
   ���� ���� �ʰ� ���ȣ���� �ϴ� ��찡 �ִ�.

   ���� ���� �ʴ� ���� covered[y][x]�� 1�� ����� ���Ƴ��´�.

3. ���� �������ϴ� �޸���ƽ �˰����� �̿��Ͽ�,
   ���� ���¿��� �ƹ��� �� ���Ƶ� best�� ���� �� ������ Ž���� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;

// �⺻ �Է�
int H, W, R, C; // H, W: ���� ũ��	R, C: ��� ũ��
vector<string> board;
vector<string> block;

// �޸������̼�
vector<vector<pair<int, int>>> rotations; // �� ��� ȸ���� ���� ����
int blockSize;
int covered[10][10]; // �������� �� ĭ�� ��������? 1: ����ĭ or ����ĭ 0: �� ĭ 
int best;

/*
	�ð�������� 90�� ȸ��
	@param arr ȸ���� ��
	@return ȸ���� ��
*/
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}
	return ret;
}

/*
	block�� �� ���� ȸ�� ���¸� �����, �̵��� ��ǥ�� ������� ��ȯ
	(�� ��ǥ�� block�� �����ϴ� ��)
	@param block ��� ���
*/
void generateRotation(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++) {
		int orgY = -1, orgX = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[i].size(); j++) {
				if (block[i][j] == '#') {
					// �� ���� �� ���� ���� ���� (0, 0)
					if (orgY == -1) {
						orgY = i;
						orgX = j;
					}
					rotations[rot].push_back(make_pair(i - orgY, j - orgX));
				}
			}
		}
		// ��� ȸ�� �� �ٽ� loop
		block = rotate(block);
	}
	// �� ���� ȸ�� ���� �� �ߺ��� ������ ����
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	
	blockSize = rotations[0].size();
}

/**
 * ���带 ���ų�, �������� �����.
 *
 * @param y ���� y��ǥ
 * @param x ���� x��ǥ
 * @param block ���� ���
 * @param delta 1: ����, -1: ����
 * @return ���������� �����ų�, ��ġ�ų�, ���� ĭ�� ���� �� false
 */
bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
	bool ret = true;
	for (int i = 0; i < blockSize; i++) {
		int ny = y + block[i].first;
		int nx = x + block[i].second;
		// ������ �����
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
			ret = false;
		} else if((covered[ny][nx] += delta) > 1) {
			ret = false;
		}
	}
	return ret;
}

/*
	�ܼ��� (�� ĭ / ��ũ��)�� ���Ͽ� �󸶳� ���� �� �� ������ �����Ѵ�.
	@param board ���� board ����
	@return ���� �ִ� �� �� �� �� ������?
*/
int heuristic() {
	int empty = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (covered[i][j] == 0) {
				empty++;
			}
		}
	}
	return empty / blockSize;
}

/*
	���� Ž��
	@param placed ���ݱ��� ���� �� ��
*/
void search(int placed) {
	// pruning: �ƹ��� �� ��ġ�ص� best���� ���� ���� �� ����
	if (placed + heuristic() <= best) {
		return;
	}

	// ó�� ������ �� ĭ ã��
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			// �� ĭ�� ã��
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				goto findEmpty;
			}
		}
	}
findEmpty:

	// base case: �� ĭ �� ã��
	if (y == -1) {
		best = max(best, placed);
		return;
	}

	for (int i = 0; i < rotations.size(); i++) {
		// �� ĭ ���� ���� ���ȣ��
		if (set(y, x, rotations[i], 1)) {
			search(placed + 1);
		}
		// ���� �� ����
		set(y, x, rotations[i], -1);
	}

	covered[y][x] = 1; // �� ĭ�� ���� ���� ���Ƶд�.
	search(placed);
	covered[y][x] = 0;
}

int solve() {
	generateRotation(block);
	best = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}

	search(0);
	return best;
}

int main(void) {
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		cin >> H >> W >> R >> C;
		board.clear();
		board.resize(H);
		block.clear();
		block.resize(R);
		for (int i = 0; i < H; i++) {
			cin >> board[i];
		}
		for (int i = 0; i < R; i++) {
			cin >> block[i];
		}

		cout << solve() << endl;
	}
}