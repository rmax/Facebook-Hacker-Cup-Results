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

int main() {
  int T; cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    int N; cin >> N;
    vector<string> vs(N);
    int t = 0, x = 0, y = 0;
    for (int i = 0; i < N; ++i) {
      cin >> vs[i];
      int c = count(vs[i].begin(), vs[i].end(), '#');
      if (c) {
        t += c;
        x = i;
        y = vs[i].find_last_of('#');
      }
    }
    int sd = int(sqrt(1.0 * t) + 1E-3);
    x -= sd - 1;
    y -= sd - 1;
    bool res = true;
    if (x < 0 || y < 0 || sd * sd < t) {
      res = false;
    } else {
      for (int i = 0; i < sd; ++i) {
        for (int j = 0; j < sd; ++j) {
          if (vs[x + i][y + j] != '#') {
            res = false;
          }
        }
      }
    }
    cout << "Case #" << tt + 1 << ": " << (res ? "YES" : "NO") << endl;
  }
  return 0;
}