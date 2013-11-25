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

struct player
{
	string name;
	int shot;
	int height;
	int play;
};

bool cf(player a,player b)
{
	if (a.shot != b.shot) return a.shot > b.shot;
	return a.height > b.height;
}

player data[40];
char s[100];
int playing[40];

int main()
{
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc)
	{
		RESET(playing,0);
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		FOR(a,1,n)
		{
			int i,j;
			scanf("%s %d %d",s,&i,&j);
			data[a].name = s;
			data[a].shot = i;
			data[a].height = j;
			data[a].play = 0;
		}

		
		sort(data+1,data+n+1,cf);
		FOR(a,1,p)
		{
			playing[2*a-1] = 1;
			data[2*a-1].play++;
			playing[2*a] = 1;
			data[2*a].play++; 
		}
		if (1)
		{
			FOR(a,1,m)
			{
				pii leave1 = mp(-1,0);
				pii leave2 = mp(-1,0);
				pii in1 = mp(INF,0);
				pii in2 = mp(INF,0);
				FOR(b,1,n)
				{
					if (b%2==1)
					{
						if (playing[b]) MAX(leave1,mp(data[b].play,b));
						else MIN(in1,mp(data[b].play,b));
					}
					else
					{
						if (playing[b]) MAX(leave2,mp(data[b].play,b));
						else MIN(in2,mp(data[b].play,b));
					}
				}
				if (in1.se)
				{
					playing[leave1.se] = 0;
					playing[in1.se] = 1;
				}
				if (in2.se)
				{
					playing[leave2.se] = 0;
					playing[in2.se] = 1;
				}
				FOR(b,1,n)
				{
					if (playing[b]) data[b].play++;
				}
			}
			
		}
		vector<string> ans;
		FOR(a,1,n)
		{
			if (playing[a]) ans.pb(data[a].name);
		}
		sort(ans.begin(),ans.end());
		printf("Case #%d: ",T);
		FOR(a,0,SIZE(ans)-1)
		{
			printf("%s",ans[a].c_str());
			if (a != SIZE(ans)-1) printf(" ");
		}
		puts("");
	}
}
