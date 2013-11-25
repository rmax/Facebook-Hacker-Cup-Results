// Powered by SAM
#include <algorithm>
#include <cstdio>
#include <cstring>

const int kMaxTurns = 100;
const int kPLimit = 1000;

double g_table[kMaxTurns + 1][kMaxTurns + 1][kPLimit + 1];

double Solve(int k, double ps, double pr, int pi, int pu, double pw, int pd, double pl) {
  // Dirty hack, depends on IEEE 854. 
  memset(g_table, 0, sizeof(g_table));

  for (int i = 0; i <= k; ++i) {
    for (int p = 0; p <= kPLimit; ++p)
      g_table[k][i][p] = 1.0;
  }
  for (int i = k - 1; i >= 0; --i) {
    for (int j = k - 1; j >= 0; --j) {
      for (int p = 0; p <= kPLimit; ++p) {
        double pwin = ((double) p / kPLimit) * ps + (1.0 - (double) p / kPLimit) * pr;
        double a = pwin * (g_table[i + 1][j][std::min(p + pu, kPLimit)] * pw + g_table[i + 1][j][p] * (1.0 - pw));
        double b = (1.0 - pwin) * (g_table[i][j + 1][std::max(p - pd, 0)] * pl + g_table[i][j + 1][p] * (1.0 - pl));
        g_table[i][j][p] = a + b;
      }
    }
  }
  return std::max(std::min(g_table[0][0][pi], 1.0), 0.0);
}

int main() {
  int num_tests;
  scanf("%d", &num_tests);
  for (int test_num = 1; test_num <= num_tests; ++test_num) {
    int k;
    double ps, pr, pi, pu, pw, pd, pl;
    scanf("%d%lf%lf%lf%lf%lf%lf%lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
    double r = Solve(k, ps, pr, (int) (pi * kPLimit), (int) (pu * kPLimit), pw, (int) (pd * kPLimit), pl);
    printf("Case #%d: %.6lf\n", test_num, r);
  }
  return 0;
}