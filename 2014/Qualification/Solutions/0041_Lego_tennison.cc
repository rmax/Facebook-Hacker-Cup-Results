#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int K = 100;

double ps, pr, pw, pl;
int pi, pu, pd;
int k;

bool known[K][K][1001];
double dp[K][K][1001];

int get(const string& s) {
  int a, b;
  sscanf(s.c_str(), "%d.%d", &a, &b);
  return a * 1000 + b;
}

double go(int w, int l, int p) {
  if (w == k) return 1;
  if (l == k) return 0;

  double& ret = dp[w][l][p];
  if (known[w][l][p]) return ret;
  known[w][l][p] = true;

  ret = (p * ps     * pw     + (1000-p) * pr     * pw)     * go(w+1, l,   min(1000, p+pu)) +
        (p * ps     * (1-pw) + (1000-p) * pr     * (1-pw)) * go(w+1, l,   p) +
        (p * (1-ps) * pl     + (1000-p) * (1-pr) * pl)     * go(w,   l+1, max(0, p-pd)) +
        (p * (1-ps) * (1-pl) + (1000-p) * (1-pr) * (1-pl)) * go(w,   l+1, p);
  ret /= 1000;
  return ret;
}

int main() {
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    string spi, spu, spd;
    cin >> k >> ps >> pr >> spi >> spu >> pw >> spd >> pl;
    pi = get(spi);
    pu = get(spu);
    pd = get(spd);
    memset(known, false, sizeof(known));
    printf("Case #%d: %.6f\n", tt, go(0, 0, pi));
  }
  return 0;
}
