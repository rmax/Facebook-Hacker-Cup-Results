#include <cstdio>

// (num wins, num losses, type, num wins with increase, num losses with decrease)
long double dp[105][105][3][105][105];
#define FROM_START 0
#define FROM_0 1
#define FROM_1 2

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int Z;
		scanf("%d", &Z);
		long double ps, pr, pi, pu, pw, pd, pl;
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf", &ps, &pr, &pi, &pu, &pw, &pd, &pl);
		for (int i = 0; i < Z; i++) {
			for (int j = 0; j < Z; j++) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l <= i; l++) {
						for (int m = 0; m <= j; m++) {
							dp[i][j][k][l][m] = 0.0;
						}
					}
				}
			}
		}

		dp[0][0][0][0][0] = 1.0;
		long double ans = 0.0;
		for (int i = 0; i < Z; i++) {
			for (int j = 0; j < Z; j++) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l <= i; l++) {
						for (int m = 0; m <= j; m++) {
							long double psun = (k == FROM_START ? pi : (k == FROM_0 ? 0 : 1.0)) + l*pu - m*pd;
							long double pwin = dp[i][j][k][l][m] * (psun * ps + (1-psun) * pr);
							long double plose = dp[i][j][k][l][m] - pwin;
							dp[i+1][j][k][l][m] += pwin * (1 - pw);
							dp[i][j+1][k][l][m] += plose * (1 - pl);

							int k1, l1, m1;
							if (psun + pu >= 1.0) {
								k1 = FROM_1;
								l1 = 0;
								m1 = 0;
							} else {
								k1 = k;
								l1 = l + 1;
								m1 = m;
							}
							dp[i+1][j][k1][l1][m1] += pwin * pw;

							int k2, l2, m2;
							if (psun - pd <= 0.0) {
								k2 = FROM_0;
								l2 = 0;
								m2 = 0;
							} else {
								k2 = k;
								l2 = l;
								m2 = m + 1;
							}
							dp[i][j+1][k2][l2][m2] += plose * pl;

							if (i+1 == Z) {
								ans += pwin;
							}

						}
					}
				}
			}
		}

		/*
		long double ans = 0.0;
		for (int k = 0; k < 3; k++) {
			for (int l = 0; l <= 2*Z - 1; l++) {
				for (int m = 0; m+l <= 2*Z-1; m++) {
					ans += dp[Z][Z-1][k][l][m];
				}
			}
		}
		*/

		printf("Case #%d: %Lf\n", t, ans);
	}
}
