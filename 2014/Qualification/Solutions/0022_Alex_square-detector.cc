#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> M(n);
  for (int i = 0; i < n; ++i) cin >> M[i];

  int minx = 1e3, maxx = -1e3, miny = 1e3, maxy = -1e3, qtt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (M[i][j] == '#') {
        minx = min(minx, i);
        miny = min(miny, j);
        maxx = max(maxx, i);
        maxy = max(maxy, j);
        ++qtt;
      }
    }
  }

  if (maxx - minx == maxy - miny and (maxx - minx + 1)*(maxy - miny + 1) == qtt)
    cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
