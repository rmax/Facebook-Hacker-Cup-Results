#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int T,N;
    char M[20][21];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%s",M[i]);
        
        int r1 = N - 1,r2 = 0,c1 = N - 1,c2 = 0,cont = 0;
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                if(M[i][j] == '#'){
                    r1 = min(r1,i);
                    r2 = max(r2,i);
                    c1 = min(c1,j);
                    c2 = max(c2,j);
                    ++cont;
                }
            }
        }
        
        printf("Case #%d: ",tc);
        
        if(r2 - r1  == c2 - c1 && (r2 - r1 + 1) * (c2 - c1 + 1) == cont) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
