#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct Player {
  Player(): shot(0), height(0) {}

  std::string name;
  int shot;
  int height;
};

bool operator < (const Player& lhs, const Player& rhs) {
  return (lhs.shot < rhs.shot) ||
      (lhs.shot == rhs.shot && lhs.height < rhs.height);
}

void GetCurrent(std::vector<Player> ps, int m, int p, std::vector<Player>* res) {
  std::sort(ps.begin(), ps.begin() + p);
  int i = m % ps.size();
  int j = 0;
  while (j < p) {
    res->push_back(ps[i]);
    i = (i + 1) % ps.size();
    ++j;
  }
}

int main() {
  int num_tests;
  cin >> num_tests;
  for (int test_num = 1; test_num <= num_tests; ++test_num) {
    int n, m, p;
    cin >> n >> m >> p;
    std::vector<Player> ps(n);
    for (int i = 0; i < n; ++i)
      cin >> ps[i].name >> ps[i].shot >> ps[i].height;
    std::sort(ps.rbegin(), ps.rend());
    std::vector<Player> fs, ss;
    for (size_t i = 0; i < ps.size(); ++i) {
      if (i & 1)
        ss.push_back(ps[i]);
      else
        fs.push_back(ps[i]);
    }

    std::vector<Player> fr, sr;
    GetCurrent(fs, m, p, &fr);
    GetCurrent(ss, m, p, &sr);

    std::vector<std::string> names;
    for (size_t i = 0; i < fr.size(); ++i)
      names.push_back(fr[i].name);
    for (size_t i = 0; i < sr.size(); ++i)
      names.push_back(sr[i].name);
    std::sort(names.begin(), names.end());
    cout << "Case #" << test_num << ":";
    for (size_t i = 0; i < names.size(); ++i)
      std::cout << " " << names[i];
    cout << endl;
  }
  return 0;
}
