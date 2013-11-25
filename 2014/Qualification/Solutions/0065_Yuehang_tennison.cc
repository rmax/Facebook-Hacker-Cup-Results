#include <bits/stdc++.h>
using namespace std;
double dp[2][110][1010];

int main()
{
    //freopen("tennison.txt","r",stdin);
    //freopen("tennison_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++)
    {
        int K;
        double ps,pr,pi,pu,pw,pd,pl;
        scanf("%d%lf%lf%lf%lf%lf%lf%lf",&K,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
        int u=(int)(pu*1000.0+1e-8),v=(int)(pd*1000.0+1e-8),pre=(int)(pi*1000.0+1e-8);
        memset(dp,0,sizeof(dp));
        dp[0][0][pre]=1.0;
        int i=0;
        double anss=0.0;
        for (int ii=0; ii<=2*K-1; ii++)
        {
            i=1-i;
            memset(dp[i],0,sizeof(dp[i]));
            for (int j=0; j<=ii&&j<=K; j++)
            {
                for (int k=0; k<=1000; k++)
                {
                    if (ii-j>=K) continue;
                    if (j==K)
                    {
                        anss+=dp[1-i][j][k];
                        continue;
                    }
                    double P=dp[1-i][j][k];
                    double p=k/1000.0;

                    double win=ps*p+pr*(1.0-p);
                    dp[i][j+1][k]+=P*win*(1.0-pw);
                    dp[i][j+1][min(1000,k+u)]+=P*win*pw;
                    dp[i][j][k]+=P*(1.0-win)*(1.0-pl);
                    dp[i][j][max(0,k-v)]+=P*(1.0-win)*pl;
                }
            }
        }
        printf("Case #%d: %.6f\n",cas,anss);
    }
    return 0;
}
