#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
char s[33][33];
bool vis[33][33];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int ar=0,n;
pii mx,mi;
void dfs(int x,int y)
{
	vis[x][y]=1;
	int i;
	++ar;
	mx=max(mx,mp(x,y));
	mi=min(mi,mp(x,y));
	for (i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (xx>=0&&yy>=0&&xx<n&&yy<n&&!vis[xx][yy]&&s[xx][yy]=='#')dfs(xx,yy);
	}
}
int main()
{
	freopen("C:\\competition\\fbhc\\a.out","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)scanf("%s",s[i]);
		clr(vis);
		int cnt=0,o=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)if (!vis[i][j]&&s[i][j]=='#')
			{
				ar=0;
				mx=mp(-1,-1);
				mi=mp(111,111);
				dfs(i,j);
				++cnt;
				mx.fi-=mi.fi;
				mx.se-=mi.se;
				mx.fi++;mx.se++;
				if (mx.fi==mx.se&&ar==mx.fi*mx.se)o=1;
			}
		}
		printf("Case #%d: ",++cc);
		if (cnt>1||cnt==0)
		{
			puts("NO");
			continue;
		}
		puts(o?"YES":"NO");
	}
	return 0;
}
			
		
	