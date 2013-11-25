#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T,N,M,P;

struct player{
    string name;
    int shot;
    int h;
    
    player(){}
    
    bool operator < (player X)const{
        if(shot != X.shot) return shot > X.shot;
        return h > X.h;
    }
}a[30];

/*

    Each team starts the game with the P players who have the lowest draft numbers.
    After each minute of the game the player with the highest total time played leaves the playing field.
    Ties are broken by the player with the higher draft number leaving first.
    
    To replace her the player on the bench with the lowest total time played joins the game.
    Ties are broken by the player with the lower draft number entering first.

*/

int cont[30];

int main(){
    ios::sync_with_stdio(0);
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N >> M >> P;
        
        for(int i = 0;i < N;++i)
            cin >> a[i].name >> a[i].shot >> a[i].h;
        
        sort(a,a + N);
        
        int id1[P],id2[P];
        bool isout[N];
        
        for(int i = 0;i < P;++i) id1[i] = 2 * i;
        for(int i = 0;i < P;++i) id2[i] = 2 * i + 1;
        
        memset(cont,0,sizeof cont);
        
        for(int it = 0;it < M;++it){
            //cout << "it = " << it << endl;
            memset(isout,true,sizeof isout);
            
            for(int i = 0;i < P;++i){
                ++cont[ id1[i] ];
                isout[ id1[i] ] = false;
            }
            
            for(int i = 0;i < P;++i){
                ++cont[ id2[i] ];
                isout[ id2[i] ] = false;
            }
            
            int out1 = P - 1;
            int out2 = P - 1;
            
            sort(id1,id1 + P);
            sort(id2,id2 + P);
            
            for(int i = P - 2;i >= 0;--i)
                if(cont[ id1[i] ] > cont[ id1[out1] ])
                    out1 = i;
            
            for(int i = P - 2;i >= 0;--i)
                if(cont[ id2[i] ] > cont[ id2[out2] ])
                    out2 = i;
            //cout << out1 << " * " << out2 << endl;
            //cout << id1[out1] << " - " << id2[out2] << endl;
            //if(cont[ id1[out1] ] > cont[ id2[out2] ] || (cont[ id1[out1] ] == cont[ id2[out2] ] && id1[out1] > id2[out2])){
                int in1 = -1;
                
                for(int i = 0;i < N;i += 2)
                    if(isout[i] && (in1 == -1 || cont[i] < cont[in1]))
                        in1 = i;
                //cout << 1 << " " << in1 << " <-> " << id1[out1] << endl;
                if(in1 != -1) id1[out1] = in1;
            //}else{
                int in2 = -1;
                
                for(int i = 1;i < N;i += 2)
                    if(isout[i] && (in2 == -1 || cont[i] < cont[in2]))
                        in2 = i;
                //cout << 2 << " " << in2 << " <-> " << id2[out2] << endl;
                if(in2 != -1) id2[out2] = in2;
            //}
        }
        
        vector<string> ans;
        
        for(int i = 0;i < P;++i)
            ans.push_back(a[ id1[i] ].name);
        for(int i = 0;i < P;++i)
            ans.push_back(a[ id2[i] ].name);
        
        sort(ans.begin(),ans.end());
        
        printf("Case #%d:",tc);
        
        for(int i = 0;i < 2 * P;++i)
            printf(" %s",ans[i].c_str());
        
        printf("\n");
        //break;
    }
    
    return 0;
}
