#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 100;

int ntest;
int n;
char s[maxn][maxn];

int main() {
  scanf("%d", &ntest);
  for(int test = 1; test <= ntest; test++) {
    scanf("%d", &n);

    int minx = n, miny = n, maxx = 0, maxy = 0;

    for(int i=0; i<n; i++) {
      scanf("%s", s[i]);
      for(int j=0; j<n; j++) {
        if(s[i][j] == '#') {
          minx = min(minx, i);
          maxx = max(maxx, i);
          miny = min(miny, j);
          maxy = max(maxy, j);
        }
      }
    }

    bool ok = (maxx - minx) == (maxy  - miny);
    for(int i=minx; i<=maxx; i++) {
      for(int j=miny; j<=maxy; j++) {
        if(s[i][j] != '#') ok = false;
      }
    }

    printf("Case #%d: %s\n", test, ok ? "YES" : "NO");
  }
  return 0;
}
