#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1ll<<60)

int N,F;
bool graph[260][260];
ll cost[260];
ll dp[(1<<11)][260];
ll dist[260][260];

ll func(void){
	int mask,x,y,i,j,k;
	
	REP(i,N) REP(j,N){
		if(i == j) dist[i][j] = 0;
		else if(graph[i][j]) dist[i][j] = cost[j];
		else dist[i][j] = INF;
	}
	REP(k,N) REP(i,N) REP(j,N) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	
	REP(mask,(1<<F)) REP(i,N) dp[mask][i] = INF;
	for(mask=1;mask<(1<<F);mask++){
		REP(i,F) if(mask == (1<<i)) dp[mask][i] = cost[i];
		for(x=mask;x>0;x=(mask&(x-1))){
			y = mask - x;
			REP(i,N){
				int y2 = y;
				if(i < F) y2 |= (1<<i);
				dp[mask][i] = min(dp[mask][i],dp[x][i]+dp[y2][i]-cost[i]);
			}
		}
		REP(i,N) REP(j,N) dp[mask][i] = min(dp[mask][i],dp[mask][j]+dist[j][i]);
	}
	
	return dp[(1<<F)-1][0];
}

int main(void){
	int T,M,t,u,v,i,j,tmp;
	
	scanf("%d",&T);
	REP(t,T){
		scanf("%d%d%d",&N,&F,&M);
		REP(i,N) REP(j,N) graph[i][j] = false;
		REP(i,M){
			scanf("%d%d",&u,&v);
			graph[u][v] = graph[v][u] = true;
		}
		REP(i,N){
			scanf("%d",&tmp);
			cost[i] = (ll)tmp * 1000 + 1;
		}
		ll ans = func();
		cout << ans / 1000 << ' ' << ans % 1000 << endl;
	}
	
	return 0;
}
