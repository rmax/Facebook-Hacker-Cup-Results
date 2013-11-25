#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
  string name;
  int shot, h;

  int time;

 };

bool comp(const Player& a, const Player& b) {
  return (a.shot == b.shot ? a.h > b.h : a.shot > b.shot);
}

bool comp2(const Player& a, const Player& b) {
  if (a.time == b.time) 
    return (a.shot == b.shot ? a.h > b.h : a.shot > b.shot);
  return a.time < b.time;
}

void solve() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<Player> v(n);
  for (int i = 0; i < n; ++i) { 
    cin >> v[i].name >> v[i].shot >> v[i].h;
    v[i].time = 0;
  }
  
  sort(v.begin(), v.end(), comp);

  vector<int> jug1, jug2;
  vector<Player> in1, in2;
  vector<Player> out1, out2;
  
  for (int i = 0; i < n; ++i) {
    if (i&1) jug2.push_back(i);
    else jug1.push_back(i);
  }

  for (int i = 0; i < p; ++i) {
    in1.push_back(v[jug1[i]]);
    in2.push_back(v[jug2[i]]);
  }

  for (int i = p; i < jug1.size(); ++i) 
    out1.push_back(v[jug1[i]]);
  for (int i = p; i < jug2.size(); ++i) 
    out2.push_back(v[jug2[i]]);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < p; ++j) {
      ++in1[j].time;
      ++in2[j].time;
    }
    if (jug1.size() > p) {
      sort(in1.begin(), in1.end(), comp2);
      sort(out1.begin(), out1.end(), comp2);
      swap(out1[0], in1[p - 1]);
    }
    if (jug2.size() > p) {
      sort(in2.begin(), in2.end(), comp2);
      sort(out2.begin(), out2.end(), comp2);
      swap(out2[0], in2[p - 1]);
    }
  }
  vector<string> res;
  for (int i = 0; i < p; ++i) {
    res.push_back(in1[i].name);
    res.push_back(in2[i].name);
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); ++i)
    cout << " " << res[i];
  cout << endl;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ":";
    solve();
  }
}
