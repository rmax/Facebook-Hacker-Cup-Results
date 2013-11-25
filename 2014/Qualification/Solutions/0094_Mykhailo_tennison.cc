#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

double dp[101][101][1001];
char was[101][101][1001];
int k,pu1,pu2,pd1,pd2;
double ps,pr,pw,pl;
int it;
double r(int p1, int p2, int prob)
{
	if (p1==k)
		return 1;
	if (p2==k)
		return 0;
	if (was[p1][p2][prob]==it)
		return dp[p1][p2][prob];
	was[p1][p2][prob]=it;
	double res=0;
	double p=prob/1000.0;
	//sunny
	res+=p*ps*pw*r(p1+1,p2,min(1000,prob+pu1));//win and increase
	res+=p*ps*(1-pw)*r(p1+1,p2,prob);//win and not increase
	res+=p*(1-ps)*pl*r(p1,p2+1,max(0,prob-pd1));//lose and decrease
	res+=p*(1-ps)*(1-pl)*r(p1,p2+1,prob);//lose and not decrease
	//rainy
	res+=(1-p)*pr*pw*r(p1+1,p2,min(1000,prob+pu1));//win and increase
	res+=(1-p)*pr*(1-pw)*r(p1+1,p2,prob);//win and not increase
	res+=(1-p)*(1-pr)*pl*r(p1,p2+1,max(0,prob-pd1));//lose and decrease
	res+=(1-p)*(1-pr)*(1-pl)*r(p1,p2+1,prob);//lose and not decrease
	return dp[p1][p2][prob]=res;
}
int main()
{
#ifdef Fcdkbear
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double beg=clock();
#else
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	for (it=1; it<=t; ++it)
	{
		scanf("%d",&k);
		scanf("%lf%lf",&ps,&pr);
		int pi1,pi2;
		scanf("%d.%d",&pi1,&pi2);
		pi1=1000*pi1+pi2;
		scanf("%d.%d",&pu1,&pu2);
		pu1=1000*pu1+pu2;
		scanf("%lf",&pw);
		scanf("%d.%d",&pd1,&pd2);
		pd1=1000*pd1+pd2;
		scanf("%lf",&pl);
		double res=r(0,0,pi1);
		printf("Case #%d: %.6lf\n",it,res);
	}

#ifdef Fcdkbear
	double end=clock();
	fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}