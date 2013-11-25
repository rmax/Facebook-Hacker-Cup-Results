#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

char s[55][55];
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n, X1, Y1, X2, Y2;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
        int f1 = 0;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        if (s[i][j] == '#'){
            if (!f1){
                f1 = 1;
                X1 = i, Y1 = j;
            }
            X2 = i, Y2 = j;
        }
        if (X2 - X1 != Y2 - Y1){
            printf("Case #%d: NO\n", cas);
            continue;
        }
        f1 = 0;
        for (int i = X1; i <= X2; i++)
        for (int j = Y1; j <= Y2; j++)
        if (s[i][j] != '#') f1 = 1;
        if (!f1) printf("Case #%d: YES\n", cas);
        else printf("Case #%d: NO\n", cas);
    }

}
