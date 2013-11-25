#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

double dp[101][101][1001];

int toInt(double x) {
    return (int)(x * 1000.0 + 0.5);
}

void solve() {
    int n;
    cin >> n;
    double ps, pr, pi, pu, pw, pd, pl;
    cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    int ppu = toInt(pu), ppi = toInt(pi), ppd = toInt(pd);

    memset(dp, 0, sizeof(dp));

    dp[0][0][ppi] = 1.0;
    double res = 0.0;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            for (int psun = 0; psun <= 1000; psun ++) {
                double win = ps * psun / 1000.0 + pr * (1 - psun / 1000.0);
                // win
                dp[x + 1][y][min(psun + ppu, 1000)] += dp[x][y][psun] * pw * win;
                dp[x + 1][y][psun] += dp[x][y][psun] * (1 - pw) * win;
                // lose
                dp[x][y + 1][max(psun - ppd, 0)] += dp[x][y][psun] * pl * (1 - win);
                dp[x][y + 1][psun] += dp[x][y][psun] * (1 - pl) * (1 - win);
            }
    for (int i = 0; i < n; i++) for (int j = 0; j <= 1000; j++) res += dp[n][i][j];
    printf(" %.6lf\n", res);
}

int main() {
    //freopen("tennison.in", "r", stdin);
    //freopen("tennison.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        printf("Case #%d:", test);
        solve();
    }
    return 0;
}
