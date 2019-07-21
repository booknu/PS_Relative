/************
<주소>		: p428
**********
<해결방안>	:



**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 입력
int n, m;
vector<vector<int>> edible; // food[food][i]: food를 먹으면 안 되는 친구들

// 메모
int best;

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

int bitcount(int n) {
	int i;
	for (i = 0; n != 0; i++) {
		n &= (n - 1);
	}
	return i;
}

/*
	foodNum을 먹고도 먹지 못한 친구들의 bitmask를 반환

	@param r_friend 남은 친구들의 bitmask
	@param foodNum 먹을 음식
	@return r_friend 중 foodNum을 먹고 나서도 못 먹은 친구들의 bitmask
*/
int getRemainFriend(int r_friend, int foodNum) {
	for (int i = 0; i < edible[foodNum].size(); i++) {
		r_friend = setBit(edible[foodNum][i], false, r_friend);
	}
	return r_friend;
}

/*
	@param r_friend 남아있는 친구의 bitmask
	@param used 사용한 음식의 bitmask
	@param prevFood 이전에 먹은 음식
*/
void mySearch(int r_friend, int used, int prevFood) {
	// pruning
	if (bitcount(used) >= best) {
		return;
	}

	// base case: 모든 친구가 음식을 먹음
	if (r_friend == 0) {
		best = min(best, bitcount(used));
		return;
	}

	// 남아있는 음식들을 먹어봄
	for (int foodNum = prevFood + 1; foodNum < m; foodNum++) {
		if (!getBit(foodNum, used)) {
			mySearch(getRemainFriend(r_friend, foodNum), setBit(foodNum, true, used), foodNum);
		}
	}
}

int solve() {
	best = 987654321;

	mySearch((1 << n) - 1, 0, -1);
	return best;
}

int main(void) {
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		cin >> n >> m;
		vector<string> friends(n); // 친구들 이름
		for (int i = 0; i < n; i++) {
			cin >> friends[i];
		}

		edible.clear();
		edible.resize(m);
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			edible[i] = vector<int>(num);
			for (int j = 0; j < num; j++) {
				string name;
				cin >> name;
				for (int iter = 0; iter < friends.size(); iter++) {
					if (friends[iter] == name) {
						edible[i][j] = iter;
					}
				}
			}
		}
		
		cout << solve() << endl;
	}
}