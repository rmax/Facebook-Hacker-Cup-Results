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

struct P {
  string n;
  int p;
  int h;
  int m;
};

struct draft_cmp {
  bool operator()(const P& p1, const P& p2) {
    return (p1.p != p2.p) ? p1.p > p2.p : p1.h > p2.h;
  }
};

struct bench_cmp {
  bool operator()(const P& p1, const P& p2) {
    return (p1.m != p2.m) ? p1.m < p2.m : draft_cmp_(p1, p2);
  }
  draft_cmp draft_cmp_;
};

struct active_cmp {
  bool operator()(const P& p1, const P& p2) {
    return (p1.m != p2.m) ? p1.m > p2.m : draft_cmp_(p2, p1);
  }
  draft_cmp draft_cmp_;
};

void simulate(const vector<P>& team, int m, int p, vector<string>& res) {
  vector<P> bench(team.begin() + p, team.end());
  vector<P> active(team.begin(), team.begin() + p);
  for (int rr = 0; rr < m; ++rr) {
    sort(bench.begin(), bench.end(), bench_cmp());
    sort(active.begin(), active.end(), active_cmp());
    for (P& player : active) ++player.m;
    if (bench.size() && active.size()) {
      swap(bench[0], active[0]);
    }
  }
  for (const P& player : active) {
    res.push_back(player.n);
  }
}

int main() {
  int T; cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    int n, m, p; cin >> n >> m >> p;
    vector<P> ps(n), team[2];
    for (int i = 0; i < n; ++i) {
      P& p = ps[i]; p.m = 0;
      cin >> p.n >> p.p >> p.h;
    }
    sort(ps.begin(), ps.end(), draft_cmp());
    for (int i = 0; i < n; ++i) {
      team[i&1].push_back(ps[i]);
    }
    vector<string> active;
    simulate(team[0], m, p, active);
    simulate(team[1], m, p, active);
    sort(active.begin(), active.end());
    cout << "Case #" << tt + 1 << ":";
    for (const string& name : active) {
      cout << " " << name;
    }
    cout << endl;
  }
  return 0;
}