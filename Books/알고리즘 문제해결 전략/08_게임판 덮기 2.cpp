/************
<주소>		: p422
**********
<해결방안>	:

1. 블럭이 회전할 수 있는 경우를 rotations에 넣어놓는다.

2. 맨 윗줄부터 빈 칸을 찾아 블럭을 놓는데,
   현재 칸에 블럭을 놓고 재귀호출을 하는 경우와
   블럭을 놓지 않고 재귀호출을 하는 경우가 있다.

   블럭을 놓지 않는 경우는 covered[y][x]를 1로 만들어 막아놓는다.

3. 답을 과대평가하는 휴리스틱 알고리즘을 이용하여,
   현재 상태에서 아무리 잘 놓아도 best를 넘을 수 없으면 탐색을 중지

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;

// 기본 입력
int H, W, R, C; // H, W: 보드 크기	R, C: 블록 크기
vector<string> board;
vector<string> block;

// 메모이제이션
vector<vector<pair<int, int>>> rotations; // 각 블록 회전된 상태 저장
int blockSize;
int covered[10][10]; // 게임판의 각 칸이 덮였는지? 1: 검은칸 or 덮은칸 0: 빈 칸 
int best;

/*
	시계방향으로 90도 회전
	@param arr 회전할 블럭
	@return 회전된 블럭
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
	block의 네 가지 회전 형태를 만들고, 이들을 좌표의 목록으로 반환
	(각 좌표는 block이 존재하는 곳)
	@param block 블록 모양
*/
void generateRotation(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++) {
		int orgY = -1, orgX = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[i].size(); j++) {
				if (block[i][j] == '#') {
					// 맨 윗줄 맨 왼쪽 블럭이 원점 (0, 0)
					if (orgY == -1) {
						orgY = i;
						orgX = j;
					}
					rotations[rot].push_back(make_pair(i - orgY, j - orgX));
				}
			}
		}
		// 블록 회전 후 다시 loop
		block = rotate(block);
	}
	// 네 가지 회전 형태 중 중복이 있으면 제거
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	
	blockSize = rotations[0].size();
}

/**
 * 보드를 덮거나, 덮었던걸 지운다.
 *
 * @param y 현재 y좌표
 * @param x 현재 x좌표
 * @param block 덮을 블록
 * @param delta 1: 덮음, -1: 없앰
 * @return 게임판으로 나가거나, 겹치거나, 검은 칸을 덮을 때 false
 */
bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
	bool ret = true;
	for (int i = 0; i < blockSize; i++) {
		int ny = y + block[i].first;
		int nx = x + block[i].second;
		// 범위를 벗어나면
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
			ret = false;
		} else if((covered[ny][nx] += delta) > 1) {
			ret = false;
		}
	}
	return ret;
}

/*
	단순히 (빈 칸 / 블럭크기)를 통하여 얼마나 블럭이 들어갈 수 있을지 예상한다.
	@param board 현재 board 상태
	@return 블럭이 최대 몇 개 들어갈 수 있을지?
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
	완전 탐색
	@param placed 지금까지 놓은 블럭 수
*/
void search(int placed) {
	// pruning: 아무리 잘 배치해도 best보다 많이 놓을 수 없음
	if (placed + heuristic() <= best) {
		return;
	}

	// 처음 나오는 빈 칸 찾기
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			// 빈 칸을 찾음
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				goto findEmpty;
			}
		}
	}
findEmpty:

	// base case: 빈 칸 못 찾음
	if (y == -1) {
		best = max(best, placed);
		return;
	}

	for (int i = 0; i < rotations.size(); i++) {
		// 이 칸 덮고 다음 재귀호출
		if (set(y, x, rotations[i], 1)) {
			search(placed + 1);
		}
		// 덮은 것 제거
		set(y, x, rotations[i], -1);
	}

	covered[y][x] = 1; // 이 칸을 덮지 말고 막아둔다.
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