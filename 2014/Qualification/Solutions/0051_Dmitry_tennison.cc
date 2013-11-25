#pragma comment(linker, "/STACK:128777216")
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>
#include <cmath>
#include <math.h>
#include <queue>
#include <deque>
#include <cassert>
#include <time.h>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define zero(a) memset (a, 0, sizeof (a))
#define last(v) (int)v.size() - 1
#define _(a, val) memset (a, val, sizeof (a))
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifdef WIN32
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	if (s.length() != 0)
	{
		freopen ((s + ".in").c_str(), "r", stdin);
		freopen ((s + ".out").c_str(), "w", stdout);
	}
#endif
}

int k, ps, pr, pi, pu, pw, pd, pl;
ld dp[105][105][1005];

int go(double d)
{
	return (int)floor(d*1000 + 0.5);
}

void readdata ()
{
	double t_ps, t_pr, t_pi, t_pu, t_pw, t_pd, t_pl;
	scanf("%d %lf %lf %lf %lf %lf %lf %lf", &k, &t_ps, &t_pr, &t_pi, &t_pu, &t_pw, &t_pd, &t_pl);

	ps = go( t_ps );
	pr = go( t_pr );
	pi = go( t_pi );
	pu = go( t_pu );
	pw = go( t_pw );
	pd = go( t_pd );
	pl = go( t_pl );
}

void upd(int a, int b, int p)
{
	dp[a + 1][b][p] += dp[a][b][p] * p * ps * (1000 - pw) / 1e9;
	dp[a + 1][b][min(1000, p + pu)] += dp[a][b][p] * p * ps * pw / 1e9;
	dp[a + 1][b][p] += dp[a][b][p] * (1000 - p) * pr * (1000 - pw) / 1e9;
	dp[a + 1][b][min(1000, p + pu)] += dp[a][b][p] * (1000 - p) * pr * pw / 1e9;

	dp[a][b + 1][p] += dp[a][b][p] * p * (1000 - ps) * (1000 - pl) / 1e9;
	dp[a][b + 1][max(0, p - pd)] += dp[a][b][p] * p * (1000 - ps) * pl / 1e9;
	dp[a][b + 1][p] += dp[a][b][p] * (1000 - p) * (1000 - pr) * (1000 - pl) / 1e9;
	dp[a][b + 1][max(0, p - pd)] += dp[a][b][p] * (1000 - p) * (1000 - pr) * pl / 1e9;
}

void solve ()
{
	_(dp, 0);
	dp[0][0][pi] = 1.0;

	forn(i, k)
	{
		forn(j, k)
		{
			forn(t, 1001)
			{
				upd(i, j, t);
			}
		}
	}

	ld ans = 0.0;
	forn(i, k)
		forn(j, 1001)
			ans += dp[k][i][j];

	printf("%.6Lf\n", ans);
}

void writedata ()
{

}

int main ()
{
	prepare ("");
	
	int t;
	scanf("%d", &t);

	forn(i, t)
	{
		printf("Case #%d: ", i + 1);
		readdata ();
		solve ();
	}


	return 0;
}
