#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long double p[101][1001],p2[101][1001];

int main(){
    int T,K;
    long double ps,pr,pi,pu,pw,pd,pl;
    int PS,PR,PI,PU,PW,PD,PL;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&K);
        
        cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
        PI = (int)(pi * 1000);
        PU = (int)(pu * 1000);
        PD = (int)(pd * 1000);
        
        for(int i = 0;i <= 2 * K;++i)
            for(int j = 0;j <= 1000;++j)
                p[i][j] = 0;
        
        p[0][PI] = 1;
        long double ans = 0;
        
        for(int it = 0;it <= 2 * K;++it){
            for(int i = 0;i <= K;++i)
                for(int j = 0;j <= 1000;++j)
                    p2[i][j] = 0;
            
            for(int i = 0,i2 = it;i <= K && i <= it;++i,--i2){
                for(int j = 0;j <= 1000;++j){
                        long double pwin = (j * ps + (1000 - j) * pr) / 1000.0;
                        long double plose = 1 - pwin;
                        long double curp = p[i][j];
                        
                        if(i == K - 1) ans += curp * pwin;
                        else{
                            p2[i + 1][min(1000,j + PU)] += curp * pwin * pw;
                            p2[i + 1][j] += curp * pwin * (1 - pw);
                        }
                        
                        if(i2 < K - 1){
                            p2[i][max(0,j - PD)] += curp * plose * pl;
                            p2[i][j] += curp * plose * (1 - pl);
                        }
                }
            }
            
            for(int i = 0;i <= K;++i)
                for(int j = 0;j <= 1000;++j)
                    p[i][j] = p2[i][j];
        }
        
        printf("Case #%d: %.6f\n",tc,(double)ans);
    }
    
    return 0;
}
