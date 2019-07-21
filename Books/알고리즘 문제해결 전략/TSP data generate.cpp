#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int n = 20;
const int MAX = 50;
void generate() {
	srand(time(NULL));

	int map[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = rand() % MAX + 1;
		}
	}

	// print map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(void) {
	generate();
}