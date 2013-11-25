#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)

using namespace std;

double dp[105][105][1005]; //tennison,enemy,pi = prob win

void reset()
{
	memset(dp,-1,sizeof(dp));
}

int t,k;
double ps,pr,pi,pu,pw,pd,pl;
double total;

void print_dp()
{
	printf("\ndp:\n");
	for (int i=0;i<=k;i++)
	{
		for (int j=0;j<=k;j++) printf("%10f ",dp[i][j]);
		printf("\n");
	}
}

double getDp(int win,int lose,int sunny)
{
//	printf("call getDp(%d,%d,%d)\n",win,lose,sunny);
	
	if (win<0 || lose<0 || sunny<0 || sunny>1000) return 0;
	if (win==0) return 1;
	if (lose==0) return 0;
	
	if (dp[win][lose][sunny]==dp[win][lose][sunny]) return dp[win][lose][sunny];
	
	dp[win][lose][sunny] = getDp(win-1,lose,min(1000,sunny+(int)pu))*ps*(sunny/1000.0)*pw
						 + getDp(win-1,lose,sunny)*ps*(sunny/1000.0)*(1-pw)
						 + getDp(win-1,lose,min(1000,sunny+(int)pu))*pr*((1000-sunny)/1000.0)*pw
						 + getDp(win-1,lose,sunny)*pr*((1000-sunny)/1000.0)*(1-pw)
						 + getDp(win,lose-1,max(0,sunny-(int)pd))*(1-ps)*(sunny/1000.0)*pl
						 + getDp(win,lose-1,sunny)*(1-ps)*(sunny/1000.0)*(1-pl)
						 + getDp(win,lose-1,max(0,sunny-(int)pd))*(1-pr)*((1000-sunny)/1000.0)*pl
						 + getDp(win,lose-1,sunny)*(1-pr)*((1000-sunny)/1000.0)*(1-pl);
	
	/*dp[win][lose][sunny] = dp[win-1][lose][max(0,sunny-pu)]*ps*(sunny/1000.0)*pw
						 + dp[win-1][lose][sunny]*ps*(sunny/1000.0)*(1-pw)
						 + dp[win-1][lose][max(0,sunny-pu)]*pr*((1000-sunny)/1000.0)*pw
						 + dp[win-1][lose][sunny]*pr*((1000-sunny)/1000.0)*(1-pw)
						 + dp[win][lose-1][min(1000,sunny+pd)]*(1-ps)*(sunny/1000.0)*pl
						 + dp[win][lose-1][sunny]*(1-ps)*(sunny/1000.0)*(1-pl)
						 + dp[win][lose-1][min(1000,sunny+pd)]*(1-pr)*((1000-sunny)/1000.0)*pl
						 + dp[win][lose-1][sunny]*(1-ps)*((1000-sunny)/1000.0)*(1-pl);*/
	return dp[win][lose][sunny];
}

int main()
{
	freopen("tennison.txt","r",stdin);
	freopen("tennison_out.txt","w",stdout);
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		reset();
		
		scanf("%d %lf %lf %lf %lf %lf %lf %lf",&k,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		
		pi*=1000;
		pu*=1000;
		pd*=1000;
		
		dp[0][0][(int)pi] = 1;
		
		getDp(k,k,(int)pi);
		
		printf("Case #%d: %.6f\n",tc,dp[k][k][(int)pi]);
		
	}
	
 	return 0;
}

