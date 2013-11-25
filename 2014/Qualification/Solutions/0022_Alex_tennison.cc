#include <iostream>
#include <vector>
using namespace std;

double M[105][105][105][105][3];

int k;
double ps, pr, pi, pu, pw, pd, pl;

double dp(int k1, int k2, int inc, int dec, int m) {
  if (k1 == 0) return 1.0;
  if (k2 == 0) return 0.0;

  double& ans = M[k1][k2][inc][dec][m];
  if (ans < -1) {
    
    double psun = 0;
    if (m == 0) psun = pi + pu*inc - pd*dec;
    else if (m == 1) psun = 1 + pu*inc - pd*dec;
    else psun = pu*inc - pd*dec;

    ans = 0;

    //Sun win with inc
    ans += psun*ps*pw*(psun + pu > 1 ? dp(k1 - 1, k2, 0, 0, 1) : dp(k1 - 1, k2, inc + 1, dec, m));

    //Sun win without inc
    ans += psun*ps*(1.0 - pw)*dp(k1 - 1, k2, inc, dec, m);

    //Sun lose with dec
    ans += psun*(1.0 - ps)*pl*(psun - pd < 0 ? dp(k1, k2 - 1, 0, 0, 2) : dp(k1, k2 - 1, inc, dec + 1, m));

    //Sun lose without dec
    ans += psun*(1.0 - ps)*(1.0 - pl)*dp(k1, k2 - 1, inc, dec, m);

    //Rain win with inc
    ans += (1.0 - psun)*pr*pw*(psun + pu > 1 ? dp(k1 - 1, k2, 0, 0, 1) : dp(k1 - 1, k2, inc + 1, dec, m));

    //Rain win without inc
    ans += (1.0 - psun)*pr*(1.0 - pw)*dp(k1 - 1, k2, inc, dec, m);

    //Rain lose with dec
    ans += (1.0 - psun)*(1.0 - pr)*pl*(psun - pd < 0 ? dp(k1, k2 - 1, 0, 0, 2) : dp(k1, k2 - 1, inc, dec + 1, m));

    //Rain lose without dec
    ans += (1.0 - psun)*(1.0 - pr)*(1.0 - pl)*dp(k1, k2 - 1, inc, dec, m);
  }
  return ans;
}

void solve() {
  cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
  for (int i = 0; i < 105; ++i)
    for (int j = 0; j < 105; ++j) 
      for (int h = 0; h < 105; ++h)
        for (int l = 0; l < 105; ++l)
          for (int t = 0; t < 3; ++t)
            M[i][j][h][l][t] = -2;
  cout << dp(k, k, 0, 0, 0) << endl;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(6);
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
