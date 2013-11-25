#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

double dp[201][1001];
double dp1[201][1001];

int main()
{
	int t,ii=0,n,i,j,k;

	double ps,pr,pi,pu,pw,pd,pl;

	//freopen("1.in","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>t;

	while(t--)
	{
		cin>>n>>ps>>pr>>pi>>pu>>pw>>pd>>pl;

		memset(dp,0,sizeof(dp));

		dp[0][(int)(pi*1000+0.2)]=1;

		double ans=0;

		double p=pi*ps+(1-pi)*pr;

		for(i=0;i<n+n;i++)
		{
			memset(dp1,0,sizeof(dp1));
			for(j=0;j<=i&&j<n;j++)if(i-j<n)
			{
				for(k=0;k<=1000;k++)
				{
					p=k*ps+(1000-k)*pr;
					p/=1000;

					dp1[j+1][k]+=dp[j][k]*p*(1-pw);
					dp1[j+1][min(k+(int)(pu*1000+0.2),1000)]+=dp[j][k]*p*pw;

					dp1[j][k]+=dp[j][k]*(1-p)*(1-pl);
					dp1[j][max(k-(int)(pd*1000+0.2),0)]+=dp[j][k]*(1-p)*pl;
				}
			}
			for(k=0;k<=1000;k++)
				ans+=dp[n][k];
			memcpy(dp,dp1,sizeof(dp));
		}
		printf("Case #%d: %.6lf\n",++ii,ans);
	}
}
