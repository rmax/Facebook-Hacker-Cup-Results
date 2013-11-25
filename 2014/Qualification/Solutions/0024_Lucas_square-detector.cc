#include <bits/stdc++.h>
#define Fr(i,a,b) for(int i = (a); i < (b); ++i)
#define Rp(i,n) Fr(i,0,n)

using namespace std;

char grid[22][22];

int main() {
    int tc; cin >> tc; ++tc;
    Fr(_,1,tc) {
        int n;
        cin >> n;
        Rp(i,n) cin >> grid[i];
        int minr = 100, minc = 100, maxr = -1, maxc = -1;
        Rp(i,n) Rp(j,n)
            if(grid[i][j] == '#') {
                minr = min(minr,i);
                maxr = max(maxr,i);
                minc = min(minc,j);
                maxc = max(maxc,j);
            }
        bool ok = (maxc-minc == maxr - minr);
        Fr(i,minr,maxr+1)
            Fr(j,minc,maxc+1)
                ok&=grid[i][j]=='#';
        printf("Case #%d: %s\n", _, ok ? "YES" : "NO");
    }
    return 0;
}
