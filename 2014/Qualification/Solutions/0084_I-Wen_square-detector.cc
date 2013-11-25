#include<stdio.h>
int main(){
    int T,cs=0;scanf("%d",&T);
    while(T--){
        int N,a[22][22]={};
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            char s[22];
            scanf("%s",s+1);
            for(int j=1;j<=N;j++)a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(s[j]=='#');
        }
        bool suc=false;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++){
                for(int k=1;k<=i&&k<=j;k++){
                        if(a[N][N]==a[i][j]-a[i][j-k]-a[i-k][j]+a[i-k][j-k]&&k*k==a[N][N])suc=true;
                }
            }
        printf("Case #%d: ",++cs);
        if(suc)puts("YES");
        else puts("NO");
    }
    return 0;
}
