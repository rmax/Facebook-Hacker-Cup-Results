#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int k;
double ps, pr, pw, pl;
int pu_integer, pd_integer;

int nearestInt(double x)
{
	return (int) floor(x + 0.5);
}

double dp[102][102][1002];

double pwin(int iwin, int hewin, int psun_integer)
{
	if (iwin == k) {
// 		printf("reached winning with multiplier of %.6lf\n", multiplier);
		return 1.0;
	}
	if (hewin == k) return 0.0;
	
	double& d = dp[iwin][hewin][psun_integer];
	if (d != -1) return d;
	
	double psun = psun_integer / 1000.0;
	double result = 0;
	
	// win on sunny, and advance psun:
	result += pwin(iwin + 1, hewin, min(1000, psun_integer + pu_integer)) * ps * psun * pw;
	// win on sunny, don't advance psun:
	result += pwin(iwin + 1, hewin, psun_integer) * ps * psun * (1 - pw);
	// don't win on sunny, decrease psun:
	result += pwin(iwin, hewin + 1, max(0, psun_integer - pd_integer)) * (1 - ps) * psun * pl;
	// don't win on sunny, don't decrease psun:
	result += pwin(iwin, hewin + 1, psun_integer) * (1 - ps) * psun * (1 - pl);

	// win on rainy, and advance psun:
	result += pwin(iwin + 1, hewin, min(1000, psun_integer + pu_integer)) * pr * (1 - psun) * pw;
	// win on rainy, don't advance psun:
	result += pwin(iwin + 1, hewin, psun_integer) * pr * (1 - psun) * (1 - pw);
	// don't win on rainy, decrease psun:
	result += pwin(iwin, hewin + 1, max(0, psun_integer - pd_integer)) * (1 - pr) * (1 - psun) * pl;
	// don't win on rainy, don't decrease psun:
	result += pwin(iwin, hewin + 1, psun_integer) * (1 - pr) * (1 - psun) * (1 - pl);
	
	d = result;
	
	return result;
}

double solve(void)
{
	double pi, pd, pu;
	FOR(i, 102) FOR(j, 102) FOR(k, 1002) dp[i][j][k] = -1;
	scanf("%d%lf%lf%lf%lf%lf%lf%lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
	pd_integer = nearestInt(pd * 1000);
	pu_integer = nearestInt(pu * 1000);
	return pwin(0, 0, nearestInt(pi * 1000));
}


int main(void)
{
//  	freopen("/home/vesko/hackercup/c.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	FOR(tc, T) {
		printf("Case #%d: %.6lf\n", tc + 1, solve());
	}
	return 0;
}
