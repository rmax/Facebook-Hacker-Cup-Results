#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXK = 111;
const int MAXP = 1001;
int k;
int Ps, Pr, Pi, Pu, Pw, Pd, Pl;
double ps, pr, pi, pu, pw, pd, pl;
void input(int &P, double& p) {
  int a, b;
  scanf("%d.%d", &a, &b);
  P = a * 1000 + b;
  p = a + b / 1000.0; 
}
double dp[MAXK][MAXK][MAXP];
int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 0; T < cases; T++) {
    scanf("%d", &k);
    input(Ps, ps);
    input(Pr, pr);
    input(Pi, pi);
    input(Pu, pu);
    input(Pw, pw);
    input(Pd, pd);
    input(Pl, pl);
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < k; j++) {
      for (int i = 0; i < MAXP; i++) {
        dp[k][j][i] = 1.0;
      }
    }
    for (int i = k - 1; i >= 0; i--) {
      for (int j = k; j >= 0; j--) {
        for (int PI = 0; PI < MAXP; PI++) {
          double pI = PI / 1000.0;
          double sum = 0;
          double left = 1.0;
          sum += (pI * ps * pw + (1 - pI) * pr * pw) * dp[i + 1][j][min(1000, PI + Pu)];
          sum += (pI * ps * (1 - pw) + (1 - pI) * pr * (1 - pw)) * dp[i + 1][j][PI];
          sum += (pI * (1 - ps) * pl + (1 - pI) * (1 - pr) * pl) * dp[i][j + 1][max(0, PI - Pd)];
          sum += (pI * (1 - ps) * (1 - pl) + (1 - pI) * (1 - pr) * (1 - pl)) * dp[i][j + 1][PI];
          //printf("%d %.3lf %.3lf %.3lf %.3lf\n", i, (pI * ps * pw + (1 - pI) * pr * pw), (pI * ps * (1 - pw) + (1 - pI) * pr * (1 - pw)),  (pI * (1 - ps) * pl + (1 - pI) * (1 - pr) * pl),  (pI * (1 - ps) * (1 - pl) + (1 - pI) * (1 - pr) * (1 - pl)));
          //printf("%d %.3lf %.6lf %.6lf\n", i, pI, sum, left);
          dp[i][j][PI] = sum / left;
          /*dp[i][PI] = (pI * ps * pw + (1 - pI) * pr * pw) * dp[i + 1][min(1000, PI + Pu)];
            dp[i][PI] += (pI * ps * (1 - pw) + (1 - pI) * pr * (1 - pw)) * dp[i + 1][PI];
            dp[i][PI] += (pI * (1 - ps) * pl + (1 - pI) * (1 - pr) * pl) * dp[i][max(0, PI - Pd)];
            dp[i][PI] += (pI * (1 - ps) * (1 - pl) + (1 - pI) * (1 - pr) * (1 - pl)) * dp[i][PI];*/


        }
      }
    }
    printf("Case #%d: %.6lf\n", T + 1, dp[0][0][Pi]);
  }
}

