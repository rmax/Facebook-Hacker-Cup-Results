#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double dp[205][1010][205];
int p[10];
int main()
{
	int n,t,x,y;char c;cin>>t;
	rep(i,t){
		cin>>n;n=n*2-1;
		rep(j,7){
			cin>>x>>c>>y;p[j]=1000*x+y;
		}
		rep(j,n+2) rep(k,1001) rep(l,j+2) dp[j][k][l]=0.0;dp[0][p[2]][0]=1.0;
		rep(j,n) rep(k,1001) rep(l,j+1){
			//if(dp[j][k][l]<1e-100) continue;
			double win=1e-6*(k*p[0]+(1000-k)*p[1]),lose=1-win;
			dp[j+1][min(k+p[3],1000)][l+1]+=dp[j][k][l]*win*0.001*p[4];
			dp[j+1][k][l+1]+=dp[j][k][l]*win*0.001*(1000-p[4]);
			dp[j+1][max(k-p[5],0)][l]+=dp[j][k][l]*lose*0.001*p[6];
			dp[j+1][k][l]+=dp[j][k][l]*lose*0.001*(1000-p[6]);
		}
		double ret=0.0;rep(j,1001) REP(k,n/2+1,n+1) ret+=dp[n][j][k];
		printf("Case #%d: %.6f\n",i+1,ret);
	}
}
