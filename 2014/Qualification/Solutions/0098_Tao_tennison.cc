#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

double ps=0.984, pr=0.222;
double pu=0.336, pw=0.207, pd=0.084, pl=0.478;
double pi = 0.993;
double ans = 0;
int k = 25;
double dp[2][3][103][103][103];
int main(){
    int t;
    cin >> t;
    for(int ca=0;ca<t;ca++){
        ans = 0;
        cerr << ca << endl;
        cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][0] = 1.0;
        for(int wl = 0; wl <= k*2-1; wl++){
            int cur = wl & 1;
            memset(dp[1-cur], 0, sizeof(dp[1-cur]));

            for(int sta=0;sta<3;sta++)
                for(int win=0;win<=k && win <=wl;win++){
                    int lose = wl - win;
                    if(lose >= k) continue;

                    for(int inc=0;inc<=win;inc++){
                        for(int dec=0;dec<=lose;dec++){
                            double val = dp[cur][sta][win][inc][dec];
                            if(win >= k){
                                /* cout << win << " " << lose << " " << sta << " " <<  dp[cur][sta][win][inc][dec] << endl; */
                                ans += val;
                                continue;
                            }
                            double sun = pi + pu * inc - pd * dec;
                            if(sta == 1) sun = pu * inc - pd * dec;
                            else if(sta == 2) sun = 1.0 + pu * inc - pd * dec;

                            double pwin = sun * ps + (1-sun) * pr;
                            double plose = 1 - pwin;

                            dp[1-cur][sta][win+1][inc][dec] += val * pwin * (1.0 - pw);
                            dp[1-cur][sta][win][inc][dec] += val * plose * (1.0 - pl);

                            if(sun + pu < 1.0)
                                dp[1-cur][sta][win+1][inc+1][dec] += val * pwin * pw;
                            else
                                dp[1-cur][2][win+1][0][0] += val * pwin * pw;

                            if(sun - pd > 0.0)
                                dp[1-cur][sta][win][inc][dec+1] += val * plose * pl;
                            else
                                dp[1-cur][1][win][0][0] += val * plose * pl;
                        }
                    }
                }
        }
        printf("Case #%d: %.6lf\n", ca+1, ans);
    }
    return 0;
}
