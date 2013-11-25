#pragma comment (linker, "/STACK:268435456")
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <functional>
#include <complex>
#include <numeric>
#include <utility>
#include <cstdlib>

using namespace std;

double ps, pr, pw, pl;
int k, pi, pu, pd;
double dp[210][110][1010];

double solve()
{
	double result = 0;
	for (int i = 0; i <= k * 2 - 1; i++)
		for (int w = 0; w <= k * 2 - 1; w++)
			for (int j = 0; j <= 1000; j++)
				dp[i][w][j] = 0;
	dp[0][0][pi] = 1;
	for (int i = 0; i <= k * 2 - 1; i++)
		for (int w = 0; w <= i && w <= k; w++)
		{
			int l = i - w;
			if (l <= k)
				for (int j = 0; j <= 1000; j++)
				{
					if (w == k)
					{
						result += dp[i][w][j];
						continue;
					}
					if (l == k)
						continue;
					double pwin = ps * j * 0.001 + pr * (1000 - j) * 0.001; 
					dp[i + 1][w + 1][min(1000, j + pu)] += dp[i][w][j] * pwin * pw;
					dp[i + 1][w + 1][j]                 += dp[i][w][j] * pwin * (1 - pw);
					dp[i + 1][w][max(0, j - pd)]        += dp[i][w][j] * (1 - pwin) * pl;
					dp[i + 1][w][j]                     += dp[i][w][j] * (1 - pwin) * (1 - pl);
				}
		}
	return result;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	double _pi, _pu, _pd;
    	cin >> k >> ps >> pr >> _pi >> _pu >> pw >> _pd >> pl;
    	pi = int(_pi * 1000 + 0.5);
    	pu = int(_pu * 1000 + 0.5);
    	pd = int(_pd * 1000 + 0.5);
    	printf("Case #%d: %0.6lf\n", tc + 1, solve());
    }
    return 0;
}
