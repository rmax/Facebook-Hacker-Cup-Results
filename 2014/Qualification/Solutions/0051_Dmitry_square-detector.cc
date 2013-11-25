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
#ifdef _DEBUG
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

const int NMAX = 25;

char a[NMAX][NMAX];
int n;

void readdata ()
{
	scanf("%d\n", &n);
	forn(i, n)
	{
		gets( a[i] );
	}
}

struct pos
{
	int r, c;
	pos() {}
	pos(int a, int b) { r = a; c = b; }
};

void solve ()
{
	pos l(INF, INF), r(INF, -INF);
	forn(i, n) forn(j, n)
	{
		if (a[i][j] == '#')
		{
			if (l.c > j)
			{
				l = pos(i, j);
			}
			else
				if (l.c == j)
					l.r = min(l.r, i);

			if (r.c < j)
			{
				r = pos(i, j);
			}
			else
				if (r.c == j)
					r.r = max(r.r, i);
		}
	}

	if (l.c <= r.c && l.r <= r.r && r.c - l.c == r.r - l.r)
	{
		forab(i, l.r, r.r) forab(j, l.c, r.c)
		{
			if (a[i][j] != '#')
			{
				puts("NO");
				return;
			}
		}
		puts("YES");
	}
	else
		puts("NO");

}

void writedata ()
{

}

int main ()
{
	prepare("");
	int t;
	scanf("%d", &t);
	forn(i, t)
	{
		printf("Case #%d: ", i + 1);
		readdata();
		solve();
	}
	
	return 0;
}
