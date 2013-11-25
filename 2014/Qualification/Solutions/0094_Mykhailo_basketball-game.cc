#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

string name[40];
int per[40];
int h[40];
vector<pair<pnt,int> > a;

int team[40];
int play[40];
int ti[40];
int ra[40];
int n;

vector<string> res;


inline int fromTeam(int te)
{
	int who=-1;
	FOR(i,0,n)
		if ((team[i]==te) && (play[i]==1))
		{
			if ((who==-1) || (ti[i]>ti[who]) || ((ti[i]==ti[who]) && (ra[i]>ra[who])))
				who=i;
		}
	return who;
}

int toTeam(int te)
{
	int who=-1;
	FOR(i,0,n)
		if ((team[i]==te) && (play[i]==0))
		{
			if ((who==-1) || (ti[i]<ti[who]) || ((ti[i]==ti[who]) && (ra[i]<ra[who])))
				who=i;
		}
	return who;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double beg=clock();
#else
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		int m,p;
		scanf("%d%d%d",&n,&m,&p);
		a.clear();
		FOR(i,0,n)
		{
			cin>>name[i]>>per[i]>>h[i];
			a.push_back(mp(mp(-per[i],-h[i]),i));
		}
		sort(a.begin(),a.end());
		MEMS(team,0);
		MEMS(play,0);
		FOR(i,0,n)
		{
			if (i&1)
				team[a[i].second]=2;
			else
				team[a[i].second]=1;
			if (i<2*p)
				play[a[i].second]=1;
			else
				play[a[i].second]=0;
			ra[a[i].second]=i;
		}
		MEMS(ti,0);
		if (p+p!=n)
		{
			FOR(itt,0,m)
			{
				FOR(i,0,n)
					if (play[i])
						ti[i]++;
				int fr1=fromTeam(1);
				int fr2=fromTeam(2);
				int to1=toTeam(1);
				int to2=toTeam(2);
				play[fr1]=0;
				play[fr2]=0;
				play[to1]=1;
				play[to2]=1;
			}
		}
		res.clear();
		FOR(i,0,n)
			if (play[i])
				res.push_back(name[i]);
		sort(res.begin(),res.end());
		printf("Case #%d:",it);
		FOR(i,0,res.size())
			printf(" %s",res[i].c_str());
		printf("\n");
	}

#ifdef Fcdkbear
	double end=clock();
	fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}
