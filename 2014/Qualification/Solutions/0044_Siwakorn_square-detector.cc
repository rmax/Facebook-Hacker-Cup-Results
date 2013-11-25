//
// square.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Thursday, 21 November 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

int n;
char in[25][25];
void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++ ) scanf("%s", in[i]);
    int cnt = 0;
    int maxr = -1, minr = 10000, maxc = -1, minc = 10000;
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < n; j++ ){
            if(in[i][j] == '#'){
                cnt++;
                maxr = max(maxr, i);
                minr = min(minr, i);
                maxc = max(maxc, j);
                minc = min(minc, j);
            }
        }
    }

    int d1 = maxr - minr + 1;
    int d2 = maxc - minc + 1;
    if(d1 == d2 && d1 * d2 == cnt){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    for(int tt = 0; tt < test; tt++ ){
        printf("Case #%d: ", tt + 1);
        solve();
    }
    return 0;
}
