#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

class timer {
public:
  timer() : t_(clock()) {}
  void start() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

struct state {
  int w;
  int l;
  double p;
  state(int w_, int l_, double p_) {
    w = w_;
    l = l_;
    p = p_;
  }
  bool operator<(const state& that) const {
    if (w != that.w) return w < that.w;
    if (l != that.l) return l < that.l;
    return p < that.p;
  }
};
double outcomes[101][101][1001];
int k;
double ps, pr;
double pw, pl;
int pu, pd;

double eval(int w, int l, int pi) {
  if (w == k) return 1.0;
  if (l == k) return 0.0;
  double& res = outcomes[w][l][pi];
  if (res != -1) return res;
  res = pi * ps * pw * eval(w + 1, l, min(1000, pi + pu));
  res += pi * ps * (1.0 - pw) * eval(w + 1, l, pi);
  res += pi * (1.0 - ps) * pl * eval(w, l + 1, max(0, pi - pd));
  res += pi * (1.0 - ps) * (1.0 - pl) * eval(w, l + 1, pi);
  res += (1000 - pi) * pr * pw * eval(w + 1, l, min(1000, pi + pu));
  res += (1000 - pi) * pr * (1.0 - pw) * eval(w + 1, l, pi);
  res += (1000 - pi) * (1.0 - pr) * pl * eval(w, l + 1, max(0, pi - pd));
  res += (1000 - pi) * (1.0 - pr) * (1.0 - pl) * eval(w, l + 1, pi);
  res *= 0.001;
  return res;
}

int main() {
  int T; cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    for (int i = 0; i <= 100; ++i)
      for (int j = 0; j <= 100; ++j)
        for (int k = 0; k <= 1000; ++k)
          outcomes[i][j][k] = -1.0;
    double pi, u, d;
    cin >> k;
    cin >> ps >> pr;
    cin >> pi;
    cin >> u >> pw;
    cin >> d >> pl;
    pu = int(u * 1000 + 1E-3);
    pd = int(d * 1000 + 1E-3);
    cout << "Case #" << tt + 1 << ": ";
    printf("%.6f", eval(0, 0, int(pi * 1000 + 1E-3)));
    cout << endl;
  }
  return 0;
}