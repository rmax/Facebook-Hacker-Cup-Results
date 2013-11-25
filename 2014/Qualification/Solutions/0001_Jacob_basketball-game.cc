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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,tt,N,M,K,S;
	int i,j,m,m2;
	pair <PR,string> P[30];
	int tim[30];
	vector <int> t[2],b[2];
	vector <string> ans;
	Read(T);
		Fox1(tt,T)
		{
			printf("Case #%d:",tt);
			Read(N),Read(M),Read(K);
				Fox(i,N)
				{
					cin >> P[i].y;
					Read(P[i].x.x),Read(P[i].x.y);
				}
			sort(P,P+N);
			reverse(P,P+N);
			t[0].clear();
			t[1].clear();
			b[0].clear();
			b[1].clear();
				Fox(i,N)
				{
					j=i%2;
						if (Sz(t[j])<K)
							t[j].pb(i);
						else
							b[j].pb(i);
				}
			Fill(tim,0);
				while (M--)
					Fox(i,2)
					{
							Fox(j,Sz(t[i]))
								tim[t[i][j]]++;
						m=0;
							Fox(j,Sz(t[i]))
								if ((tim[t[i][j]]>tim[t[i][m]]) || (tim[t[i][j]]==tim[t[i][m]]) && (t[i][j]>t[i][m]))
									m=j;
						b[i].pb(t[i][m]);
						t[i].erase(t[i].begin()+m);
						m2=0;
							Fox(j,Sz(b[i]))
								if ((tim[b[i][j]]<tim[b[i][m2]]) || (tim[b[i][j]]==tim[b[i][m2]]) && (b[i][j]<b[i][m2]))
									m2=j;
						t[i].pb(b[i][m2]);
						b[i].erase(b[i].begin()+m2);
					}
			ans.clear();
				Fox(i,K)
					Fox(j,2)
						ans.pb(P[t[j][i]].y);
			sort(All(ans));
				Fox(i,Sz(ans))
					cout << " " << ans[i];
			printf("\n");
		}
	return(0);
}