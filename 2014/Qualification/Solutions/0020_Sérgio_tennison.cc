#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define dbg if(0)


double dp[110][110][1010];

int k,t;
double ps,pr,pi,pu,pw,pd,pl;



double go(int a, int b, int c){
	if(dp[a][b][c] > -0.5) return dp[a][b][c];
	dp[a][b][c] = 0.0;
	if(a == k) return dp[a][b][c] = 1.0;
	if(b == k) return dp[a][b][c] = 0.0;
	double pg = (c/1000.0) * ps + (1-c/1000.0) * pr;
	dp[a][b][c] = go(a+1,b,c) * pg * (1-pw) + go(a+1,b,min(1000,int(c+pu*1000+1e-4))) * pg * pw + go(a,b+1,c) * (1-pg) * (1-pl) + go(a,b+1,max(0,int(c-pd*1000+1e-4))) * (1-pg) * pl;
	return dp[a][b][c];
}






int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d %lf %lf %lf %lf %lf %lf %lf",&k,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		fr(i,0,k+1) fr(j,0,k+1) fr(l,0,1001) dp[i][j][l] = -1.0;
		printf("Case #%d: %.6lf\n",cas,go(0,0,pi*1000+1e-4));
	}
	return 0;
}










































