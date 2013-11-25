#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;
 
#define LL long long
#define LD long double
#define PR pair<int,int>
 
#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=n-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second
 
template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }
 
const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);
 
#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif
 
bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if (c<0)
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

int K;
LD Ps,Pr,Pi,Pu,Pw,Pd,Pl;
LD dyn[101][101][1001];
int vis[101][101][1001];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int i,j,p,p2;
	LD ans,d,d2;
	queue <pair<PR,int> > Q;
	Read(T);
		Fox1(t,T)
		{
			Read(K);
			scanf("%Lf%lf%Lf%Lf%Lf%Lf%Lf",&Ps,&Pr,&Pi,&Pu,&Pw,&Pd,&Pl);
			i=Pi*1000+0.5;
			Q.push(mp(mp(0,0),i)),dyn[0][0][i]=1,vis[0][0][i]=t;
			ans=0;
				while (!Q.empty())
				{
					i=Q.front().x.x;
					j=Q.front().x.y;
					p=Q.front().y;
					Q.pop();
					d=dyn[i][j][p];
						if (i==K)
						{
							ans+=d;
							continue;
						}
						if (j==K)
							continue;
					//win and moar sun
					p2=min(1000,p+int(Pu*1000+0.5));
					d2=d*((LD)p/1000*Ps + (LD)(1000-p)/1000*Pr) * Pw;
						if (vis[i+1][j][p2]!=t)
							Q.push(mp(mp(i+1,j),p2)),vis[i+1][j][p2]=t,dyn[i+1][j][p2]=0;
					dyn[i+1][j][p2]+=d2;
					//win and same sun
					p2=p;
					d2=d*((LD)p/1000*Ps + (LD)(1000-p)/1000*Pr) * (1-Pw);
						if (vis[i+1][j][p2]!=t)
							Q.push(mp(mp(i+1,j),p2)),vis[i+1][j][p2]=t,dyn[i+1][j][p2]=0;
					dyn[i+1][j][p2]+=d2;
					//lose and less sun
					p2=max(0,p-int(Pd*1000+0.5));
					d2=d*(1-((LD)p/1000*Ps + (LD)(1000-p)/1000*Pr)) * Pl;
						if (vis[i][j+1][p2]!=t)
							Q.push(mp(mp(i,j+1),p2)),vis[i][j+1][p2]=t,dyn[i][j+1][p2]=0;
					dyn[i][j+1][p2]+=d2;
					//lose and same sun
					p2=p;
					d2=d*(1-((LD)p/1000*Ps + (LD)(1000-p)/1000*Pr)) * (1-Pl);
						if (vis[i][j+1][p2]!=t)
							Q.push(mp(mp(i,j+1),p2)),vis[i][j+1][p2]=t,dyn[i][j+1][p2]=0;
					dyn[i][j+1][p2]+=d2;
				}
			printf("Case #%d: %.6Lf\n",t,ans);
		}
	return(0);
}