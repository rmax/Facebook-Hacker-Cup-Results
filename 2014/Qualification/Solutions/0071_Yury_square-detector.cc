#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int l;
    cin >> l;
    vector<string> f(l);
    for (int j = 0; j < l; ++j) {
      cin >> f[j];
      f[j] = "." + f[j] + ".";
    }
    string b(f[0].size(), '.');
    f.insert(f.begin(), b);
    f.insert(f.end(), b);

    int nin = 0, nout = 0;
    for (int j = 0; j + 1 < f.size(); ++j) {
      for (int k = 0; k + 1 < f[0].size(); ++k) {
        int c = (f[j][k] == '#') + (f[j][k + 1] == '#') + (f[j + 1][k] == '#') + (f[j + 1][k + 1] == '#');
        if (c == 1)
          ++nout;
        else if (c == 3)
          ++nin;
      }
    }
    bool ok = false;
    if (nout == 4 && nin == 0) {
      int tot = 0, cur, hei = 0;
      for (int j = 0; j < f.size(); ++j) {
        cur = count(f[j].begin(), f[j].end(), '#');
        if (cur)
          hei++;
        tot += cur;
      }
      if (hei * hei == tot)
        ok = true;
    }
    cout << "Case #" << i << ": " << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
