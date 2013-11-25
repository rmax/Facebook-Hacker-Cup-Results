#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define PI	(acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (123456789)
#define BIGBIG (987654321987654321LL)
#define SZ(a) ((int)((a).size()))
#define SQ(a) ((a)*(a))
typedef long long ll;
typedef unsigned long long ull;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE

int main()
{
	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;
		vector <string> field;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			field.push_back(s);

		}

		bool yes = false;

		for (int ly = 0; ly < N; ly++)
		{
			for (int lx = 0; lx < N; lx++)
			{
				for (int h = 1; h+ly <= N && h+lx<= N; h++)
				{
					int w = h;
					bool ok = true;

					for (int y = 0; y < N; y++)
					{
						for (int x = 0; x < N; x++)
						{
							if(INRANGE(y,ly,ly+h-1)&&INRANGE(x,lx,lx+w-1) && field[y][x]!='#')
							{
								ok = false;
							}
							if( !(INRANGE(y,ly,ly+h-1)&&INRANGE(x,lx,lx+w-1)) && field[y][x]=='#')
							{
								ok = false;
							}

						}
					}

					if(ok)
					{
						yes = true;
					}
				}
			}
		}

		printf("Case #%d: %s\n",testcase+1,yes?"YES":"NO");
	}

	return 0;
}
