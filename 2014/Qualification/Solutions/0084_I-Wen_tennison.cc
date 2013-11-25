#include<stdio.h>
#include<algorithm>
using namespace std;
double dp[2][102][102][102],up[2][102][102][102],down[2][102][102][102];
double fix(double v){
    return max(0.,min(1.,v));
}
int main(){
    int T,K,cs=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&K);
        int now=0;
        double ps,pr,pi,pu,pw,pd,pl;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&ps,&pr,&pi,&pu,&pw,&pd,&pl);
        for(int round=K+K-1;round>=0;round--,now^=1){
            if(round>=K){
                for(int i=0;i<=K&&i<=round;i++)for(int j=0;j<=K&&i+j<=round;j++){
                    dp[now][K][i][j]=1;
                    up[now][K][i][j]=1;
                    down[now][K][i][j]=1;
                }
                for(int i=0;i<=K&&i<=round;i++)for(int j=0;j<=K&&i+j<=round;j++){
                    dp[now][round-K][i][j]=0;
                    up[now][round-K][i][j]=0;
                    down[now][round-K][i][j]=0;
                }
            }
            for(int i=max(0,round-K+1);i<K&&i<=round;i++){
                for(int j=0;j<=K&&j<=round;j++)for(int k=0;k<=K&&j+k<=round;k++){
                    double sun=fix(pi+pu*j-pd*k);
                    double win=sun*ps+(1-sun)*pr;
                    if(pi+pu*(j+1)-pd*k<=1)dp[now][i][j][k]=win*(pw*dp[now^1][i+1][j+1][k]+(1-pw)*dp[now^1][i+1][j][k]);
                    else dp[now][i][j][k]=win*(pw*up[now^1][i+1][0][0]+(1-pw)*dp[now^1][i+1][j][k]);
                    if(pi+pu*j-pd*(k+1)>=0)dp[now][i][j][k]+=(1-win)*(pl*dp[now^1][i][j][k+1]+(1-pl)*dp[now^1][i][j][k]);
                    else dp[now][i][j][k]+=(1-win)*(pl*down[now^1][i][0][0]+(1-pl)*dp[now^1][i][j][k]);

                    sun=fix(1+pu*j-pd*k);
                    win=sun*ps+(1-sun)*pr;
                    if(1+pu*(j+1)-pd*k<=1)up[now][i][j][k]=win*(pw*up[now^1][i+1][j+1][k]+(1-pw)*up[now^1][i+1][j][k]);
                    else up[now][i][j][k]=win*(pw*up[now^1][i+1][0][0]+(1-pw)*up[now^1][i+1][j][k]);
                    if(1+pu*j-pd*(k+1)>=0)up[now][i][j][k]+=(1-win)*(pl*up[now^1][i][j][k+1]+(1-pl)*up[now^1][i][j][k]);
                    else up[now][i][j][k]+=(1-win)*(pl*down[now^1][i][0][0]+(1-pl)*up[now^1][i][j][k]);
                    
                    sun=fix(pu*j-pd*k);
                    win=sun*ps+(1-sun)*pr;
                    if(pu*(j+1)-pd*k<=1)down[now][i][j][k]=win*(pw*down[now^1][i+1][j+1][k]+(1-pw)*down[now^1][i+1][j][k]);
                    else down[now][i][j][k]=win*(pw*up[now^1][i+1][0][0]+(1-pw)*down[now^1][i+1][j][k]);
                    if(pu*j-pd*(k+1)>=0)down[now][i][j][k]+=(1-win)*(pl*down[now^1][i][j][k+1]+(1-pl)*down[now^1][i][j][k]);
                    else down[now][i][j][k]+=(1-win)*(pl*down[now^1][i][0][0]+(1-pl)*down[now^1][i][j][k]);
                }
            }
        }
        printf("Case #%d: %.6f\n",++cs,dp[now^1][0][0][0]);
    }
    return 0;
}
