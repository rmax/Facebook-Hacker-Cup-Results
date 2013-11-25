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



double f[222][222][1005];

int main(){
    int CAS, n;
    double ps, pr, pi, pu, pw, pd, pl;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> CAS;
    for (int cas = 1; cas <= CAS; cas++){
        cin >> n >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
        for (int i = 0; i <= n + n; i++)
        for (int j = 0; j <= n + n; j++)
        for (int k = 0; k <= 1000; k++)
            f[i][j][k] = 0;
        f[0][0][(int)((pi + 1e-6) * 1000)] = 1;
        for (int i = 0; i < n + n; i++)
        for (int j = 0; j < n; j++)
        for (int k = 0; k <= 1000; k++){
            double p = k / 1000.0;
            f[i + 1][j + 1][min(1000, k + (int)((pu + 1e-6) * 1000))] += (f[i][j][k] * p * ps + f[i][j][k] * (1 - p) * pr) * pw;
            f[i + 1][j + 1][k] += (f[i][j][k] * p * ps + f[i][j][k] * (1 - p) * pr) * (1 - pw);
            f[i + 1][j][max(0, k - (int)((pd + 1e-6) * 1000))] += (f[i][j][k] * p * (1 - ps) + f[i][j][k] * (1 - p) * (1 - pr)) * pl;
            f[i + 1][j][k] += (f[i][j][k] * p * (1 - ps) + f[i][j][k] * (1 - p) * (1 - pr)) * (1 - pl);
        }
        double ans = 0;
        for (int i = 1; i < n + n; i++)
        for (int j = 0; j <= 1000; j++)
            ans += f[i][n][j];
        printf("Case #%d: %.6lf\n", cas, ans);

    }

}
