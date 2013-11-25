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
struct player 
{
	string name;
	int sp,h;
	int d;
	int tot;
	void input()
	{
		cin>>name>>sp>>h;
		tot=0;
	}
	bool operator<(const player&gg)const 
	{
		if (sp==gg.sp)return h>gg.h;
		return sp>gg.sp;
	}
}a[1111];
int n,m,p;
int main()
{
	//freopen("C:\\competition\\fbhc\\b.out","w",stdout);
	int i,j,k,cas,cc=0;
	cin>>cas;
	while (cas--)
	{
		cin>>n>>m>>p;
		for (i=0;i<n;i++)a[i].input();
		sort(a,a+n);
		for (i=0;i<n;i++)a[i].d=i;
		vector<player>t1,t2;
		for (i=0;i<n;i++)
		{
			if (i%2==0)t1.pb(a[i]);
			else t2.pb(a[i]);
		}
		//reverse(all(t1));
		//reverse(all(t2));
		vector<player>c1,c2;
		for (i=0;i<p;i++)
		{
			c1.pb(t1[i]);
			c2.pb(t2[i]);
		}
		for (i=0;i<p;i++)
		{
			t1.erase(t1.begin());
			t2.erase(t2.begin());
		}
		while (m--)
		{
			//puts("--");
			for (i=0;i<sz(c1);i++)
			{
				c1[i].tot++;
			}
			for (i=0;i<sz(c2);i++)
			{
				c2[i].tot++;
			}
			if (t1.empty())continue;
			player f;
			f.tot=-1;
			f.d=-1;
			for (i=0;i<sz(c1);i++)
			{
				if (c1[i].tot>f.tot||c1[i].tot==f.tot&&c1[i].d>f.d)f=c1[i];
			}
			player g;
			g.tot=1111111;
			g.d=1111111;
			for (i=0;i<sz(t1);i++)
			{
				if (t1[i].tot<g.tot||t1[i].tot==g.tot&&t1[i].d<g.d)g=t1[i];
			}
			for (i=0;i<sz(c1);i++)
			{
				if (c1[i].d==f.d)
				{
					swap(c1[i],c1[c1.size()-1]);
					c1.pop_back();
					c1.pb(g);
					break;
				}
			}
			for (i=0;i<sz(t1);i++)
			{
				if (t1[i].d==g.d)
				{
					swap(t1[i],t1[t1.size()-1]);
					t1.pop_back();
					t1.pb(f);
					break;
				}
			}
			if (t2.empty())continue;
			f.tot=-1;
			f.d=-1;
			for (i=0;i<sz(c2);i++)
			{
				if (c2[i].tot>f.tot||c2[i].tot==f.tot&&c2[i].d>f.d)f=c2[i];
			}
			g.tot=1111111;
			g.d=1111111;
			for (i=0;i<sz(t2);i++)
			{
				if (t2[i].tot<g.tot||t2[i].tot==g.tot&&t2[i].d<g.d)g=t2[i];
			}
			for (i=0;i<sz(c2);i++)
			{
				if (c2[i].d==f.d)
				{
					swap(c2[i],c2[c2.size()-1]);
					c2.pop_back();
					c2.pb(g);
					break;
				}
			}
			for (i=0;i<sz(t2);i++)
			{
				if (t2[i].d==g.d)
				{
					swap(t2[i],t2[t2.size()-1]);
					t2.pop_back();
					t2.pb(f);
					break;
				}
			}	
		}
		vector<player>o;
		foreach(e,c1)o.pb(*e);
		foreach(e,c2)o.pb(*e);
		vs s;
		foreach(e,o)s.pb(e->name);
		sort(all(s));
		printf("Case #%d:",++cc);
		foreach(e,s)cout<<" "<<*e;
		cout<<endl;		
	}
	return 0;
}
/*
69 
29
2
0
*/			
		
	
