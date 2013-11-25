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

const int N = 20;

char arr[N][N+1];

int main() {
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n; cin >> n;
    int t = N, b = -1, l = N, r = -1;
    int blacks = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      for (int j = 0; j < n; j++) if (arr[i][j] == '#') {
        blacks++;
        l = min(l, j), r = max(r, j);
        t = min(t, i), b = max(b, i);
      }
    }
    cout << "Case #" << tt << ": ";
    int h = b-t+1, w = r-l+1;
    if (h == w && blacks == h*w)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}