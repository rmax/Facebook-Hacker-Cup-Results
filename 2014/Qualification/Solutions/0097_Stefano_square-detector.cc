#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
//zlb//

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
int MOD    = 1000000007;
int MAXINT = 2147483647;
LL INFLL   = 1000000000000000000LL;
LL MAXLL   = 9223372036854775807LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back
#define SIZE(a)       (int)a.size()
#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))
#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)
#define RESET(a, b)   memset(a,b,sizeof(a))
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ------------ //

char s[25][25];

int main()
{
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc)
	{
		int n;
		scanf("%d",&n);
		FOR(a,0,n-1)
		{
			scanf("%s",s[a]);
		}
		int tlx=-1,tly=-1;
		int brx=-1,bry=-1;
		FOR(a,0,n-1)
		{
			FOR(b,0,n-1)
			{
				if (s[a][b] == '#')
				{
					tlx = a;
					tly = b;
					break;
				}
			}
			if (tlx != -1) break;
		}
		FORD(a,n-1,0)
		{
			FORD(b,n-1,0)
			{
				if (s[a][b] == '#')
				{
					brx = a;
					bry = b;
					break;
				}
			}
			if (brx != -1) break;
		}
		printf("Case #%d: ",T);
		if (tlx <= brx && tly <= bry && brx-tlx == bry-tly)
		{
			bool fail = 0;
			FOR(a,tlx,brx)
			{
				FOR(b,tly,bry)
				{
					if (s[a][b] == '.') fail = 1;
				}
			}
			if (!fail) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
}
