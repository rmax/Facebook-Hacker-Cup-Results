#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

double dp[205][105][1005];

#define p_win(p) ((p) * ps + (1 - (p)) * pr)

int main(int argc, char* argv[]) {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++ t) {
    int K;
    cin >> K;

    double ps, pr, pu, pw, pd, pl, pi;
    cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

    int _pi = pi * 1000;
    int _pu = pu * 1000;
    int _pd = pd * 1000;

    memset(dp, 0, sizeof(dp));

    dp[0][0][_pi] = 1;
    for (int n = 0; n < 2 * K - 1; ++ n) {
      for (int k = 0; k <= n && k < K; ++ k) {
        for (int p = 0; p <= 1000; ++ p) {
          if (dp[n][k][p] <= 0) continue;

          dp[n + 1][k + 1][p] +=
              dp[n][k][p] * p_win(p/1000.) * (1 - pw);

          dp[n + 1][k][p] +=
              dp[n][k][p] * (1 - p_win(p/1000.)) * (1 - pl);

          int q;

          q = min(1000, p + _pu);
          dp[n + 1][k + 1][q] +=
              dp[n][k][p] * p_win(p/1000.) * pw;

          q = max(0, p - _pd);
          dp[n + 1][k][q] +=
              dp[n][k][p] * (1 - p_win(p/1000.)) * pl;
        }
      }
    }

    double ans = 0;
    for (int n = K; n <= 2 * K - 1; ++ n) {
      for (int p = 0; p <= 1000; ++ p) {
        ans += dp[n][K][p];
      }
    }

    cout << "Case #" << t << ": " << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}

