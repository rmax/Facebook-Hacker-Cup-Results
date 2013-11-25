#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 31;
int n, m, p;
struct data {
  string name;
  int shot_percentage;
  int height;
  int time;
  int id;
  bool operator <(const data& d) const {
    return time == d.time ? id < d.id : time < d.time;
  }
} d[MAXN];
priority_queue<data> team[2], rest[2], tmp;

bool cmp (const data& a, const data& b) {
  return a.shot_percentage == b.shot_percentage ? a.height > b.height : a.shot_percentage > b.shot_percentage;
}
int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 0; T < cases; T++) {
    scanf("%d %d %d", &n, &m, &p);
    printf("Case #%d:", T + 1);
    for (int i = 0; i < n; i++) {
      cin >> d[i].name >> d[i].shot_percentage >> d[i].height;
      d[i].time = 0;
    }
    sort(d, d + n, cmp);
    for (int i = 0; i < n; i++) {
      d[i].id = i;
    }
    for (int i = 0; i < 2; i++) {
      while (!team[i].empty()) {
        team[i].pop();
      }
      while (!rest[i].empty()) {
        rest[i].pop();
      }
    }
    for (int i = 0; i < n; i++) {
      if (i < 2 * p) {
        team[i % 2].push(d[i]);
      } else {
        d[i].id = -d[i].id;
        rest[i % 2].push(d[i]);
      }
    }
    for (int t = 0; t < m; t++) {
      for (int i = 0; i < 2; i++) {
        while (!tmp.empty()) tmp.pop();
        while (!team[i].empty()) {
          data e = team[i].top();
          team[i].pop();
          e.time += 1;
          tmp.push(e);
        }
        while (!tmp.empty()) {
          data e = tmp.top();
          //printf("%d %d %s %d %d\n", t, i, e.name.c_str(), e.time, e.id);
          tmp.pop();
          team[i].push(e);
        }
      }
      for (int i = 0; i < 2; i++) {
        if (rest[i].empty()) continue;
        data e = team[i].top();
        team[i].pop();
        data f = rest[i].top();
        rest[i].pop();
        e.id = -e.id;
        e.time = -e.time;
        f.id = -f.id;
        f.time = -f.time;
        team[i].push(f);
        rest[i].push(e);
        //printf("%s %s\n", e.name.c_str(), f.name.c_str());
      }
    }
    vector<string> names;
    for (int i = 0; i < 2; i++) {
      while (!team[i].empty()) {
        data e = team[i].top();
        team[i].pop();
        names.push_back(e.name);
      }
    }
    sort(names.begin(), names.end());
    for (int i = 0; i < names.size(); i++) {
      printf(" %s", names[i].c_str());
    }
    puts("");
  }
}
