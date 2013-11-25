#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 22;
char mat[MAXN][MAXN];
int sqr[MAXN * MAXN];
int main() {
  for (int i = 0; i < MAXN; i++) {
    sqr[i * i] = 1;
  }
  int cases, n;
  scanf("%d", &cases);
  for (int T = 0; T < cases; T++) {
    scanf("%d", &n);
    gets(mat[0]);
    int cnt = 0;
    int u = n + 1, d = 0;
    int l = n + 1, r = 0;
    for (int i = 0; i < n; i++) {
      gets(mat[i]);
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == '#') {
          cnt++;
          u = min(u, i);
          d = max(d, i);
          l = min(l, j);
          r = max(r, j);
        }
      }
    }
    printf("Case #%d: ", T + 1);
    if (!sqr[cnt] || (d - u != r - l)) {
      puts("NO");
      continue;
    }
    bool flag = true;
    for (int i = u; i <= d; i++) {
      for (int j = l; j <= r; j++) {
        if (mat[i][j] != '#') {
          flag = false;
          break;
        }
      }
    }
    puts(flag ? "YES" : "NO");
  }
}

                           
