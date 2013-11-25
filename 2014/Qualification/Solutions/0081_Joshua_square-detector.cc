#include <iostream>
#include <string>

using namespace std;

bool grid[50][50];

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n; cin >> n;
    string dummy; getline(cin, dummy);
    for (int i = 0; i < n; ++i) {
      string line; getline(cin, line);
      for (int j = 0; j < n; ++j) {
        grid[i][j] = (line[j] == '#');
      }
    }

    bool first_found = false;
    pair<int, int> first, last;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          if (!first_found) {
            first = make_pair(i, j);
            first_found = true;
          }
          last = make_pair(i, j);
        }
      }
    }

    bool okay = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != (first.first <= i && i <= last.first &&
                           first.second <= j && j <= last.second)) {
          okay = false;
          break;
        }
      }
    }
    if (last.first - first.first != last.second - first.second) okay = false;
    if (last.first - first.first < 0) okay = false;
    cout << "Case #" << test << ": " << (okay ? "YES" : "NO") << endl;
  }
  return 0;
}