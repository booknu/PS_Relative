#include<bits/stdc++.h>

using namespace std;

#define maxn 300010
int n, m;
long long k;
long long a[maxn];
long long s[maxn];
long long dp[maxn][15];
long long b[maxn][15];

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	s[0] = 0;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = s[i + j - 1] - s[i - 1] - k;
	long long res = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int bd = i - j + 1;
			if (bd < 1) continue;
			dp[i][j] = max(1LL * 0, b[bd][j]);
			for (int t = 1; t <= m; t++)
			{
				if (t + j <= m) continue;
				int bd1 = (bd - 1) - t + 1;
				if (bd1 < 0) continue;
				//    cout << bd - 1 << " " << t << " " << dp[bd - 1][t] << endl;
				dp[i][j] = max(dp[i][j], dp[bd - 1][t] + b[bd][j]);
			}
			res = max(res, dp[i][j]);
		}
	cout << res;
	return 0;
}