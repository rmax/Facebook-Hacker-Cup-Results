#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int T, n, m, p, C=1, L[1024], shot[1024], h[1024];
char nome[1024][1024];

bool cmp(int a, int b) {
    if (shot[a] != shot[b])
        return shot[a] > shot[b];
    return h[a] > h[b];
}

bool cmp2(int a, int b) {
    return strcmp(nome[a],nome[b])<0;
}

int main() {

    for(scanf("%d",&T);T--;) {
        scanf("%d %d %d",&n,&m,&p);
        for (int i=0;i<n;i++)
            scanf("%s %d %d",nome[i],shot+i,h+i);
        for (int i=0;i<n;i++) L[i] = i;
        sort(L,L+n,cmp);
        vector<int> time[2];
        for (int i=0;i<n;i++)
            time[ (i&1) ].push_back( L[i] );

        vector<int> resp;
        for (int t=0;t<2;t++) {

            if ((int)time[t].size() <= p) { // todo mundo joga
                for (int i=0;i<(int)time[t].size();i++)
                    resp.push_back(time[t][i]);
                continue;
            }

            queue<int> Q[2];
            for (int i=p-1;i>=0;i--)
                Q[0].push( time[t][i] );
            for (int i=p;i<(int)time[t].size();i++)
                Q[1].push( time[t][i] );
            for (int tt=0;tt<m;tt++) {
                int sai = Q[0].front();
                int entra = Q[1].front();
                Q[0].pop(); Q[0].push(entra);
                Q[1].pop(); Q[1].push(sai);
            }
            while (!Q[0].empty()) {
                resp.push_back(Q[0].front());
                Q[0].pop();
            }
        }
        sort(resp.begin(),resp.end(),cmp2);

        printf("Case #%d:",C++);
        for (int i=0;i<(int)resp.size();i++)
            printf(" %s",nome[resp[i]]);
        printf("\n");
    }

    return 0;
}
