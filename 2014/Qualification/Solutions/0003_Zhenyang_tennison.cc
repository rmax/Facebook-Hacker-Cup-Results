#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
double dp[211][111][1111];
int d;
int p[9];
int get(string s)
{
	if (s[0]=='1')return 1000;
	s=s.substr(2);
	return atoi(s.c_str());
}
int main()
{
	//freopen("C:\\competition\\fbhc\\c.out","w",stdout);
	int i,j,k,cas,cc=0;
	cin>>cas;
	while (cas--)
	{
		cin>>d;
		string s[8];
		for (i=0;i<7;i++)
		{
			cin>>s[i];
			p[i]=get(s[i]);
		}
		double p1=p[0]/1000.0;//prob of win in sun
		double p2=p[1]/1000.0;//prob of win in rain
		double p3=p[4]/1000.0;//prob of prob inc when win
		double p4=p[6]/1000.0;//prob of prob dec when lose
		clr(dp);
		//puts("--");
		dp[0][0][p[2]]=1.0;
		for (i=0;i<=2*d;i++)
		{
			//printf("%d\n",i);
			for (j=0;j<d;j++)
			{
				for (k=0;k<=1000;k++)
				{
					double ps=k/1000.0;//prob of sun
					double pr=1.0-ps;//prob of rain
					double win=p1*ps+p2*pr;
					double lose=1-win;
					//win
					dp[i+1][j+1][k]+=dp[i][j][k]*win*(1-p3);
					dp[i+1][j+1][min(1000,k+p[3])]+=dp[i][j][k]*win*p3;
					//lose
					dp[i+1][j][k]+=dp[i][j][k]*lose*(1-p4);
					dp[i+1][j][max(0,k-p[5])]+=dp[i][j][k]*lose*p4;
				}
			}
		}
		double ans=0;
		for (i=d;i<=2*d-1;i++)
		{
			for (j=0;j<=1000;j++)ans+=dp[i][d][j];
		}
		printf("Case #%d: %f\n",++cc,ans);			
	}
	return 0;
}
			
		
	
