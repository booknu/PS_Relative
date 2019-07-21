// 분석해봐야 됨
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;  typedef pair<ll, pi> plp;
typedef pair<int, pi> pip; typedef tuple<int, int, int> ti;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N; char S[MAX_N];
int SA[MAX_N], LCP[MAX_N];

void getSA() {
	int m = 500;
	vector<int> cnt(max(m, N)+1, 0), x(N+1, 0), y(N+1, 0); // x = ord, y = tmp
	for(int i = 1; i<=N; i++) cnt[x[i] = S[i]]++; // 첫 ord는 str을 이용해 만듬
	for(int i = 1; i<=m; i++) cnt[i] += cnt[i-1];
	for(int i = N; i>=1; i--) SA[cnt[x[i]]--] = i; // 첫(1을 이용한) 정렬 결과
	for(int len = 1, p = 0, i; p<N; len *= 2, m = p) {
		for(p = 0, i = N-len+1; i<=N; i++) y[++p] = i; // 두 번째 자리를 이용한 ordering
		for(i = 1; i<=N; i++) if(SA[i] > len) y[++p] = SA[i] - len;
		for(i = 1; i<=m; i++) cnt[i] = 0;
		for(i = 1; i<=N; i++) cnt[x[y[i]]]++;
		for(i = 1; i<=m; i++) cnt[i] += cnt[i-1];
		for(i = N; i>=1; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y);
		p = 1; x[SA[1]] = 1;
		for(i = 1; i<N; i++) {
			int a = SA[i], b = SA[i+1], al = SA[i] + len, bl = SA[i+1] + len;
			x[SA[i+1]] = (al <= N && bl <= N && y[a] == y[b] && y[al] == y[bl]) ? p : ++p;
		}
	}
}
void getLCP() {
	int i, j, k;
	vector<int> rk(N+1, 0);
	for(i = 1; i<=N; i++) rk[SA[i]] = i;
	for(i = 1, k = 0; i<=N; LCP[rk[i++]] = k)
		for((k ? k-- : 0), j = SA[rk[i]-1]; S[i+k] == S[j+k]; k++);
}

int main() {
	int TC; cin >> TC;
	while(TC--) {
		scanf("%s", S+1); N = strlen(S+1);
		getSA();
		getLCP();
		ll ans = 0;
		for(int i = 2; i<=N; i++) ans += max(0, LCP[i] - LCP[i-1]);
		printf("%lld\n", ans);
	}
	return 0;
}
