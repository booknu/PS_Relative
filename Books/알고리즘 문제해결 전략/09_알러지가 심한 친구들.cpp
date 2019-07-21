/************
<�ּ�>		: p428
**********
<�ذ���>	:



**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �Է�
int n, m;
vector<vector<int>> edible; // food[food][i]: food�� ������ �� �Ǵ� ģ����

// �޸�
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
	foodNum�� �԰� ���� ���� ģ������ bitmask�� ��ȯ

	@param r_friend ���� ģ������ bitmask
	@param foodNum ���� ����
	@return r_friend �� foodNum�� �԰� ������ �� ���� ģ������ bitmask
*/
int getRemainFriend(int r_friend, int foodNum) {
	for (int i = 0; i < edible[foodNum].size(); i++) {
		r_friend = setBit(edible[foodNum][i], false, r_friend);
	}
	return r_friend;
}

/*
	@param r_friend �����ִ� ģ���� bitmask
	@param used ����� ������ bitmask
	@param prevFood ������ ���� ����
*/
void mySearch(int r_friend, int used, int prevFood) {
	// pruning
	if (bitcount(used) >= best) {
		return;
	}

	// base case: ��� ģ���� ������ ����
	if (r_friend == 0) {
		best = min(best, bitcount(used));
		return;
	}

	// �����ִ� ���ĵ��� �Ծ
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
		vector<string> friends(n); // ģ���� �̸�
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