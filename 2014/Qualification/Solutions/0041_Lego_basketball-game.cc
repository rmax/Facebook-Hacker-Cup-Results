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

typedef priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Bench;
typedef priority_queue< pair<int, int>, vector< pair<int, int> > > OnCourt;

const int N = 30;

bool compare(const pair< string, pair<int, int> >& a, const pair< string, pair<int, int> >& b) {
  if (a.second.first != b.second.first) return a.second.first > b.second.first;
  return a.second.second > b.second.second;
}

int minutes[N];

void update(OnCourt& onCourt) {
  OnCourt temp;
  while (!onCourt.empty()) {
    int id = onCourt.top().second;
    minutes[id]++;
    temp.push(make_pair(minutes[id], id));
    onCourt.pop();
  }
  onCourt = temp;
}

int main() {
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n, m, p; cin >> n >> m >> p;
    vector< pair< string, pair<int, int> > > players;
    for (int i = 0; i < n; i++) {
      string name;
      int shot, height;
      cin >> name >> shot >> height;
      players.push_back(make_pair(name, make_pair(shot, height)));
    }
    sort(players.begin(), players.end(), compare);

    Bench bench[2];
    for (int i = 0; i < n; i++) minutes[i] = 0, bench[i & 1].push(make_pair(0, i));

    OnCourt onCourt[2];
    for (int i = 0; i < 2; i++) for (int j = 0; j < p; j++) {
      onCourt[i].push(bench[i].top());
      bench[i].pop();
    }

    while (m--) {
      for (int i = 0; i < 2; i++) {
        update(onCourt[i]);
        bench[i].push(onCourt[i].top());
        onCourt[i].pop();
        onCourt[i].push(bench[i].top());
        bench[i].pop();
      }
    }

    vector<string> res;
    for (int i = 0; i < 2; i++) {
      while (!onCourt[i].empty()) {
        res.push_back(players[onCourt[i].top().second].first);
        onCourt[i].pop();
      }
    }
    sort(res.begin(), res.end());
    cout << "Case #" << tt << ":";
    for (int i = 0; i < res.size(); i++) cout << " " << res[i];
    cout << endl;
  }
  return 0;
}
