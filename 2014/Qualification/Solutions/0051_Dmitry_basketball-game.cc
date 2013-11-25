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

struct person
{
	string name;
	int h, acc;
};

const int NMAX = 55;

person a[NMAX];
int n, m, p;
char temp[NMAX];

void readdata ()
{
	scanf("%d %d %d\n", &n, &m, &p);
	forn(i, n)
	{
		scanf("%s %d %d\n", temp, &a[i].acc, &a[i].h);
		a[i].name = temp;
	}
}

bool cmp(const person &a, const person &b)
{
	if (a.acc == b.acc)
		return a.h > b.h;
	return a.acc > b.acc;
}

void solve ()
{
	sort(a, a + n, cmp);

	queue<person> q1, q2, z1, z2;
	forn(i, n)
		if (i & 1)
			z1.push( a[i] );
		else
			z2.push( a[i] );

	vector<person> v1, v2;
	forn(i, p)
	{
		v1.pb( z1.front() );
		z1.pop();
		v2.pb( z2.front() );
		z2.pop();
	}

	reverse( all(v1) );
	reverse( all(v2) );

	forn(i, p)
		q1.push( v1[i] ), q2.push( v2[i] );

	forn(i, m)
	{
		z1.push( q1.front() );
		q1.pop();
		q1.push( z1.front() );
		z1.pop();


		z2.push( q2.front() );
		q2.pop();
		q2.push( z2.front() );
		z2.pop();
	}

	vector<string> ans;
	forn(i, p)
	{
		ans.pb ( q1.front().name );
		q1.pop();
		ans.pb ( q2.front().name );
		q2.pop();
	}

	sort(all(ans));
	forn(i, ans.size())
		printf(" %s", ans[i].c_str());
	printf("\n");
}

int main ()
{
	prepare ("");
	
	int t;
	scanf("%d", &t);

	forn(i, t)
	{
		printf("Case #%d:", i + 1);
		readdata ();
		solve ();
	}

	return 0;
}
