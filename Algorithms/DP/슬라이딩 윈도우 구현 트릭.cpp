int dp[MAXJ]; // 현재 dp
int pdp[MAXJ]; // 이전 dp
int main() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			// must be initialized!
			dp[j] = INIT;
			// DO SOME DP Calculation
			// .... //
		}
		// move dp values
		for(int j = 0; j < m; ++j) pdp[j] = dp[j];
	}
	return 0;
}