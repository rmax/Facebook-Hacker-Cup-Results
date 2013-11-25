#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int C=1, T, n;
char M[32][32];

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        int cp=0;
        for (int i=0;i<n;i++) {
            scanf("%s",M[i]);
            for (int j=0;j<n;j++)
                if (M[i][j]=='#') cp++;
        }
        if (!cp) {
            printf("NO\n");
            continue;
        }
        int x1,y1,x2,y2;
        x1=y1=0x3f3f3f3f;
        x2=y2=-0x3f3f3f3f;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) if (M[i][j] == '#') {
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
        if (x2-x1 != y2-y1)
            printf("NO\n");
        else
            printf("%s\n", (x2-x1+1)*(y2-y1+1) == cp ? "YES": "NO");

    }

    return 0;
}
