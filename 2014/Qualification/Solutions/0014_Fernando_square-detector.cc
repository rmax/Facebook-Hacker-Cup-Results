#include <stdio.h>
#include <algorithm>

using namespace std;

int t, teste;
int smallx, smally, bigx, bigy;
int n;
char ch;

int main() {
   for (scanf("%d", &t); t; --t) {
      printf("Case #%d: ", ++teste);

      scanf("%d", &n);
      smallx = n+1;
      bigx = -1;
      smally = n+1;
      bigy = -1;

      int cnt = 0;

      for (int x = 0; x < n; x++) {
         for (int y = 0; y < n; y++) {
            scanf(" %c", &ch);
            if (ch == '#') {
               smallx = min(smallx, x);
               bigx = max(bigx, x);
               smally = min(smally, y);
               bigy = max(bigy, y);

               cnt++;
            }
         }
      }

      int dx = bigx - smallx + 1;
      int dy = bigy - smally + 1;

      if (dx != dy) {
         printf("NO\n");
      }
      else if (dx*dy != cnt) {
         printf("NO\n");
      }
      else printf("YES\n");
   }
}