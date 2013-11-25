#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int T, K;
double ps, pr, pi, pu, pw, pd, pl, dp[128][128][1024];

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %lf %lf %lf %lf %lf %lf %lf", &K, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
		dp[0][0][(int)(pi * 1000)] = 1;
		for (int w = 0; w < K; w++)
			for (int l = 0; l < K; l++)
				for (int p = 0; p <= 1000; p++) {
					double pc = p / 1000.0;
					dp[w + 1][l][p] += dp[w][l][p] * (ps * pc + pr * (1 - pc)) * (1 - pw);
					dp[w + 1][l][min(1000, (int)(p + pu * 1000))] += dp[w][l][p] * (ps * pc + pr * (1 - pc)) * pw;
					dp[w][l + 1][p] += dp[w][l][p] * ((1 - ps) * pc + (1 - pr) * (1 - pc)) * (1 - pl);
					dp[w][l + 1][max(0, (int)(p - pd * 1000))] += dp[w][l][p] * ((1 - ps) * pc + (1 - pr) * (1 - pc)) * pl;
				}
		double ans = 0;
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < 1024; k++)
				ans += dp[K][j][k];
		}
		printf("Case #%d: %lf\n", i, ans);
	}
	return 0;
}
