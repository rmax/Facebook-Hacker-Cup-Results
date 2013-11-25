//
// tennison.cpp
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

#define EPS (1e-8)


double ps, pr, pi, pu, pw, pd, pl;
int K;
int PU, PD;
double dp[105][105][1005];
double cal(int score1, int score2, int PP){

    if(score1 == 0) return 1.0;
    if(score2 == 0) return 0.0;
    if(dp[score1][score2][PP] > -0.5) return dp[score1][score2][PP];
    // win case
    double p_sun = ((double)PP) / 1000;
    double p_win = p_sun * ps + (1.0-p_sun) * pr;
    double a = p_win * (pw * cal(score1 - 1, score2, min(PP + PU, 1000)) + (1 - pw) * cal(score1 - 1, score2, PP));
    // lose case
    double b = (1.0-p_win) * (pl * cal(score1, score2 - 1, max(0, PP - PD)) + (1 - pl) * cal(score1, score2 - 1, PP));
    return dp[score1][score2][PP] = a + b;
}

void solve(){
    scanf("%d", &K);
    scanf("%lf %lf %lf %lf %lf %lf %lf", &ps, &pr, &pi, &pu, &pw, &pd, &pl);
    PU = (int)(pu * 10000 + 5) / 10;
    PD = (int)(pd * 10000 + 5) / 10;
    int PP = (int)(pi * 10000 + 5) / 10;
    for(int i = 0; i <= K; i++ )
        for(int j = 0; j <= K; j++ )
            for(int k = 0; k < 1005; k++ )
                dp[i][j][k] = -1;

    if(ps * pi >= 1.000 - EPS){
        printf("1.000000\n");
    } else if(pr * (1-pi) >= 1.000 - EPS){
        printf("1.000000\n");
    } else if(ps >= 1.000 - EPS && pr >= 1.000 - EPS){
        printf("1.000000\n");
    } else {
        double ans = cal(K, K, PP);
        printf("%.6lf\n", ans);
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
