#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, k;
i64 a[2048];
i64 m;
i64 x[4024000];
i64 s[10240];
i64 b[2048];
int c[2048];
int t[2048];

void tadd(int x)
{
	for(x++; x <= n; x += x & -x)
	{
		t[x]++;
	}
}

int tsum(int x)
{
	int ans = 0;
	for(x++; x; x -= x & -x)
	{
		ans += t[x];
	}
	return ans;
}

bool win()
{
	int cnt = 0;
	clr(t);
	s[0] = a[0];
	For(i, 1, n-1)
	{
		s[i] = s[i-1] + a[i];
	}

	forn(i, n)
	{
		b[i] = s[i];
	}
	sort(b, b+n);
	forn(i, n)
	{
		c[i] = lower_bound(b, b+n, s[i]) - b;
	}

	forn(i, n-1)
	{
		cnt += tsum(c[i] - 1);
		tadd(c[i]);
	}

	return cnt & 1;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	time_t et_0 = clock();
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int qq;
	scanf("%d", &qq);
	int tn = 0;
	while (qq--)
	{
		cerr << "tn = " << ++tn << endl;
		scanf("%d%d", &n, &k);
		k--;
		forn(i, n)
		{
			scanf("%I64d", &a[i]);
		}
		m = a[k];
		i64 ans = 0;
//		cerr << "m = " << m << endl;
		a[k] = -m;

		int cnt = 0;
		clr(t);
		s[0] = a[0];
		For(i, 1, n-1)
		{
			s[i] = s[i-1] + a[i];
		}
		forn(i, n)
		{
			b[i] = s[i];
		}
		sort(b, b+n);
		forn(i, n)
		{
			c[i] = lower_bound(b, b+n, s[i]) - b;
		}
	    
		forn(i, n-1)
		{
			cnt += tsum(c[i] - 1);
			tadd(c[i]);
		}

/*		clr(t);

		s[0] = a[k];
		For(i, 1, n-k-1)
		{
			s[i] = s[i-1] + a[k+i];
		}
		forn(i, n-k)
		{
			b[i] = s[i];
		}
		sort(b, b+n-k);
		forn(i, n-k)
		{
			c[i] = lower_bound(b, b+n-k, s[i]) - b;
		}
	    
		forn(i, n-k-1)
		{
			cnt += tsum(c[i] - 1);
			tadd(c[i]);
		}
*/
		cnt &= 1;

		int r = 0;
		x[r++] = m;
		forn(i, k)
		{
			For(j, k, n-2)
			{
				x[r++] = s[i] - s[j] - m;
			}
		}
		sort(x, x+r);

		int l = 0;
		while (x[l] < -m) l++;
		while (x[r-1] > m) r--;
		if (x[l] > -m)
		{
			if (cnt & 1)
			{
				ans += x[l] - (-m) + 1;
//				cerr << -m << ".." << x[l] << "  ";
			}
		}

//		cerr << ans << endl;
		while (l + 1 < r)
		{
			cnt ^= 1;
			if (cnt & 1)
			{
				ans += x[l + 1] - x[l];
//				cerr << x[l] + 1 << ".." << x[l + 1] << "  ";
			}
			l++;
		}
//		cerr << endl;

/*		For(i, -m, m)
		{
			a[k] = i;
			if (win())
			{
				ans++;
			}
		}*/
/*
		forn(i, t)
		{
			a[k] = x[i];
			if (win())
			{
				cerr << a[k] << " ";
				ans++;
			}
		}
		cerr << endl;

		forn(i, t-1)
		{
			i64 zz = x[i+1] - x[i] - 1;
			if (zz > 0)
			{
				a[k] = x[i] + 1;
				if (win())
				{
					cerr << x[i] + 1 << "-" << x[i+1] - 1 << "  ";
					ans += zz;
				}
			}
		}
		cerr << endl;
*/
		printf("%I64d\n", ans);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}
